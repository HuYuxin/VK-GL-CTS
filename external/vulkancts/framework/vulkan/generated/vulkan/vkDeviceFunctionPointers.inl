/* WARNING: This is auto-generated file. Do not modify, since changes will
 * be lost! Modify the generating script instead.
 * This file was generated by /scripts/gen_framework.py
 */

GetDeviceProcAddrFunc										getDeviceProcAddr;
DestroyDeviceFunc											destroyDevice;
GetDeviceQueueFunc											getDeviceQueue;
QueueSubmitFunc												queueSubmit;
QueueWaitIdleFunc											queueWaitIdle;
DeviceWaitIdleFunc											deviceWaitIdle;
AllocateMemoryFunc											allocateMemory;
FreeMemoryFunc												freeMemory;
MapMemoryFunc												mapMemory;
UnmapMemoryFunc												unmapMemory;
FlushMappedMemoryRangesFunc									flushMappedMemoryRanges;
InvalidateMappedMemoryRangesFunc							invalidateMappedMemoryRanges;
GetDeviceMemoryCommitmentFunc								getDeviceMemoryCommitment;
GetBufferMemoryRequirementsFunc								getBufferMemoryRequirements;
BindBufferMemoryFunc										bindBufferMemory;
GetImageMemoryRequirementsFunc								getImageMemoryRequirements;
BindImageMemoryFunc											bindImageMemory;
GetImageSparseMemoryRequirementsFunc						getImageSparseMemoryRequirements;
QueueBindSparseFunc											queueBindSparse;
CreateFenceFunc												createFence;
DestroyFenceFunc											destroyFence;
ResetFencesFunc												resetFences;
GetFenceStatusFunc											getFenceStatus;
WaitForFencesFunc											waitForFences;
CreateSemaphoreFunc											createSemaphore;
DestroySemaphoreFunc										destroySemaphore;
CreateEventFunc												createEvent;
DestroyEventFunc											destroyEvent;
GetEventStatusFunc											getEventStatus;
SetEventFunc												setEvent;
ResetEventFunc												resetEvent;
CreateQueryPoolFunc											createQueryPool;
DestroyQueryPoolFunc										destroyQueryPool;
GetQueryPoolResultsFunc										getQueryPoolResults;
ResetQueryPoolFunc											resetQueryPool;
CreateBufferFunc											createBuffer;
DestroyBufferFunc											destroyBuffer;
CreateBufferViewFunc										createBufferView;
DestroyBufferViewFunc										destroyBufferView;
CreateImageFunc												createImage;
DestroyImageFunc											destroyImage;
GetImageSubresourceLayoutFunc								getImageSubresourceLayout;
CreateImageViewFunc											createImageView;
DestroyImageViewFunc										destroyImageView;
CreateShaderModuleFunc										createShaderModule;
DestroyShaderModuleFunc										destroyShaderModule;
CreatePipelineCacheFunc										createPipelineCache;
DestroyPipelineCacheFunc									destroyPipelineCache;
GetPipelineCacheDataFunc									getPipelineCacheData;
MergePipelineCachesFunc										mergePipelineCaches;
CreateGraphicsPipelinesFunc									createGraphicsPipelines;
CreateComputePipelinesFunc									createComputePipelines;
GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEIFunc			getDeviceSubpassShadingMaxWorkgroupSizeHUAWEI;
DestroyPipelineFunc											destroyPipeline;
CreatePipelineLayoutFunc									createPipelineLayout;
DestroyPipelineLayoutFunc									destroyPipelineLayout;
CreateSamplerFunc											createSampler;
DestroySamplerFunc											destroySampler;
CreateDescriptorSetLayoutFunc								createDescriptorSetLayout;
DestroyDescriptorSetLayoutFunc								destroyDescriptorSetLayout;
CreateDescriptorPoolFunc									createDescriptorPool;
DestroyDescriptorPoolFunc									destroyDescriptorPool;
ResetDescriptorPoolFunc										resetDescriptorPool;
AllocateDescriptorSetsFunc									allocateDescriptorSets;
FreeDescriptorSetsFunc										freeDescriptorSets;
UpdateDescriptorSetsFunc									updateDescriptorSets;
CreateFramebufferFunc										createFramebuffer;
DestroyFramebufferFunc										destroyFramebuffer;
CreateRenderPassFunc										createRenderPass;
DestroyRenderPassFunc										destroyRenderPass;
GetRenderAreaGranularityFunc								getRenderAreaGranularity;
GetRenderingAreaGranularityKHRFunc							getRenderingAreaGranularityKHR;
CreateCommandPoolFunc										createCommandPool;
DestroyCommandPoolFunc										destroyCommandPool;
ResetCommandPoolFunc										resetCommandPool;
AllocateCommandBuffersFunc									allocateCommandBuffers;
FreeCommandBuffersFunc										freeCommandBuffers;
BeginCommandBufferFunc										beginCommandBuffer;
EndCommandBufferFunc										endCommandBuffer;
ResetCommandBufferFunc										resetCommandBuffer;
CmdBindPipelineFunc											cmdBindPipeline;
CmdSetAttachmentFeedbackLoopEnableEXTFunc					cmdSetAttachmentFeedbackLoopEnableEXT;
CmdSetViewportFunc											cmdSetViewport;
CmdSetScissorFunc											cmdSetScissor;
CmdSetLineWidthFunc											cmdSetLineWidth;
CmdSetDepthBiasFunc											cmdSetDepthBias;
CmdSetBlendConstantsFunc									cmdSetBlendConstants;
CmdSetDepthBoundsFunc										cmdSetDepthBounds;
CmdSetStencilCompareMaskFunc								cmdSetStencilCompareMask;
CmdSetStencilWriteMaskFunc									cmdSetStencilWriteMask;
CmdSetStencilReferenceFunc									cmdSetStencilReference;
CmdBindDescriptorSetsFunc									cmdBindDescriptorSets;
CmdBindIndexBufferFunc										cmdBindIndexBuffer;
CmdBindVertexBuffersFunc									cmdBindVertexBuffers;
CmdDrawFunc													cmdDraw;
CmdDrawIndexedFunc											cmdDrawIndexed;
CmdDrawMultiEXTFunc											cmdDrawMultiEXT;
CmdDrawMultiIndexedEXTFunc									cmdDrawMultiIndexedEXT;
CmdDrawIndirectFunc											cmdDrawIndirect;
CmdDrawIndexedIndirectFunc									cmdDrawIndexedIndirect;
CmdDispatchFunc												cmdDispatch;
CmdDispatchIndirectFunc										cmdDispatchIndirect;
CmdSubpassShadingHUAWEIFunc									cmdSubpassShadingHUAWEI;
CmdDrawClusterHUAWEIFunc									cmdDrawClusterHUAWEI;
CmdDrawClusterIndirectHUAWEIFunc							cmdDrawClusterIndirectHUAWEI;
CmdUpdatePipelineIndirectBufferNVFunc						cmdUpdatePipelineIndirectBufferNV;
CmdCopyBufferFunc											cmdCopyBuffer;
CmdCopyImageFunc											cmdCopyImage;
CmdBlitImageFunc											cmdBlitImage;
CmdCopyBufferToImageFunc									cmdCopyBufferToImage;
CmdCopyImageToBufferFunc									cmdCopyImageToBuffer;
CmdCopyMemoryIndirectNVFunc									cmdCopyMemoryIndirectNV;
CmdCopyMemoryToImageIndirectNVFunc							cmdCopyMemoryToImageIndirectNV;
CmdUpdateBufferFunc											cmdUpdateBuffer;
CmdFillBufferFunc											cmdFillBuffer;
CmdClearColorImageFunc										cmdClearColorImage;
CmdClearDepthStencilImageFunc								cmdClearDepthStencilImage;
CmdClearAttachmentsFunc										cmdClearAttachments;
CmdResolveImageFunc											cmdResolveImage;
CmdSetEventFunc												cmdSetEvent;
CmdResetEventFunc											cmdResetEvent;
CmdWaitEventsFunc											cmdWaitEvents;
CmdPipelineBarrierFunc										cmdPipelineBarrier;
CmdBeginQueryFunc											cmdBeginQuery;
CmdEndQueryFunc												cmdEndQuery;
CmdBeginConditionalRenderingEXTFunc							cmdBeginConditionalRenderingEXT;
CmdEndConditionalRenderingEXTFunc							cmdEndConditionalRenderingEXT;
CmdResetQueryPoolFunc										cmdResetQueryPool;
CmdWriteTimestampFunc										cmdWriteTimestamp;
CmdCopyQueryPoolResultsFunc									cmdCopyQueryPoolResults;
CmdPushConstantsFunc										cmdPushConstants;
CmdBeginRenderPassFunc										cmdBeginRenderPass;
CmdNextSubpassFunc											cmdNextSubpass;
CmdEndRenderPassFunc										cmdEndRenderPass;
CmdExecuteCommandsFunc										cmdExecuteCommands;
CreateSharedSwapchainsKHRFunc								createSharedSwapchainsKHR;
CreateSwapchainKHRFunc										createSwapchainKHR;
DestroySwapchainKHRFunc										destroySwapchainKHR;
GetSwapchainImagesKHRFunc									getSwapchainImagesKHR;
AcquireNextImageKHRFunc										acquireNextImageKHR;
QueuePresentKHRFunc											queuePresentKHR;
DebugMarkerSetObjectNameEXTFunc								debugMarkerSetObjectNameEXT;
DebugMarkerSetObjectTagEXTFunc								debugMarkerSetObjectTagEXT;
CmdDebugMarkerBeginEXTFunc									cmdDebugMarkerBeginEXT;
CmdDebugMarkerEndEXTFunc									cmdDebugMarkerEndEXT;
CmdDebugMarkerInsertEXTFunc									cmdDebugMarkerInsertEXT;
GetMemoryWin32HandleNVFunc									getMemoryWin32HandleNV;
CmdExecuteGeneratedCommandsNVFunc							cmdExecuteGeneratedCommandsNV;
CmdPreprocessGeneratedCommandsNVFunc						cmdPreprocessGeneratedCommandsNV;
CmdBindPipelineShaderGroupNVFunc							cmdBindPipelineShaderGroupNV;
GetGeneratedCommandsMemoryRequirementsNVFunc				getGeneratedCommandsMemoryRequirementsNV;
CreateIndirectCommandsLayoutNVFunc							createIndirectCommandsLayoutNV;
DestroyIndirectCommandsLayoutNVFunc							destroyIndirectCommandsLayoutNV;
CmdPushDescriptorSetKHRFunc									cmdPushDescriptorSetKHR;
TrimCommandPoolFunc											trimCommandPool;
GetMemoryWin32HandleKHRFunc									getMemoryWin32HandleKHR;
GetMemoryWin32HandlePropertiesKHRFunc						getMemoryWin32HandlePropertiesKHR;
GetMemoryFdKHRFunc											getMemoryFdKHR;
GetMemoryFdPropertiesKHRFunc								getMemoryFdPropertiesKHR;
GetMemoryZirconHandleFUCHSIAFunc							getMemoryZirconHandleFUCHSIA;
GetMemoryZirconHandlePropertiesFUCHSIAFunc					getMemoryZirconHandlePropertiesFUCHSIA;
GetMemoryRemoteAddressNVFunc								getMemoryRemoteAddressNV;
GetSemaphoreWin32HandleKHRFunc								getSemaphoreWin32HandleKHR;
ImportSemaphoreWin32HandleKHRFunc							importSemaphoreWin32HandleKHR;
GetSemaphoreFdKHRFunc										getSemaphoreFdKHR;
ImportSemaphoreFdKHRFunc									importSemaphoreFdKHR;
GetSemaphoreZirconHandleFUCHSIAFunc							getSemaphoreZirconHandleFUCHSIA;
ImportSemaphoreZirconHandleFUCHSIAFunc						importSemaphoreZirconHandleFUCHSIA;
GetFenceWin32HandleKHRFunc									getFenceWin32HandleKHR;
ImportFenceWin32HandleKHRFunc								importFenceWin32HandleKHR;
GetFenceFdKHRFunc											getFenceFdKHR;
ImportFenceFdKHRFunc										importFenceFdKHR;
DisplayPowerControlEXTFunc									displayPowerControlEXT;
RegisterDeviceEventEXTFunc									registerDeviceEventEXT;
RegisterDisplayEventEXTFunc									registerDisplayEventEXT;
GetSwapchainCounterEXTFunc									getSwapchainCounterEXT;
GetDeviceGroupPeerMemoryFeaturesFunc						getDeviceGroupPeerMemoryFeatures;
BindBufferMemory2Func										bindBufferMemory2;
BindImageMemory2Func										bindImageMemory2;
CmdSetDeviceMaskFunc										cmdSetDeviceMask;
GetDeviceGroupPresentCapabilitiesKHRFunc					getDeviceGroupPresentCapabilitiesKHR;
GetDeviceGroupSurfacePresentModesKHRFunc					getDeviceGroupSurfacePresentModesKHR;
AcquireNextImage2KHRFunc									acquireNextImage2KHR;
CmdDispatchBaseFunc											cmdDispatchBase;
CreateDescriptorUpdateTemplateFunc							createDescriptorUpdateTemplate;
DestroyDescriptorUpdateTemplateFunc							destroyDescriptorUpdateTemplate;
UpdateDescriptorSetWithTemplateFunc							updateDescriptorSetWithTemplate;
CmdPushDescriptorSetWithTemplateKHRFunc						cmdPushDescriptorSetWithTemplateKHR;
SetHdrMetadataEXTFunc										setHdrMetadataEXT;
GetSwapchainStatusKHRFunc									getSwapchainStatusKHR;
GetRefreshCycleDurationGOOGLEFunc							getRefreshCycleDurationGOOGLE;
GetPastPresentationTimingGOOGLEFunc							getPastPresentationTimingGOOGLE;
CmdSetViewportWScalingNVFunc								cmdSetViewportWScalingNV;
CmdSetDiscardRectangleEXTFunc								cmdSetDiscardRectangleEXT;
CmdSetDiscardRectangleEnableEXTFunc							cmdSetDiscardRectangleEnableEXT;
CmdSetDiscardRectangleModeEXTFunc							cmdSetDiscardRectangleModeEXT;
CmdSetSampleLocationsEXTFunc								cmdSetSampleLocationsEXT;
GetBufferMemoryRequirements2Func							getBufferMemoryRequirements2;
GetImageMemoryRequirements2Func								getImageMemoryRequirements2;
GetImageSparseMemoryRequirements2Func						getImageSparseMemoryRequirements2;
GetDeviceBufferMemoryRequirementsFunc						getDeviceBufferMemoryRequirements;
GetDeviceImageMemoryRequirementsFunc						getDeviceImageMemoryRequirements;
GetDeviceImageSparseMemoryRequirementsFunc					getDeviceImageSparseMemoryRequirements;
CreateSamplerYcbcrConversionFunc							createSamplerYcbcrConversion;
DestroySamplerYcbcrConversionFunc							destroySamplerYcbcrConversion;
GetDeviceQueue2Func											getDeviceQueue2;
CreateValidationCacheEXTFunc								createValidationCacheEXT;
DestroyValidationCacheEXTFunc								destroyValidationCacheEXT;
GetValidationCacheDataEXTFunc								getValidationCacheDataEXT;
MergeValidationCachesEXTFunc								mergeValidationCachesEXT;
GetDescriptorSetLayoutSupportFunc							getDescriptorSetLayoutSupport;
GetShaderInfoAMDFunc										getShaderInfoAMD;
SetLocalDimmingAMDFunc										setLocalDimmingAMD;
GetCalibratedTimestampsEXTFunc								getCalibratedTimestampsEXT;
SetDebugUtilsObjectNameEXTFunc								setDebugUtilsObjectNameEXT;
SetDebugUtilsObjectTagEXTFunc								setDebugUtilsObjectTagEXT;
QueueBeginDebugUtilsLabelEXTFunc							queueBeginDebugUtilsLabelEXT;
QueueEndDebugUtilsLabelEXTFunc								queueEndDebugUtilsLabelEXT;
QueueInsertDebugUtilsLabelEXTFunc							queueInsertDebugUtilsLabelEXT;
CmdBeginDebugUtilsLabelEXTFunc								cmdBeginDebugUtilsLabelEXT;
CmdEndDebugUtilsLabelEXTFunc								cmdEndDebugUtilsLabelEXT;
CmdInsertDebugUtilsLabelEXTFunc								cmdInsertDebugUtilsLabelEXT;
GetMemoryHostPointerPropertiesEXTFunc						getMemoryHostPointerPropertiesEXT;
CmdWriteBufferMarkerAMDFunc									cmdWriteBufferMarkerAMD;
CreateRenderPass2Func										createRenderPass2;
CmdBeginRenderPass2Func										cmdBeginRenderPass2;
CmdNextSubpass2Func											cmdNextSubpass2;
CmdEndRenderPass2Func										cmdEndRenderPass2;
GetSemaphoreCounterValueFunc								getSemaphoreCounterValue;
WaitSemaphoresFunc											waitSemaphores;
SignalSemaphoreFunc											signalSemaphore;
GetAndroidHardwareBufferPropertiesANDROIDFunc				getAndroidHardwareBufferPropertiesANDROID;
GetMemoryAndroidHardwareBufferANDROIDFunc					getMemoryAndroidHardwareBufferANDROID;
CmdDrawIndirectCountFunc									cmdDrawIndirectCount;
CmdDrawIndexedIndirectCountFunc								cmdDrawIndexedIndirectCount;
CmdSetCheckpointNVFunc										cmdSetCheckpointNV;
GetQueueCheckpointDataNVFunc								getQueueCheckpointDataNV;
CmdBindTransformFeedbackBuffersEXTFunc						cmdBindTransformFeedbackBuffersEXT;
CmdBeginTransformFeedbackEXTFunc							cmdBeginTransformFeedbackEXT;
CmdEndTransformFeedbackEXTFunc								cmdEndTransformFeedbackEXT;
CmdBeginQueryIndexedEXTFunc									cmdBeginQueryIndexedEXT;
CmdEndQueryIndexedEXTFunc									cmdEndQueryIndexedEXT;
CmdDrawIndirectByteCountEXTFunc								cmdDrawIndirectByteCountEXT;
CmdSetExclusiveScissorNVFunc								cmdSetExclusiveScissorNV;
CmdSetExclusiveScissorEnableNVFunc							cmdSetExclusiveScissorEnableNV;
CmdBindShadingRateImageNVFunc								cmdBindShadingRateImageNV;
CmdSetViewportShadingRatePaletteNVFunc						cmdSetViewportShadingRatePaletteNV;
CmdSetCoarseSampleOrderNVFunc								cmdSetCoarseSampleOrderNV;
CmdDrawMeshTasksNVFunc										cmdDrawMeshTasksNV;
CmdDrawMeshTasksIndirectNVFunc								cmdDrawMeshTasksIndirectNV;
CmdDrawMeshTasksIndirectCountNVFunc							cmdDrawMeshTasksIndirectCountNV;
CmdDrawMeshTasksEXTFunc										cmdDrawMeshTasksEXT;
CmdDrawMeshTasksIndirectEXTFunc								cmdDrawMeshTasksIndirectEXT;
CmdDrawMeshTasksIndirectCountEXTFunc						cmdDrawMeshTasksIndirectCountEXT;
CompileDeferredNVFunc										compileDeferredNV;
CreateAccelerationStructureNVFunc							createAccelerationStructureNV;
CmdBindInvocationMaskHUAWEIFunc								cmdBindInvocationMaskHUAWEI;
DestroyAccelerationStructureKHRFunc							destroyAccelerationStructureKHR;
DestroyAccelerationStructureNVFunc							destroyAccelerationStructureNV;
GetAccelerationStructureMemoryRequirementsNVFunc			getAccelerationStructureMemoryRequirementsNV;
BindAccelerationStructureMemoryNVFunc						bindAccelerationStructureMemoryNV;
CmdCopyAccelerationStructureNVFunc							cmdCopyAccelerationStructureNV;
CmdCopyAccelerationStructureKHRFunc							cmdCopyAccelerationStructureKHR;
CopyAccelerationStructureKHRFunc							copyAccelerationStructureKHR;
CmdCopyAccelerationStructureToMemoryKHRFunc					cmdCopyAccelerationStructureToMemoryKHR;
CopyAccelerationStructureToMemoryKHRFunc					copyAccelerationStructureToMemoryKHR;
CmdCopyMemoryToAccelerationStructureKHRFunc					cmdCopyMemoryToAccelerationStructureKHR;
CopyMemoryToAccelerationStructureKHRFunc					copyMemoryToAccelerationStructureKHR;
CmdWriteAccelerationStructuresPropertiesKHRFunc				cmdWriteAccelerationStructuresPropertiesKHR;
CmdWriteAccelerationStructuresPropertiesNVFunc				cmdWriteAccelerationStructuresPropertiesNV;
CmdBuildAccelerationStructureNVFunc							cmdBuildAccelerationStructureNV;
WriteAccelerationStructuresPropertiesKHRFunc				writeAccelerationStructuresPropertiesKHR;
CmdTraceRaysKHRFunc											cmdTraceRaysKHR;
CmdTraceRaysNVFunc											cmdTraceRaysNV;
GetRayTracingShaderGroupHandlesKHRFunc						getRayTracingShaderGroupHandlesKHR;
GetRayTracingCaptureReplayShaderGroupHandlesKHRFunc			getRayTracingCaptureReplayShaderGroupHandlesKHR;
GetAccelerationStructureHandleNVFunc						getAccelerationStructureHandleNV;
CreateRayTracingPipelinesNVFunc								createRayTracingPipelinesNV;
CreateRayTracingPipelinesKHRFunc							createRayTracingPipelinesKHR;
CmdTraceRaysIndirectKHRFunc									cmdTraceRaysIndirectKHR;
CmdTraceRaysIndirect2KHRFunc								cmdTraceRaysIndirect2KHR;
GetDeviceAccelerationStructureCompatibilityKHRFunc			getDeviceAccelerationStructureCompatibilityKHR;
GetRayTracingShaderGroupStackSizeKHRFunc					getRayTracingShaderGroupStackSizeKHR;
CmdSetRayTracingPipelineStackSizeKHRFunc					cmdSetRayTracingPipelineStackSizeKHR;
GetImageViewHandleNVXFunc									getImageViewHandleNVX;
GetImageViewAddressNVXFunc									getImageViewAddressNVX;
GetDeviceGroupSurfacePresentModes2EXTFunc					getDeviceGroupSurfacePresentModes2EXT;
AcquireFullScreenExclusiveModeEXTFunc						acquireFullScreenExclusiveModeEXT;
ReleaseFullScreenExclusiveModeEXTFunc						releaseFullScreenExclusiveModeEXT;
AcquireProfilingLockKHRFunc									acquireProfilingLockKHR;
ReleaseProfilingLockKHRFunc									releaseProfilingLockKHR;
GetImageDrmFormatModifierPropertiesEXTFunc					getImageDrmFormatModifierPropertiesEXT;
GetBufferOpaqueCaptureAddressFunc							getBufferOpaqueCaptureAddress;
GetBufferDeviceAddressFunc									getBufferDeviceAddress;
InitializePerformanceApiINTELFunc							initializePerformanceApiINTEL;
UninitializePerformanceApiINTELFunc							uninitializePerformanceApiINTEL;
CmdSetPerformanceMarkerINTELFunc							cmdSetPerformanceMarkerINTEL;
CmdSetPerformanceStreamMarkerINTELFunc						cmdSetPerformanceStreamMarkerINTEL;
CmdSetPerformanceOverrideINTELFunc							cmdSetPerformanceOverrideINTEL;
AcquirePerformanceConfigurationINTELFunc					acquirePerformanceConfigurationINTEL;
ReleasePerformanceConfigurationINTELFunc					releasePerformanceConfigurationINTEL;
QueueSetPerformanceConfigurationINTELFunc					queueSetPerformanceConfigurationINTEL;
GetPerformanceParameterINTELFunc							getPerformanceParameterINTEL;
GetDeviceMemoryOpaqueCaptureAddressFunc						getDeviceMemoryOpaqueCaptureAddress;
GetPipelineExecutablePropertiesKHRFunc						getPipelineExecutablePropertiesKHR;
GetPipelineExecutableStatisticsKHRFunc						getPipelineExecutableStatisticsKHR;
GetPipelineExecutableInternalRepresentationsKHRFunc			getPipelineExecutableInternalRepresentationsKHR;
CmdSetLineStippleEXTFunc									cmdSetLineStippleEXT;
CreateAccelerationStructureKHRFunc							createAccelerationStructureKHR;
CmdBuildAccelerationStructuresKHRFunc						cmdBuildAccelerationStructuresKHR;
CmdBuildAccelerationStructuresIndirectKHRFunc				cmdBuildAccelerationStructuresIndirectKHR;
BuildAccelerationStructuresKHRFunc							buildAccelerationStructuresKHR;
GetAccelerationStructureDeviceAddressKHRFunc				getAccelerationStructureDeviceAddressKHR;
CreateDeferredOperationKHRFunc								createDeferredOperationKHR;
DestroyDeferredOperationKHRFunc								destroyDeferredOperationKHR;
GetDeferredOperationMaxConcurrencyKHRFunc					getDeferredOperationMaxConcurrencyKHR;
GetDeferredOperationResultKHRFunc							getDeferredOperationResultKHR;
DeferredOperationJoinKHRFunc								deferredOperationJoinKHR;
GetPipelineIndirectMemoryRequirementsNVFunc					getPipelineIndirectMemoryRequirementsNV;
GetPipelineIndirectDeviceAddressNVFunc						getPipelineIndirectDeviceAddressNV;
CmdSetCullModeFunc											cmdSetCullMode;
CmdSetFrontFaceFunc											cmdSetFrontFace;
CmdSetPrimitiveTopologyFunc									cmdSetPrimitiveTopology;
CmdSetViewportWithCountFunc									cmdSetViewportWithCount;
CmdSetScissorWithCountFunc									cmdSetScissorWithCount;
CmdBindIndexBuffer2KHRFunc									cmdBindIndexBuffer2KHR;
CmdBindVertexBuffers2Func									cmdBindVertexBuffers2;
CmdSetDepthTestEnableFunc									cmdSetDepthTestEnable;
CmdSetDepthWriteEnableFunc									cmdSetDepthWriteEnable;
CmdSetDepthCompareOpFunc									cmdSetDepthCompareOp;
CmdSetDepthBoundsTestEnableFunc								cmdSetDepthBoundsTestEnable;
CmdSetStencilTestEnableFunc									cmdSetStencilTestEnable;
CmdSetStencilOpFunc											cmdSetStencilOp;
CmdSetPatchControlPointsEXTFunc								cmdSetPatchControlPointsEXT;
CmdSetRasterizerDiscardEnableFunc							cmdSetRasterizerDiscardEnable;
CmdSetDepthBiasEnableFunc									cmdSetDepthBiasEnable;
CmdSetLogicOpEXTFunc										cmdSetLogicOpEXT;
CmdSetPrimitiveRestartEnableFunc							cmdSetPrimitiveRestartEnable;
CmdSetTessellationDomainOriginEXTFunc						cmdSetTessellationDomainOriginEXT;
CmdSetDepthClampEnableEXTFunc								cmdSetDepthClampEnableEXT;
CmdSetPolygonModeEXTFunc									cmdSetPolygonModeEXT;
CmdSetRasterizationSamplesEXTFunc							cmdSetRasterizationSamplesEXT;
CmdSetSampleMaskEXTFunc										cmdSetSampleMaskEXT;
CmdSetAlphaToCoverageEnableEXTFunc							cmdSetAlphaToCoverageEnableEXT;
CmdSetAlphaToOneEnableEXTFunc								cmdSetAlphaToOneEnableEXT;
CmdSetLogicOpEnableEXTFunc									cmdSetLogicOpEnableEXT;
CmdSetColorBlendEnableEXTFunc								cmdSetColorBlendEnableEXT;
CmdSetColorBlendEquationEXTFunc								cmdSetColorBlendEquationEXT;
CmdSetColorWriteMaskEXTFunc									cmdSetColorWriteMaskEXT;
CmdSetRasterizationStreamEXTFunc							cmdSetRasterizationStreamEXT;
CmdSetConservativeRasterizationModeEXTFunc					cmdSetConservativeRasterizationModeEXT;
CmdSetExtraPrimitiveOverestimationSizeEXTFunc				cmdSetExtraPrimitiveOverestimationSizeEXT;
CmdSetDepthClipEnableEXTFunc								cmdSetDepthClipEnableEXT;
CmdSetSampleLocationsEnableEXTFunc							cmdSetSampleLocationsEnableEXT;
CmdSetColorBlendAdvancedEXTFunc								cmdSetColorBlendAdvancedEXT;
CmdSetProvokingVertexModeEXTFunc							cmdSetProvokingVertexModeEXT;
CmdSetLineRasterizationModeEXTFunc							cmdSetLineRasterizationModeEXT;
CmdSetLineStippleEnableEXTFunc								cmdSetLineStippleEnableEXT;
CmdSetDepthClipNegativeOneToOneEXTFunc						cmdSetDepthClipNegativeOneToOneEXT;
CmdSetViewportWScalingEnableNVFunc							cmdSetViewportWScalingEnableNV;
CmdSetViewportSwizzleNVFunc									cmdSetViewportSwizzleNV;
CmdSetCoverageToColorEnableNVFunc							cmdSetCoverageToColorEnableNV;
CmdSetCoverageToColorLocationNVFunc							cmdSetCoverageToColorLocationNV;
CmdSetCoverageModulationModeNVFunc							cmdSetCoverageModulationModeNV;
CmdSetCoverageModulationTableEnableNVFunc					cmdSetCoverageModulationTableEnableNV;
CmdSetCoverageModulationTableNVFunc							cmdSetCoverageModulationTableNV;
CmdSetShadingRateImageEnableNVFunc							cmdSetShadingRateImageEnableNV;
CmdSetCoverageReductionModeNVFunc							cmdSetCoverageReductionModeNV;
CmdSetRepresentativeFragmentTestEnableNVFunc				cmdSetRepresentativeFragmentTestEnableNV;
CreatePrivateDataSlotFunc									createPrivateDataSlot;
DestroyPrivateDataSlotFunc									destroyPrivateDataSlot;
SetPrivateDataFunc											setPrivateData;
GetPrivateDataFunc											getPrivateData;
CmdCopyBuffer2Func											cmdCopyBuffer2;
CmdCopyImage2Func											cmdCopyImage2;
CmdBlitImage2Func											cmdBlitImage2;
CmdCopyBufferToImage2Func									cmdCopyBufferToImage2;
CmdCopyImageToBuffer2Func									cmdCopyImageToBuffer2;
CmdResolveImage2Func										cmdResolveImage2;
CmdSetFragmentShadingRateKHRFunc							cmdSetFragmentShadingRateKHR;
CmdSetFragmentShadingRateEnumNVFunc							cmdSetFragmentShadingRateEnumNV;
GetAccelerationStructureBuildSizesKHRFunc					getAccelerationStructureBuildSizesKHR;
CmdSetVertexInputEXTFunc									cmdSetVertexInputEXT;
CmdSetColorWriteEnableEXTFunc								cmdSetColorWriteEnableEXT;
CmdSetEvent2Func											cmdSetEvent2;
CmdResetEvent2Func											cmdResetEvent2;
CmdWaitEvents2Func											cmdWaitEvents2;
CmdPipelineBarrier2Func										cmdPipelineBarrier2;
QueueSubmit2Func											queueSubmit2;
CmdWriteTimestamp2Func										cmdWriteTimestamp2;
CmdWriteBufferMarker2AMDFunc								cmdWriteBufferMarker2AMD;
GetQueueCheckpointData2NVFunc								getQueueCheckpointData2NV;
CopyMemoryToImageEXTFunc									copyMemoryToImageEXT;
CopyImageToMemoryEXTFunc									copyImageToMemoryEXT;
CopyImageToImageEXTFunc										copyImageToImageEXT;
TransitionImageLayoutEXTFunc								transitionImageLayoutEXT;
CreateVideoSessionKHRFunc									createVideoSessionKHR;
DestroyVideoSessionKHRFunc									destroyVideoSessionKHR;
CreateVideoSessionParametersKHRFunc							createVideoSessionParametersKHR;
UpdateVideoSessionParametersKHRFunc							updateVideoSessionParametersKHR;
GetEncodedVideoSessionParametersKHRFunc						getEncodedVideoSessionParametersKHR;
DestroyVideoSessionParametersKHRFunc						destroyVideoSessionParametersKHR;
GetVideoSessionMemoryRequirementsKHRFunc					getVideoSessionMemoryRequirementsKHR;
BindVideoSessionMemoryKHRFunc								bindVideoSessionMemoryKHR;
CmdDecodeVideoKHRFunc										cmdDecodeVideoKHR;
CmdBeginVideoCodingKHRFunc									cmdBeginVideoCodingKHR;
CmdControlVideoCodingKHRFunc								cmdControlVideoCodingKHR;
CmdEndVideoCodingKHRFunc									cmdEndVideoCodingKHR;
CmdEncodeVideoKHRFunc										cmdEncodeVideoKHR;
CmdDecompressMemoryNVFunc									cmdDecompressMemoryNV;
CmdDecompressMemoryIndirectCountNVFunc						cmdDecompressMemoryIndirectCountNV;
CreateCuModuleNVXFunc										createCuModuleNVX;
CreateCuFunctionNVXFunc										createCuFunctionNVX;
DestroyCuModuleNVXFunc										destroyCuModuleNVX;
DestroyCuFunctionNVXFunc									destroyCuFunctionNVX;
CmdCuLaunchKernelNVXFunc									cmdCuLaunchKernelNVX;
GetDescriptorSetLayoutSizeEXTFunc							getDescriptorSetLayoutSizeEXT;
GetDescriptorSetLayoutBindingOffsetEXTFunc					getDescriptorSetLayoutBindingOffsetEXT;
GetDescriptorEXTFunc										getDescriptorEXT;
CmdBindDescriptorBuffersEXTFunc								cmdBindDescriptorBuffersEXT;
CmdSetDescriptorBufferOffsetsEXTFunc						cmdSetDescriptorBufferOffsetsEXT;
CmdBindDescriptorBufferEmbeddedSamplersEXTFunc				cmdBindDescriptorBufferEmbeddedSamplersEXT;
GetBufferOpaqueCaptureDescriptorDataEXTFunc					getBufferOpaqueCaptureDescriptorDataEXT;
GetImageOpaqueCaptureDescriptorDataEXTFunc					getImageOpaqueCaptureDescriptorDataEXT;
GetImageViewOpaqueCaptureDescriptorDataEXTFunc				getImageViewOpaqueCaptureDescriptorDataEXT;
GetSamplerOpaqueCaptureDescriptorDataEXTFunc				getSamplerOpaqueCaptureDescriptorDataEXT;
GetAccelerationStructureOpaqueCaptureDescriptorDataEXTFunc	getAccelerationStructureOpaqueCaptureDescriptorDataEXT;
SetDeviceMemoryPriorityEXTFunc								setDeviceMemoryPriorityEXT;
WaitForPresentKHRFunc										waitForPresentKHR;
CreateBufferCollectionFUCHSIAFunc							createBufferCollectionFUCHSIA;
SetBufferCollectionBufferConstraintsFUCHSIAFunc				setBufferCollectionBufferConstraintsFUCHSIA;
SetBufferCollectionImageConstraintsFUCHSIAFunc				setBufferCollectionImageConstraintsFUCHSIA;
DestroyBufferCollectionFUCHSIAFunc							destroyBufferCollectionFUCHSIA;
GetBufferCollectionPropertiesFUCHSIAFunc					getBufferCollectionPropertiesFUCHSIA;
CreateCudaModuleNVFunc										createCudaModuleNV;
GetCudaModuleCacheNVFunc									getCudaModuleCacheNV;
CreateCudaFunctionNVFunc									createCudaFunctionNV;
DestroyCudaModuleNVFunc										destroyCudaModuleNV;
DestroyCudaFunctionNVFunc									destroyCudaFunctionNV;
CmdCudaLaunchKernelNVFunc									cmdCudaLaunchKernelNV;
CmdBeginRenderingFunc										cmdBeginRendering;
CmdEndRenderingFunc											cmdEndRendering;
GetDescriptorSetLayoutHostMappingInfoVALVEFunc				getDescriptorSetLayoutHostMappingInfoVALVE;
GetDescriptorSetHostMappingVALVEFunc						getDescriptorSetHostMappingVALVE;
CreateMicromapEXTFunc										createMicromapEXT;
CmdBuildMicromapsEXTFunc									cmdBuildMicromapsEXT;
BuildMicromapsEXTFunc										buildMicromapsEXT;
DestroyMicromapEXTFunc										destroyMicromapEXT;
CmdCopyMicromapEXTFunc										cmdCopyMicromapEXT;
CopyMicromapEXTFunc											copyMicromapEXT;
CmdCopyMicromapToMemoryEXTFunc								cmdCopyMicromapToMemoryEXT;
CopyMicromapToMemoryEXTFunc									copyMicromapToMemoryEXT;
CmdCopyMemoryToMicromapEXTFunc								cmdCopyMemoryToMicromapEXT;
CopyMemoryToMicromapEXTFunc									copyMemoryToMicromapEXT;
CmdWriteMicromapsPropertiesEXTFunc							cmdWriteMicromapsPropertiesEXT;
WriteMicromapsPropertiesEXTFunc								writeMicromapsPropertiesEXT;
GetDeviceMicromapCompatibilityEXTFunc						getDeviceMicromapCompatibilityEXT;
GetMicromapBuildSizesEXTFunc								getMicromapBuildSizesEXT;
GetShaderModuleIdentifierEXTFunc							getShaderModuleIdentifierEXT;
GetShaderModuleCreateInfoIdentifierEXTFunc					getShaderModuleCreateInfoIdentifierEXT;
GetImageSubresourceLayout2KHRFunc							getImageSubresourceLayout2KHR;
GetPipelinePropertiesEXTFunc								getPipelinePropertiesEXT;
ExportMetalObjectsEXTFunc									exportMetalObjectsEXT;
GetFramebufferTilePropertiesQCOMFunc						getFramebufferTilePropertiesQCOM;
GetDynamicRenderingTilePropertiesQCOMFunc					getDynamicRenderingTilePropertiesQCOM;
CreateOpticalFlowSessionNVFunc								createOpticalFlowSessionNV;
DestroyOpticalFlowSessionNVFunc								destroyOpticalFlowSessionNV;
BindOpticalFlowSessionImageNVFunc							bindOpticalFlowSessionImageNV;
CmdOpticalFlowExecuteNVFunc									cmdOpticalFlowExecuteNV;
GetDeviceFaultInfoEXTFunc									getDeviceFaultInfoEXT;
CmdSetDepthBias2EXTFunc										cmdSetDepthBias2EXT;
ReleaseSwapchainImagesEXTFunc								releaseSwapchainImagesEXT;
GetDeviceImageSubresourceLayoutKHRFunc						getDeviceImageSubresourceLayoutKHR;
MapMemory2KHRFunc											mapMemory2KHR;
UnmapMemory2KHRFunc											unmapMemory2KHR;
CreateShadersEXTFunc										createShadersEXT;
DestroyShaderEXTFunc										destroyShaderEXT;
GetShaderBinaryDataEXTFunc									getShaderBinaryDataEXT;
CmdBindShadersEXTFunc										cmdBindShadersEXT;
GetScreenBufferPropertiesQNXFunc							getScreenBufferPropertiesQNX;
GetExecutionGraphPipelineScratchSizeAMDXFunc				getExecutionGraphPipelineScratchSizeAMDX;
GetExecutionGraphPipelineNodeIndexAMDXFunc					getExecutionGraphPipelineNodeIndexAMDX;
CreateExecutionGraphPipelinesAMDXFunc						createExecutionGraphPipelinesAMDX;
CmdInitializeGraphScratchMemoryAMDXFunc						cmdInitializeGraphScratchMemoryAMDX;
CmdDispatchGraphAMDXFunc									cmdDispatchGraphAMDX;
CmdDispatchGraphIndirectAMDXFunc							cmdDispatchGraphIndirectAMDX;
CmdDispatchGraphIndirectCountAMDXFunc						cmdDispatchGraphIndirectCountAMDX;
SetLatencySleepModeNVFunc									setLatencySleepModeNV;
LatencySleepNVFunc											latencySleepNV;
SetLatencyMarkerNVFunc										setLatencyMarkerNV;
GetLatencyTimingsNVFunc										getLatencyTimingsNV;
QueueNotifyOutOfBandNVFunc									queueNotifyOutOfBandNV;
