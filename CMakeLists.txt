# Copyright 2013 The ANGLE Project Authors. All rights reserved.
# CMake build for the shader translator copyright 2023 ds-sloth
# Use of this source code is governed by a BSD - style license that can be
# found in the LICENSE file.

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(angle_translator STATIC
            EXCLUDE_FROM_ALL

# angle_translator_exported_headers = [
    export/GLSLANG/ShaderLang.h
    export/GLSLANG/ShaderVars.h
#  src/compiler/translator/blocklayout.h
#  src/compiler/translator/hlsl/blocklayoutHLSL.h

# angle_translator_sources = [
    include/EGL/egl.h
    include/EGL/eglext.h
    include/EGL/eglplatform.h
    include/GLES2/gl2.h
    include/GLES2/gl2ext.h
    include/GLES2/gl2platform.h
    include/GLES3/gl3.h
    include/GLES3/gl31.h
    include/GLES3/gl32.h
    include/GLES3/gl3platform.h
    include/KHR/khrplatform.h
    include/angle_gl.h
    src/compiler/translator/BaseTypes.cpp
    src/compiler/translator/BaseTypes.h
    src/compiler/translator/BuiltInFunctionEmulator.cpp
    src/compiler/translator/BuiltInFunctionEmulator.h
    src/compiler/translator/CallDAG.cpp
    src/compiler/translator/CallDAG.h
    src/compiler/translator/CodeGen.cpp
    src/compiler/translator/CollectVariables.cpp
    src/compiler/translator/CollectVariables.h
    src/compiler/translator/Common.h
    src/compiler/translator/Compiler.cpp
    src/compiler/translator/Compiler.h
    src/compiler/translator/ConstantUnion.cpp
    src/compiler/translator/ConstantUnion.h
    src/compiler/translator/Declarator.cpp
    src/compiler/translator/Declarator.h
    src/compiler/translator/Diagnostics.cpp
    src/compiler/translator/Diagnostics.h
    src/compiler/translator/DirectiveHandler.cpp
    src/compiler/translator/DirectiveHandler.h
    src/compiler/translator/ExtensionBehavior.cpp
    src/compiler/translator/ExtensionBehavior.h
    src/compiler/translator/FlagStd140Structs.cpp
    src/compiler/translator/FlagStd140Structs.h
    src/compiler/translator/FunctionLookup.cpp
    src/compiler/translator/FunctionLookup.h
    src/compiler/translator/HashNames.cpp
    src/compiler/translator/HashNames.h
    src/compiler/translator/ImmutableString_autogen.cpp
    src/compiler/translator/ImmutableString.h
    src/compiler/translator/ImmutableStringBuilder.cpp
    src/compiler/translator/ImmutableStringBuilder.h
    src/compiler/translator/InfoSink.cpp
    src/compiler/translator/InfoSink.h
    src/compiler/translator/Initialize.cpp
    src/compiler/translator/Initialize.h
    src/compiler/translator/InitializeDll.cpp
    src/compiler/translator/InitializeDll.h
    src/compiler/translator/InitializeGlobals.h
    src/compiler/translator/IntermNode.cpp
    src/compiler/translator/IntermNode.h
    src/compiler/translator/IsASTDepthBelowLimit.cpp
    src/compiler/translator/IsASTDepthBelowLimit.h
    src/compiler/translator/Operator.cpp
    src/compiler/translator/Operator_autogen.h
    src/compiler/translator/OutputTree.cpp
    src/compiler/translator/OutputTree.h
    src/compiler/translator/ParseContext.cpp
    src/compiler/translator/ParseContext.h
    src/compiler/translator/PoolAlloc.cpp
    src/compiler/translator/PoolAlloc.h
    src/compiler/translator/Pragma.h
    src/compiler/translator/QualifierTypes.cpp
    src/compiler/translator/QualifierTypes.h
    src/compiler/translator/Severity.h
    src/compiler/translator/ShaderLang.cpp
    src/compiler/translator/ShaderVars.cpp
    src/compiler/translator/StaticType.h
    src/compiler/translator/Symbol.cpp
    src/compiler/translator/Symbol.h
    src/compiler/translator/SymbolTable.cpp
    src/compiler/translator/SymbolTable.h
    src/compiler/translator/SymbolTable_autogen.cpp
    src/compiler/translator/SymbolTable_autogen.h
    src/compiler/translator/SymbolUniqueId.cpp
    src/compiler/translator/SymbolUniqueId.h
    src/compiler/translator/Types.cpp
    src/compiler/translator/Types.h
    src/compiler/translator/ValidateAST.cpp
    src/compiler/translator/ValidateAST.h
    src/compiler/translator/ValidateBarrierFunctionCall.cpp
    src/compiler/translator/ValidateBarrierFunctionCall.h
    src/compiler/translator/ValidateClipCullDistance.cpp
    src/compiler/translator/ValidateClipCullDistance.h
    src/compiler/translator/ValidateGlobalInitializer.cpp
    src/compiler/translator/ValidateGlobalInitializer.h
    src/compiler/translator/ValidateLimitations.cpp
    src/compiler/translator/ValidateLimitations.h
    src/compiler/translator/ValidateMaxParameters.cpp
    src/compiler/translator/ValidateMaxParameters.h
    src/compiler/translator/ValidateOutputs.cpp
    src/compiler/translator/ValidateOutputs.h
    src/compiler/translator/ValidateSwitch.cpp
    src/compiler/translator/ValidateSwitch.h
    src/compiler/translator/ValidateTypeSizeLimitations.cpp
    src/compiler/translator/ValidateTypeSizeLimitations.h
    src/compiler/translator/ValidateVaryingLocations.cpp
    src/compiler/translator/ValidateVaryingLocations.h
    src/compiler/translator/VariablePacker.cpp
    src/compiler/translator/VariablePacker.h
    src/compiler/translator/blocklayout.cpp
    src/compiler/translator/glsl/TranslatorESSL.h
    src/compiler/translator/glsl/TranslatorGLSL.h
    src/compiler/translator/glsl/VersionGLSL.h
    src/compiler/translator/glslang.h
    src/compiler/translator/glslang_lex_autogen.cpp
    src/compiler/translator/glslang_tab_autogen.cpp
    src/compiler/translator/glslang_tab_autogen.h
    src/compiler/translator/hlsl/TranslatorHLSL.h
    src/compiler/translator/length_limits.h
    src/compiler/translator/msl/DriverUniformMetal.h
    src/compiler/translator/msl/TranslatorMSL.h
    src/compiler/translator/spirv/TranslatorSPIRV.h
    src/compiler/translator/tree_ops/ClampFragDepth.cpp
    src/compiler/translator/tree_ops/ClampFragDepth.h
    src/compiler/translator/tree_ops/ClampIndirectIndices.cpp
    src/compiler/translator/tree_ops/ClampIndirectIndices.h
    src/compiler/translator/tree_ops/ClampPointSize.cpp
    src/compiler/translator/tree_ops/ClampPointSize.h
    src/compiler/translator/tree_ops/DeclareAndInitBuiltinsForInstancedMultiview.cpp
    src/compiler/translator/tree_ops/DeclareAndInitBuiltinsForInstancedMultiview.h
    src/compiler/translator/tree_ops/DeclarePerVertexBlocks.cpp
    src/compiler/translator/tree_ops/DeclarePerVertexBlocks.h
    src/compiler/translator/tree_ops/DeferGlobalInitializers.cpp
    src/compiler/translator/tree_ops/DeferGlobalInitializers.h
    src/compiler/translator/tree_ops/EmulateGLFragColorBroadcast.cpp
    src/compiler/translator/tree_ops/EmulateGLFragColorBroadcast.h
    src/compiler/translator/tree_ops/EmulateMultiDrawShaderBuiltins.cpp
    src/compiler/translator/tree_ops/EmulateMultiDrawShaderBuiltins.h
    src/compiler/translator/tree_ops/FoldExpressions.cpp
    src/compiler/translator/tree_ops/FoldExpressions.h
    src/compiler/translator/tree_ops/ForcePrecisionQualifier.cpp
    src/compiler/translator/tree_ops/ForcePrecisionQualifier.h
    src/compiler/translator/tree_ops/InitializeVariables.cpp
    src/compiler/translator/tree_ops/InitializeVariables.h
    src/compiler/translator/tree_ops/MonomorphizeUnsupportedFunctions.cpp
    src/compiler/translator/tree_ops/MonomorphizeUnsupportedFunctions.h
    src/compiler/translator/tree_ops/PreTransformTextureCubeGradDerivatives.cpp
    src/compiler/translator/tree_ops/PreTransformTextureCubeGradDerivatives.h
    src/compiler/translator/tree_ops/PruneEmptyCases.cpp
    src/compiler/translator/tree_ops/PruneEmptyCases.h
    src/compiler/translator/tree_ops/PruneNoOps.cpp
    src/compiler/translator/tree_ops/PruneNoOps.h
    src/compiler/translator/tree_ops/RecordConstantPrecision.cpp
    src/compiler/translator/tree_ops/RecordConstantPrecision.h
    src/compiler/translator/tree_ops/RemoveArrayLengthMethod.cpp
    src/compiler/translator/tree_ops/RemoveArrayLengthMethod.h
    src/compiler/translator/tree_ops/RemoveAtomicCounterBuiltins.cpp
    src/compiler/translator/tree_ops/RemoveAtomicCounterBuiltins.h
    src/compiler/translator/tree_ops/RemoveDynamicIndexing.cpp
    src/compiler/translator/tree_ops/RemoveDynamicIndexing.h
    src/compiler/translator/tree_ops/RemoveInactiveInterfaceVariables.cpp
    src/compiler/translator/tree_ops/RemoveInactiveInterfaceVariables.h
    src/compiler/translator/tree_ops/RemoveInvariantDeclaration.cpp
    src/compiler/translator/tree_ops/RemoveInvariantDeclaration.h
    src/compiler/translator/tree_ops/RemoveUnreferencedVariables.cpp
    src/compiler/translator/tree_ops/RemoveUnreferencedVariables.h
    src/compiler/translator/tree_ops/RescopeGlobalVariables.cpp
    src/compiler/translator/tree_ops/RescopeGlobalVariables.h
    src/compiler/translator/tree_ops/RewriteArrayOfArrayOfOpaqueUniforms.cpp
    src/compiler/translator/tree_ops/RewriteArrayOfArrayOfOpaqueUniforms.h
    src/compiler/translator/tree_ops/RewriteAtomicCounters.cpp
    src/compiler/translator/tree_ops/RewriteAtomicCounters.h
    src/compiler/translator/tree_ops/RewriteCubeMapSamplersAs2DArray.cpp
    src/compiler/translator/tree_ops/RewriteCubeMapSamplersAs2DArray.h
    src/compiler/translator/tree_ops/RewriteDfdy.cpp
    src/compiler/translator/tree_ops/RewriteDfdy.h
    src/compiler/translator/tree_ops/RewritePixelLocalStorage.cpp
    src/compiler/translator/tree_ops/RewritePixelLocalStorage.h
    src/compiler/translator/tree_ops/RewriteStructSamplers.cpp
    src/compiler/translator/tree_ops/RewriteStructSamplers.h
    src/compiler/translator/tree_ops/RewriteTexelFetchOffset.cpp
    src/compiler/translator/tree_ops/RewriteTexelFetchOffset.h
    src/compiler/translator/tree_ops/SeparateDeclarations.cpp
    src/compiler/translator/tree_ops/SeparateDeclarations.h
    src/compiler/translator/tree_ops/SeparateStructFromUniformDeclarations.cpp
    src/compiler/translator/tree_ops/SeparateStructFromUniformDeclarations.h
    src/compiler/translator/tree_ops/SimplifyLoopConditions.cpp
    src/compiler/translator/tree_ops/SimplifyLoopConditions.h
    src/compiler/translator/tree_ops/SplitSequenceOperator.cpp
    src/compiler/translator/tree_ops/SplitSequenceOperator.h
    src/compiler/translator/tree_ops/glsl/RegenerateStructNames.h
    src/compiler/translator/tree_ops/glsl/RewriteRepeatedAssignToSwizzled.h
    src/compiler/translator/tree_ops/glsl/ScalarizeVecAndMatConstructorArgs.h
    src/compiler/translator/tree_ops/glsl/UseInterfaceBlockFields.h
    src/compiler/translator/tree_ops/glsl/apple/AddAndTrueToLoopCondition.h
    src/compiler/translator/tree_ops/glsl/apple/RewriteDoWhile.h
    src/compiler/translator/tree_ops/glsl/apple/RewriteRowMajorMatrices.h
    src/compiler/translator/tree_ops/glsl/apple/RewriteUnaryMinusOperatorFloat.h
    src/compiler/translator/tree_ops/glsl/apple/UnfoldShortCircuitAST.h
    src/compiler/translator/tree_util/BuiltIn.h
    src/compiler/translator/tree_util/BuiltIn_ESSL_autogen.h
    src/compiler/translator/tree_util/BuiltIn_complete_autogen.h
    src/compiler/translator/tree_util/DriverUniform.cpp
    src/compiler/translator/tree_util/DriverUniform.h
    src/compiler/translator/tree_util/FindFunction.cpp
    src/compiler/translator/tree_util/FindFunction.h
    src/compiler/translator/tree_util/FindMain.cpp
    src/compiler/translator/tree_util/FindMain.h
    src/compiler/translator/tree_util/FindPreciseNodes.cpp
    src/compiler/translator/tree_util/FindPreciseNodes.h
    src/compiler/translator/tree_util/FindSymbolNode.cpp
    src/compiler/translator/tree_util/FindSymbolNode.h
    src/compiler/translator/tree_util/IntermNodePatternMatcher.cpp
    src/compiler/translator/tree_util/IntermNodePatternMatcher.h
    src/compiler/translator/tree_util/IntermNode_util.cpp
    src/compiler/translator/tree_util/IntermNode_util.h
    src/compiler/translator/tree_util/IntermTraverse.cpp
    src/compiler/translator/tree_util/IntermTraverse.h
    src/compiler/translator/tree_util/NodeSearch.h
    src/compiler/translator/tree_util/ReplaceArrayOfMatrixVarying.cpp
    src/compiler/translator/tree_util/ReplaceArrayOfMatrixVarying.h
    src/compiler/translator/tree_util/ReplaceClipCullDistanceVariable.cpp
    src/compiler/translator/tree_util/ReplaceClipCullDistanceVariable.h
    src/compiler/translator/tree_util/ReplaceShadowingVariables.cpp
    src/compiler/translator/tree_util/ReplaceShadowingVariables.h
    src/compiler/translator/tree_util/ReplaceVariable.cpp
    src/compiler/translator/tree_util/ReplaceVariable.h
    src/compiler/translator/tree_util/RewriteSampleMaskVariable.cpp
    src/compiler/translator/tree_util/RewriteSampleMaskVariable.h
    src/compiler/translator/tree_util/RunAtTheBeginningOfShader.cpp
    src/compiler/translator/tree_util/RunAtTheBeginningOfShader.h
    src/compiler/translator/tree_util/RunAtTheEndOfShader.cpp
    src/compiler/translator/tree_util/RunAtTheEndOfShader.h
    src/compiler/translator/tree_util/SpecializationConstant.cpp
    src/compiler/translator/tree_util/SpecializationConstant.h
    src/compiler/translator/tree_util/Visit.h
    src/compiler/translator/util.cpp
    src/compiler/translator/util.h

# angle_translator_glsl_base_sources = [
    src/compiler/translator/glsl/OutputGLSLBase.cpp
    src/compiler/translator/glsl/OutputGLSLBase.h

# angle_translator_glsl_and_vulkan_base_sources = [
    src/compiler/translator/glsl/OutputGLSL.cpp
    src/compiler/translator/glsl/OutputGLSL.h

# angle_translator_glsl_sources = [
    src/compiler/translator/glsl/BuiltInFunctionEmulatorGLSL.cpp
    src/compiler/translator/glsl/BuiltInFunctionEmulatorGLSL.h
    src/compiler/translator/glsl/ExtensionGLSL.cpp
    src/compiler/translator/glsl/ExtensionGLSL.h
    src/compiler/translator/glsl/TranslatorGLSL.cpp
    src/compiler/translator/glsl/VersionGLSL.cpp
    src/compiler/translator/tree_ops/glsl/RegenerateStructNames.cpp
    src/compiler/translator/tree_ops/glsl/RewriteRepeatedAssignToSwizzled.cpp
    src/compiler/translator/tree_ops/glsl/ScalarizeVecAndMatConstructorArgs.cpp
    src/compiler/translator/tree_ops/glsl/UseInterfaceBlockFields.cpp

# angle_translator_glsl_apple_sources = [
#  src/compiler/translator/tree_ops/glsl/apple/AddAndTrueToLoopCondition.cpp
#  src/compiler/translator/tree_ops/glsl/apple/RewriteDoWhile.cpp
#  src/compiler/translator/tree_ops/glsl/apple/RewriteRowMajorMatrices.cpp
#  src/compiler/translator/tree_ops/glsl/apple/RewriteUnaryMinusOperatorFloat.cpp
#  src/compiler/translator/tree_ops/glsl/apple/UnfoldShortCircuitAST.cpp

# angle_preprocessor_sources = [
    src/compiler/preprocessor/DiagnosticsBase.cpp
    src/compiler/preprocessor/DiagnosticsBase.h
    src/compiler/preprocessor/DirectiveHandlerBase.cpp
    src/compiler/preprocessor/DirectiveHandlerBase.h
    src/compiler/preprocessor/DirectiveParser.cpp
    src/compiler/preprocessor/DirectiveParser.h
    src/compiler/preprocessor/ExpressionParser.h
    src/compiler/preprocessor/Input.cpp
    src/compiler/preprocessor/Input.h
    src/compiler/preprocessor/Lexer.cpp
    src/compiler/preprocessor/Lexer.h
    src/compiler/preprocessor/Macro.cpp
    src/compiler/preprocessor/Macro.h
    src/compiler/preprocessor/MacroExpander.cpp
    src/compiler/preprocessor/MacroExpander.h
    src/compiler/preprocessor/Preprocessor.cpp
    src/compiler/preprocessor/Preprocessor.h
    src/compiler/preprocessor/SourceLocation.h
    src/compiler/preprocessor/Token.cpp
    src/compiler/preprocessor/Token.h
    src/compiler/preprocessor/Tokenizer.h
    src/compiler/preprocessor/numeric_lex.h
    src/compiler/preprocessor/preprocessor_lex_autogen.cpp
    src/compiler/preprocessor/preprocessor_tab_autogen.cpp

# libangle_common_headers = [
    src/common/BinaryStream.h
    src/common/CircularBuffer.h
    src/common/Color.h
    src/common/Color.inc
    src/common/CompiledShaderState.h
    src/common/FastVector.h
    src/common/FixedQueue.h
    src/common/FixedVector.h
    src/common/MemoryBuffer.h
    src/common/Optional.h
    src/common/PackedEGLEnums_autogen.h
    src/common/PackedEnums.h
    src/common/PackedGLEnums_autogen.h
    src/common/PoolAlloc.h
    src/common/RingBufferAllocator.h
    src/common/Spinlock.h
    src/common/SynchronizedValue.h
    src/common/WorkerThread.h
    src/common/aligned_memory.h
#    src/common/android_util.h
    src/common/angleutils.h
#    src/common/apple_platform_utils.h
    src/common/backtrace_utils.h
    src/common/base/anglebase/base_export.h
    src/common/base/anglebase/containers/mru_cache.h
    src/common/base/anglebase/logging.h
    src/common/base/anglebase/macros.h
    src/common/base/anglebase/no_destructor.h
    src/common/base/anglebase/numerics/checked_math.h
    src/common/base/anglebase/numerics/checked_math_impl.h
    src/common/base/anglebase/numerics/clamped_math.h
    src/common/base/anglebase/numerics/clamped_math_impl.h
    src/common/base/anglebase/numerics/math_constants.h
    src/common/base/anglebase/numerics/ranges.h
    src/common/base/anglebase/numerics/safe_conversions.h
    src/common/base/anglebase/numerics/safe_conversions_arm_impl.h
    src/common/base/anglebase/numerics/safe_conversions_impl.h
    src/common/base/anglebase/numerics/safe_math.h
    src/common/base/anglebase/numerics/safe_math_arm_impl.h
    src/common/base/anglebase/numerics/safe_math_clang_gcc_impl.h
    src/common/base/anglebase/numerics/safe_math_shared_impl.h
    src/common/base/anglebase/sha1.h
    src/common/base/anglebase/sys_byteorder.h
    src/common/bitset_utils.h
    src/common/debug.h
    src/common/entry_points_enum_autogen.h
    src/common/event_tracer.h
    src/common/hash_utils.h
    src/common/mathutil.h
    src/common/matrix_utils.h
    src/common/platform.h
    src/common/platform_helpers.h
    src/common/string_utils.h
    src/common/tls.h
    src/common/utilities.h
    src/common/vector_utils.h

# libangle_common_sources = libangle_common_headers + [
    src/common/Float16ToFloat32.cpp
    src/common/MemoryBuffer.cpp
    src/common/PackedEGLEnums_autogen.cpp
    src/common/PackedEnums.cpp
    src/common/PackedGLEnums_autogen.cpp
    src/common/PoolAlloc.cpp
    src/common/RingBufferAllocator.cpp
    src/common/WorkerThread.cpp
    src/common/aligned_memory.cpp
#    src/common/android_util.cpp
    src/common/angleutils.cpp
    src/common/base/anglebase/sha1.cc
    src/common/debug.cpp
    src/common/entry_points_enum_autogen.cpp
    src/common/event_tracer.cpp
    src/common/mathutil.cpp
    src/common/matrix_utils.cpp
    src/common/platform_helpers.cpp
    src/common/string_utils.cpp
    src/common/tls.cpp
    src/common/uniform_type_info_autogen.cpp
    src/common/utilities.cpp

# libangle_common_shader_state_sources =
#    libangle_common_headers + [
    src/common/CompiledShaderState.cpp

    src/common/third_party/xxhash/xxhash.c
)

target_compile_definitions(angle_translator PRIVATE ANGLE_ENABLE_GLSL)

target_include_directories(angle_translator PRIVATE src src/common/base src/common/third_party/xxhash)
target_include_directories(angle_translator PUBLIC export)


add_executable(shader_translator_sample EXCLUDE_FROM_ALL samples/shader_translator/shader_translator.cpp)
target_include_directories(shader_translator_sample PRIVATE include)

target_link_libraries(shader_translator_sample angle_translator)
