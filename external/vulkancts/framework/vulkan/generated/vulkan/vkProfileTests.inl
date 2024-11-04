/* WARNING: This is auto-generated file. Do not modify, since changes will
 * be lost! Modify the generating script instead.
 * This file was generated by /scripts/gen_framework.py
 */

tcu::TestStatus validate_roadmap_2022(Context& context)
{
	const bool checkAlways = true;
	bool oneOrMoreChecksFailed = false;
	auto pd = context.getPhysicalDevice();
	const auto &vki = context.getInstanceInterface();
	TestLog& log = context.getTestContext().getLog();

	VkPhysicalDeviceVulkan11Features vkVulkan11Features = initVulkanStructure();
	VkPhysicalDeviceVulkan12Features vkVulkan12Features = initVulkanStructure(&vkVulkan11Features);
	VkPhysicalDeviceVulkan13Features vkVulkan13Features = initVulkanStructure(&vkVulkan12Features);

	VkPhysicalDeviceFeatures2 vkFeatures2 = initVulkanStructure(&vkVulkan13Features);
	auto& vkFeatures = vkFeatures2.features;
	vki.getPhysicalDeviceFeatures2(pd, &vkFeatures2);

	VkPhysicalDeviceVulkan11Properties vkVulkan11Properties = initVulkanStructure();
	VkPhysicalDeviceVulkan12Properties vkVulkan12Properties = initVulkanStructure(&vkVulkan11Properties);
	VkPhysicalDeviceVulkan13Properties vkVulkan13Properties = initVulkanStructure(&vkVulkan12Properties);

	VkPhysicalDeviceProperties2 vkProperties2 = initVulkanStructure(&vkVulkan13Properties);
	auto& vkProperties = vkProperties2.properties;
	vki.getPhysicalDeviceProperties2(pd, &vkProperties2);

	const std::vector<FeatureEntry> featureTable {
		// vulkan10requirements
		ROADMAP_FEATURE_ITEM(vkFeatures, robustBufferAccess),

		// vulkan10requirements_roadmap2022
		ROADMAP_FEATURE_ITEM(vkFeatures, fullDrawIndexUint32),
		ROADMAP_FEATURE_ITEM(vkFeatures, imageCubeArray),
		ROADMAP_FEATURE_ITEM(vkFeatures, independentBlend),
		ROADMAP_FEATURE_ITEM(vkFeatures, sampleRateShading),
		ROADMAP_FEATURE_ITEM(vkFeatures, drawIndirectFirstInstance),
		ROADMAP_FEATURE_ITEM(vkFeatures, depthClamp),
		ROADMAP_FEATURE_ITEM(vkFeatures, depthBiasClamp),
		ROADMAP_FEATURE_ITEM(vkFeatures, samplerAnisotropy),
		ROADMAP_FEATURE_ITEM(vkFeatures, occlusionQueryPrecise),
		ROADMAP_FEATURE_ITEM(vkFeatures, fragmentStoresAndAtomics),
		ROADMAP_FEATURE_ITEM(vkFeatures, shaderStorageImageExtendedFormats),
		ROADMAP_FEATURE_ITEM(vkFeatures, shaderUniformBufferArrayDynamicIndexing),
		ROADMAP_FEATURE_ITEM(vkFeatures, shaderSampledImageArrayDynamicIndexing),
		ROADMAP_FEATURE_ITEM(vkFeatures, shaderStorageBufferArrayDynamicIndexing),
		ROADMAP_FEATURE_ITEM(vkFeatures, shaderStorageImageArrayDynamicIndexing),

		// vulkan11requirements
		ROADMAP_FEATURE_ITEM(vkVulkan11Features, multiview),

		// vulkan11requirements_roadmap2022
		ROADMAP_FEATURE_ITEM(vkVulkan11Features, samplerYcbcrConversion),

		// vulkan12requirements
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, uniformBufferStandardLayout),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, subgroupBroadcastDynamicId),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, imagelessFramebuffer),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, separateDepthStencilLayouts),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, hostQueryReset),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, timelineSemaphore),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, shaderSubgroupExtendedTypes),

		// vulkan12requirements_roadmap2022
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, samplerMirrorClampToEdge),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, descriptorIndexing),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, shaderUniformTexelBufferArrayDynamicIndexing),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, shaderStorageTexelBufferArrayDynamicIndexing),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, shaderUniformBufferArrayNonUniformIndexing),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, shaderSampledImageArrayNonUniformIndexing),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, shaderStorageBufferArrayNonUniformIndexing),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, shaderStorageImageArrayNonUniformIndexing),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, shaderUniformTexelBufferArrayNonUniformIndexing),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, shaderStorageTexelBufferArrayNonUniformIndexing),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, descriptorBindingSampledImageUpdateAfterBind),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, descriptorBindingStorageImageUpdateAfterBind),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, descriptorBindingStorageBufferUpdateAfterBind),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, descriptorBindingUniformTexelBufferUpdateAfterBind),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, descriptorBindingStorageTexelBufferUpdateAfterBind),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, descriptorBindingUpdateUnusedWhilePending),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, descriptorBindingPartiallyBound),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, descriptorBindingVariableDescriptorCount),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, runtimeDescriptorArray),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, scalarBlockLayout),

		// vulkan13requirements
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, vulkanMemoryModel),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, vulkanMemoryModelDeviceScope),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, bufferDeviceAddress),

		ROADMAP_FEATURE_ITEM(vkVulkan13Features, robustImageAccess),
		ROADMAP_FEATURE_ITEM(vkVulkan13Features, shaderTerminateInvocation),
		ROADMAP_FEATURE_ITEM(vkVulkan13Features, shaderZeroInitializeWorkgroupMemory),
		ROADMAP_FEATURE_ITEM(vkVulkan13Features, synchronization2),
		ROADMAP_FEATURE_ITEM(vkVulkan13Features, shaderIntegerDotProduct),
		ROADMAP_FEATURE_ITEM(vkVulkan13Features, maintenance4),
		ROADMAP_FEATURE_ITEM(vkVulkan13Features, pipelineCreationCacheControl),
		ROADMAP_FEATURE_ITEM(vkVulkan13Features, subgroupSizeControl),
		ROADMAP_FEATURE_ITEM(vkVulkan13Features, computeFullSubgroups),
		ROADMAP_FEATURE_ITEM(vkVulkan13Features, shaderDemoteToHelperInvocation),
		ROADMAP_FEATURE_ITEM(vkVulkan13Features, inlineUniformBlock),
		ROADMAP_FEATURE_ITEM(vkVulkan13Features, dynamicRendering),

		// vulkan13requirements_roadmap2022
		ROADMAP_FEATURE_ITEM(vkVulkan13Features, descriptorBindingInlineUniformBlockUpdateAfterBind),

		// vulkan10optionals_roadmap2022
		ROADMAP_FEATURE_ITEM(vkFeatures, largePoints),
		ROADMAP_FEATURE_ITEM(vkFeatures, wideLines),
	};
	for (const auto &testedFeature : featureTable)
	{
	    if (!testedFeature.fieldPtr[0])
	    {
	        log << TestLog::Message
	            << "Feature " << testedFeature.fieldName << " is not supported"
	            << TestLog::EndMessage;
	        oneOrMoreChecksFailed = true;
	    }
	}

	const std::vector<FeatureLimitTableItem> propertyTable {
		// vulkan10requirements_roadmap2022
		{ PN(checkAlways), PN(vkProperties.limits.maxImageDimension1D), LIM_MIN_UINT32(8192) },
		{ PN(checkAlways), PN(vkProperties.limits.maxImageDimension2D), LIM_MIN_UINT32(8192) },
		{ PN(checkAlways), PN(vkProperties.limits.maxImageDimensionCube), LIM_MIN_UINT32(8192) },
		{ PN(checkAlways), PN(vkProperties.limits.maxImageArrayLayers), LIM_MIN_UINT32(2048) },
		{ PN(checkAlways), PN(vkProperties.limits.maxUniformBufferRange), LIM_MIN_UINT32(65536) },
		{ PN(checkAlways), PN(vkProperties.limits.bufferImageGranularity), LIM_MAX_UINT32(4096) },
		{ PN(checkAlways), PN(vkProperties.limits.maxPerStageDescriptorSamplers), LIM_MIN_UINT32(64) },
		{ PN(checkAlways), PN(vkProperties.limits.maxPerStageDescriptorUniformBuffers), LIM_MIN_UINT32(15) },
		{ PN(checkAlways), PN(vkProperties.limits.maxPerStageDescriptorStorageBuffers), LIM_MIN_UINT32(30) },
		{ PN(checkAlways), PN(vkProperties.limits.maxPerStageDescriptorSampledImages), LIM_MIN_UINT32(200) },
		{ PN(checkAlways), PN(vkProperties.limits.maxPerStageDescriptorStorageImages), LIM_MIN_UINT32(16) },
		{ PN(checkAlways), PN(vkProperties.limits.maxPerStageResources), LIM_MIN_UINT32(200) },
		{ PN(checkAlways), PN(vkProperties.limits.maxDescriptorSetSamplers), LIM_MIN_UINT32(576) },
		{ PN(checkAlways), PN(vkProperties.limits.maxDescriptorSetUniformBuffers), LIM_MIN_UINT32(90) },
		{ PN(checkAlways), PN(vkProperties.limits.maxDescriptorSetStorageBuffers), LIM_MIN_UINT32(96) },
		{ PN(checkAlways), PN(vkProperties.limits.maxDescriptorSetSampledImages), LIM_MIN_UINT32(1800) },
		{ PN(checkAlways), PN(vkProperties.limits.maxDescriptorSetStorageImages), LIM_MIN_UINT32(144) },
		{ PN(checkAlways), PN(vkProperties.limits.maxFragmentCombinedOutputResources), LIM_MIN_UINT32(16) },
		{ PN(checkAlways), PN(vkProperties.limits.maxComputeWorkGroupInvocations), LIM_MIN_UINT32(256) },
		{ PN(checkAlways), PN(vkProperties.limits.maxComputeWorkGroupSize[0]), LIM_MIN_UINT32(256) },
		{ PN(checkAlways), PN(vkProperties.limits.maxComputeWorkGroupSize[1]), LIM_MIN_UINT32(256) },
		{ PN(checkAlways), PN(vkProperties.limits.maxComputeWorkGroupSize[2]), LIM_MIN_UINT32(64) },
		{ PN(checkAlways), PN(vkProperties.limits.subTexelPrecisionBits), LIM_MIN_UINT32(8) },
		{ PN(checkAlways), PN(vkProperties.limits.mipmapPrecisionBits), LIM_MIN_UINT32(6) },
		{ PN(checkAlways), PN(vkProperties.limits.maxSamplerLodBias), LIM_MIN_FLOAT(14) },
		{ PN(checkAlways), PN(vkProperties.limits.standardSampleLocations), LIM_MIN_UINT32(true) },
		{ PN(checkAlways), PN(vkProperties.limits.maxColorAttachments), LIM_MIN_UINT32(7) },

		// vulkan11requirements
		{ PN(checkAlways), PN(vkVulkan11Properties.maxMultiviewViewCount), LIM_MIN_UINT32(6) },
		{ PN(checkAlways), PN(vkVulkan11Properties.maxMultiviewInstanceIndex), LIM_MIN_UINT32(134217727) },

		// vulkan11requirements_roadmap2022
		{ PN(checkAlways), PN(vkVulkan11Properties.subgroupSize), LIM_MIN_UINT32(4) },
		{ PN(checkAlways), PN(vkVulkan11Properties.subgroupSupportedStages), LIM_MIN_UINT32(VK_SHADER_STAGE_COMPUTE_BIT|VK_SHADER_STAGE_FRAGMENT_BIT) },
		{ PN(checkAlways), PN(vkVulkan11Properties.subgroupSupportedOperations), LIM_MIN_UINT32(VK_SUBGROUP_FEATURE_BASIC_BIT|VK_SUBGROUP_FEATURE_VOTE_BIT|VK_SUBGROUP_FEATURE_ARITHMETIC_BIT|VK_SUBGROUP_FEATURE_BALLOT_BIT|VK_SUBGROUP_FEATURE_SHUFFLE_BIT|VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT|VK_SUBGROUP_FEATURE_QUAD_BIT) },

		// vulkan12requirements
		{ PN(checkAlways), PN(vkVulkan12Properties.maxTimelineSemaphoreValueDifference), LIM_MIN_UINT32(2147483647) },

		// vulkan12requirements_roadmap2022
		{ PN(checkAlways), PN(vkVulkan12Properties.shaderSignedZeroInfNanPreserveFloat16), LIM_MIN_UINT32(true) },
		{ PN(checkAlways), PN(vkVulkan12Properties.shaderSignedZeroInfNanPreserveFloat32), LIM_MIN_UINT32(true) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxPerStageDescriptorUpdateAfterBindSamplers), LIM_MIN_UINT32(500000) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxPerStageDescriptorUpdateAfterBindUniformBuffers), LIM_MIN_UINT32(12) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxPerStageDescriptorUpdateAfterBindStorageBuffers), LIM_MIN_UINT32(500000) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxPerStageDescriptorUpdateAfterBindSampledImages), LIM_MIN_UINT32(500000) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxPerStageDescriptorUpdateAfterBindStorageImages), LIM_MIN_UINT32(500000) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxPerStageDescriptorUpdateAfterBindInputAttachments), LIM_MIN_UINT32(7) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxPerStageUpdateAfterBindResources), LIM_MIN_UINT32(500000) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxDescriptorSetUpdateAfterBindSamplers), LIM_MIN_UINT32(500000) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxDescriptorSetUpdateAfterBindUniformBuffers), LIM_MIN_UINT32(72) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic), LIM_MIN_UINT32(8) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxDescriptorSetUpdateAfterBindStorageBuffers), LIM_MIN_UINT32(500000) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic), LIM_MIN_UINT32(4) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxDescriptorSetUpdateAfterBindSampledImages), LIM_MIN_UINT32(500000) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxDescriptorSetUpdateAfterBindStorageImages), LIM_MIN_UINT32(500000) },
		{ PN(checkAlways), PN(vkVulkan12Properties.maxDescriptorSetUpdateAfterBindInputAttachments), LIM_MIN_UINT32(7) },

		// vulkan13requirements
		{ PN(checkAlways), PN(vkVulkan13Properties.maxBufferSize), LIM_MIN_DEVSIZE(1073741824) },
		{ PN(checkAlways), PN(vkVulkan13Properties.maxInlineUniformBlockSize), LIM_MIN_UINT32(256) },
		{ PN(checkAlways), PN(vkVulkan13Properties.maxPerStageDescriptorInlineUniformBlocks), LIM_MIN_UINT32(4) },
		{ PN(checkAlways), PN(vkVulkan13Properties.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks), LIM_MIN_UINT32(4) },
		{ PN(checkAlways), PN(vkVulkan13Properties.maxDescriptorSetInlineUniformBlocks), LIM_MIN_UINT32(4) },
		{ PN(checkAlways), PN(vkVulkan13Properties.maxDescriptorSetUpdateAfterBindInlineUniformBlocks), LIM_MIN_UINT32(4) },
		{ PN(checkAlways), PN(vkVulkan13Properties.maxInlineUniformTotalSize), LIM_MIN_UINT32(256) },

		// vulkan10optionals_roadmap2022
		{ PN(checkAlways), PN(vkProperties.limits.pointSizeGranularity), LIM_MAX_FLOAT(0.125) },
		{ PN(checkAlways), PN(vkProperties.limits.lineWidthGranularity), LIM_MAX_FLOAT(0.5) },
	};
	for (const auto& testedProperty : propertyTable)
	    oneOrMoreChecksFailed |= !validateLimit(testedProperty, log);

	std::vector<std::string> extensionList {
		"VK_KHR_global_priority"
	};
	const auto deviceExtensions = enumerateDeviceExtensionProperties(vki, pd, nullptr);
	for (const auto& testedExtension : extensionList)
	{
	    if (isExtensionStructSupported(deviceExtensions, RequiredExtension(testedExtension)) ||
	        context.isInstanceFunctionalitySupported(testedExtension))
	        continue;
	    log << TestLog::Message
	        << testedExtension << " is not supported"
	        << TestLog::EndMessage;
	    oneOrMoreChecksFailed = true;
	}

	if (oneOrMoreChecksFailed)
	    TCU_THROW(NotSupportedError, "Profile not supported");
	return tcu::TestStatus::pass("Profile supported");
}

tcu::TestStatus validate_roadmap_2024(Context& context)
{
	const bool checkAlways = true;
	bool oneOrMoreChecksFailed = false;
	auto pd = context.getPhysicalDevice();
	const auto &vki = context.getInstanceInterface();
	TestLog& log = context.getTestContext().getLog();

	VkPhysicalDeviceVulkan11Features vkVulkan11Features = initVulkanStructure();
	VkPhysicalDeviceVulkan12Features vkVulkan12Features = initVulkanStructure(&vkVulkan11Features);

	VkPhysicalDeviceFeatures2 vkFeatures2 = initVulkanStructure(&vkVulkan12Features);
	auto& vkFeatures = vkFeatures2.features;
	vki.getPhysicalDeviceFeatures2(pd, &vkFeatures2);

	VkPhysicalDeviceVulkan12Properties vkVulkan12Properties = initVulkanStructure();

	VkPhysicalDeviceProperties2 vkProperties2 = initVulkanStructure(&vkVulkan12Properties);
	auto& vkProperties = vkProperties2.properties;
	vki.getPhysicalDeviceProperties2(pd, &vkProperties2);

	const std::vector<FeatureEntry> featureTable {
		// vulkan10requirements_roadmap2024
		ROADMAP_FEATURE_ITEM(vkFeatures, multiDrawIndirect),
		ROADMAP_FEATURE_ITEM(vkFeatures, shaderInt16),
		ROADMAP_FEATURE_ITEM(vkFeatures, shaderImageGatherExtended),

		// vulkan11requirements_roadmap2024
		ROADMAP_FEATURE_ITEM(vkVulkan11Features, shaderDrawParameters),
		ROADMAP_FEATURE_ITEM(vkVulkan11Features, storageBuffer16BitAccess),

		// vulkan12requirements_roadmap2024
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, shaderInt8),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, shaderFloat16),
		ROADMAP_FEATURE_ITEM(vkVulkan12Features, storageBuffer8BitAccess),
	};
	for (const auto &testedFeature : featureTable)
	{
	    if (!testedFeature.fieldPtr[0])
	    {
	        log << TestLog::Message
	            << "Feature " << testedFeature.fieldName << " is not supported"
	            << TestLog::EndMessage;
	        oneOrMoreChecksFailed = true;
	    }
	}

	const std::vector<FeatureLimitTableItem> propertyTable {
		// vulkan10requirements_roadmap2024
		{ PN(checkAlways), PN(vkProperties.limits.timestampComputeAndGraphics), LIM_MIN_UINT32(true) },
		{ PN(checkAlways), PN(vkProperties.limits.maxColorAttachments), LIM_MIN_UINT32(8) },
		{ PN(checkAlways), PN(vkProperties.limits.maxBoundDescriptorSets), LIM_MIN_UINT32(7) },

		// vulkan12requirements_roadmap2024
		{ PN(checkAlways), PN(vkVulkan12Properties.shaderRoundingModeRTEFloat16), LIM_MIN_UINT32(true) },
		{ PN(checkAlways), PN(vkVulkan12Properties.shaderRoundingModeRTEFloat32), LIM_MIN_UINT32(true) },
	};
	for (const auto& testedProperty : propertyTable)
	    oneOrMoreChecksFailed |= !validateLimit(testedProperty, log);

	std::vector<std::string> extensionList {
		"VK_KHR_dynamic_rendering_local_read",
		"VK_KHR_load_store_op_none",
		"VK_KHR_shader_quad_control",
		"VK_KHR_shader_maximal_reconvergence",
		"VK_KHR_shader_subgroup_uniform_control_flow",
		"VK_KHR_shader_subgroup_rotate",
		"VK_KHR_shader_float_controls2",
		"VK_KHR_shader_expect_assume",
		"VK_KHR_line_rasterization",
		"VK_KHR_vertex_attribute_divisor",
		"VK_KHR_index_type_uint8",
		"VK_KHR_map_memory2",
		"VK_KHR_maintenance5",
		"VK_KHR_push_descriptor"
	};
	const auto deviceExtensions = enumerateDeviceExtensionProperties(vki, pd, nullptr);
	for (const auto& testedExtension : extensionList)
	{
	    if (isExtensionStructSupported(deviceExtensions, RequiredExtension(testedExtension)) ||
	        context.isInstanceFunctionalitySupported(testedExtension))
	        continue;
	    log << TestLog::Message
	        << testedExtension << " is not supported"
	        << TestLog::EndMessage;
	    oneOrMoreChecksFailed = true;
	}

	if (oneOrMoreChecksFailed)
	    TCU_THROW(NotSupportedError, "Profile not supported");
	return tcu::TestStatus::pass("Profile supported");
}

static const std::vector<ProfileEntry> profileEntries {
	{ "roadmap_2022", checkApiVersionSupport<1, 3>, validate_roadmap_2022 },
	{ "roadmap_2024", checkApiVersionSupport<1, 3>, validate_roadmap_2024 },
};