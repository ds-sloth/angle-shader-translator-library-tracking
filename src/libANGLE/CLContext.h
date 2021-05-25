//
// Copyright 2021 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// CLContext.h: Defines the cl::Context class, which manages OpenCL objects such as command-queues,
// memory, program and kernel objects and for executing kernels on one or more devices.

#ifndef LIBANGLE_CLCONTEXT_H_
#define LIBANGLE_CLCONTEXT_H_

#include "libANGLE/CLCommandQueue.h"
#include "libANGLE/CLDevice.h"
#include "libANGLE/CLMemory.h"
#include "libANGLE/CLProgram.h"
#include "libANGLE/CLSampler.h"
#include "libANGLE/renderer/CLContextImpl.h"

namespace cl
{

class Context final : public _cl_context, public Object
{
  public:
    using PtrList   = std::list<ContextPtr>;
    using PropArray = std::vector<cl_context_properties>;

    ~Context() override;

    const Platform &getPlatform() const noexcept;
    bool hasDevice(const _cl_device_id *device) const;
    const DeviceRefList &getDevices() const;

    bool supportsImages() const;
    bool supportsIL() const;
    bool supportsBuiltInKernel(const std::string &name) const;

    bool hasCommandQueue(const _cl_command_queue *commandQueue) const;
    bool hasMemory(const _cl_mem *memory) const;
    bool hasSampler(const _cl_sampler *sampler) const;
    bool hasProgram(const _cl_program *program) const;

    void retain() noexcept;
    bool release();

    cl_int getInfo(ContextInfo name, size_t valueSize, void *value, size_t *valueSizeRet) const;

    cl_command_queue createCommandQueue(cl_device_id device,
                                        CommandQueueProperties properties,
                                        cl_int &errorCode);

    cl_command_queue createCommandQueueWithProperties(cl_device_id device,
                                                      const cl_queue_properties *properties,
                                                      cl_int &errorCode);

    cl_mem createBuffer(const cl_mem_properties *properties,
                        MemFlags flags,
                        size_t size,
                        void *hostPtr,
                        cl_int &errorCode);

    cl_mem createImage(const cl_mem_properties *properties,
                       MemFlags flags,
                       const cl_image_format *format,
                       const cl_image_desc *desc,
                       void *hostPtr,
                       cl_int &errorCode);

    cl_mem createImage2D(MemFlags flags,
                         const cl_image_format *format,
                         size_t width,
                         size_t height,
                         size_t rowPitch,
                         void *hostPtr,
                         cl_int &errorCode);

    cl_mem createImage3D(MemFlags flags,
                         const cl_image_format *format,
                         size_t width,
                         size_t height,
                         size_t depth,
                         size_t rowPitch,
                         size_t slicePitch,
                         void *hostPtr,
                         cl_int &errorCode);

    cl_sampler createSampler(cl_bool normalizedCoords,
                             AddressingMode addressingMode,
                             FilterMode filterMode,
                             cl_int &errorCode);

    cl_sampler createSamplerWithProperties(const cl_sampler_properties *properties,
                                           cl_int &errorCode);

    cl_program createProgramWithSource(cl_uint count,
                                       const char **strings,
                                       const size_t *lengths,
                                       cl_int &errorCode);

    cl_program createProgramWithIL(const void *il, size_t length, cl_int &errorCode);

    cl_program createProgramWithBinary(cl_uint numDevices,
                                       const cl_device_id *devices,
                                       const size_t *lengths,
                                       const unsigned char **binaries,
                                       cl_int *binaryStatus,
                                       cl_int &errorCode);

    cl_program createProgramWithBuiltInKernels(cl_uint numDevices,
                                               const cl_device_id *devices,
                                               const char *kernelNames,
                                               cl_int &errorCode);

    static bool IsValid(const _cl_context *context);
    static bool IsValidAndVersionOrNewer(const _cl_context *context, cl_uint major, cl_uint minor);

    static void CL_CALLBACK ErrorCallback(const char *errinfo,
                                          const void *privateInfo,
                                          size_t cb,
                                          void *userData);

  private:
    Context(Platform &platform,
            PropArray &&properties,
            DeviceRefList &&devices,
            ContextErrorCB notify,
            void *userData,
            bool userSync,
            cl_int &errorCode);

    Context(Platform &platform,
            PropArray &&properties,
            DeviceType deviceType,
            ContextErrorCB notify,
            void *userData,
            bool userSync,
            cl_int &errorCode);

    cl_command_queue createCommandQueue(CommandQueue *commandQueue);
    cl_mem createMemory(Memory *memory);
    cl_sampler createSampler(Sampler *sampler);
    cl_program createProgram(Program *program);

    void destroyCommandQueue(CommandQueue *commandQueue);
    void destroyMemory(Memory *memory);
    void destroySampler(Sampler *sampler);
    void destroyProgram(Program *program);

    Platform &mPlatform;
    const PropArray mProperties;
    const ContextErrorCB mNotify;
    void *const mUserData;
    const rx::CLContextImpl::Ptr mImpl;
    const DeviceRefList mDevices;

    CommandQueue::PtrList mCommandQueues;
    Memory::PtrList mMemories;
    Sampler::PtrList mSamplers;
    Program::PtrList mPrograms;

    friend class Buffer;
    friend class CommandQueue;
    friend class Memory;
    friend class Platform;
    friend class Program;
    friend class Sampler;
};

inline const Platform &Context::getPlatform() const noexcept
{
    return mPlatform;
}

inline bool Context::hasDevice(const _cl_device_id *device) const
{
    return std::find_if(mDevices.cbegin(), mDevices.cend(), [=](const DeviceRefPtr &ptr) {
               return ptr.get() == device;
           }) != mDevices.cend();
}

inline const DeviceRefList &Context::getDevices() const
{
    return mDevices;
}

inline bool Context::supportsImages() const
{
    return (std::find_if(mDevices.cbegin(), mDevices.cend(), [](const DeviceRefPtr &ptr) {
                return ptr->getInfo().mImageSupport == CL_TRUE;
            }) != mDevices.cend());
}

inline bool Context::supportsIL() const
{
    return (std::find_if(mDevices.cbegin(), mDevices.cend(), [](const DeviceRefPtr &ptr) {
                return !ptr->getInfo().mIL_Version.empty();
            }) != mDevices.cend());
}

inline bool Context::supportsBuiltInKernel(const std::string &name) const
{
    return (std::find_if(mDevices.cbegin(), mDevices.cend(), [&](const DeviceRefPtr &ptr) {
                return ptr->supportsBuiltInKernel(name);
            }) != mDevices.cend());
}

inline bool Context::hasCommandQueue(const _cl_command_queue *commandQueue) const
{
    return std::find_if(mCommandQueues.cbegin(), mCommandQueues.cend(),
                        [=](const CommandQueuePtr &ptr) { return ptr.get() == commandQueue; }) !=
           mCommandQueues.cend();
}

inline bool Context::hasMemory(const _cl_mem *memory) const
{
    return std::find_if(mMemories.cbegin(), mMemories.cend(), [=](const MemoryPtr &ptr) {
               return ptr.get() == memory;
           }) != mMemories.cend();
}

inline bool Context::hasSampler(const _cl_sampler *sampler) const
{
    return std::find_if(mSamplers.cbegin(), mSamplers.cend(), [=](const SamplerPtr &ptr) {
               return ptr.get() == sampler;
           }) != mSamplers.cend();
}

inline bool Context::hasProgram(const _cl_program *program) const
{
    return std::find_if(mPrograms.cbegin(), mPrograms.cend(), [=](const ProgramPtr &ptr) {
               return ptr.get() == program;
           }) != mPrograms.cend();
}

inline void Context::retain() noexcept
{
    addRef();
}

}  // namespace cl

#endif  // LIBANGLE_CLCONTEXT_H_
