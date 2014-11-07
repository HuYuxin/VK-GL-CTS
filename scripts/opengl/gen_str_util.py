# -*- coding: utf-8 -*-

import os
import string

from src_util import *

# Bitfield mapping
BITFIELD_GROUPS = [
	# ClearBufferMask
	("BufferMask",		["DEPTH_BUFFER_BIT", "STENCIL_BUFFER_BIT", "COLOR_BUFFER_BIT"]),
	# MapBufferUsageMask
	("BufferMapFlags",	[
		"MAP_READ_BIT",
		"MAP_WRITE_BIT",
		"MAP_INVALIDATE_RANGE_BIT",
		"MAP_INVALIDATE_BUFFER_BIT",
		"MAP_FLUSH_EXPLICIT_BIT",
		"MAP_UNSYNCHRONIZED_BIT"
		]),
	# MemoryBarrierMask
	("MemoryBarrierFlags", [
		"VERTEX_ATTRIB_ARRAY_BARRIER_BIT",
		"ELEMENT_ARRAY_BARRIER_BIT",
		"UNIFORM_BARRIER_BIT",
		"TEXTURE_FETCH_BARRIER_BIT",
		"SHADER_IMAGE_ACCESS_BARRIER_BIT",
		"COMMAND_BARRIER_BIT",
		"PIXEL_BUFFER_BARRIER_BIT",
		"TEXTURE_UPDATE_BARRIER_BIT",
		"BUFFER_UPDATE_BARRIER_BIT",
		"FRAMEBUFFER_BARRIER_BIT",
		"TRANSFORM_FEEDBACK_BARRIER_BIT",
		"ATOMIC_COUNTER_BARRIER_BIT"
		])
]

# Enum mapping
ENUM_GROUPS = [
	# Common enums

	# ErrorCode
	("Error",				["NO_ERROR", "INVALID_ENUM", "INVALID_VALUE", "INVALID_OPERATION", "OUT_OF_MEMORY",
							 "INVALID_FRAMEBUFFER_OPERATION"]),
	# PixelType, partially
	("Type", [
		# GLES2 types
		"BYTE",
		"UNSIGNED_BYTE",
		"SHORT",
		"UNSIGNED_SHORT",
		"INT",
		"UNSIGNED_INT",
		"FLOAT",
		"FIXED",
		"UNSIGNED_SHORT_5_6_5",
		"UNSIGNED_SHORT_4_4_4_4",
		"UNSIGNED_SHORT_5_5_5_1",

		# GLES3 types
		"HALF_FLOAT",
		"INT_2_10_10_10_REV",
		"UNSIGNED_INT_2_10_10_10_REV",
		"UNSIGNED_INT_10F_11F_11F_REV",
		"UNSIGNED_INT_5_9_9_9_REV",
		"UNSIGNED_INT_24_8",
		"FLOAT_32_UNSIGNED_INT_24_8_REV",
		"SIGNED_NORMALIZED",
		"UNSIGNED_NORMALIZED",

		# Extension types
		"HALF_FLOAT_OES",
		]),

	# GetPName, also GettableState below
	("ParamQuery", [
		# Generic
		"LINE_WIDTH",
		"ALIASED_POINT_SIZE_RANGE",
		"ALIASED_LINE_WIDTH_RANGE",
		"CULL_FACE_MODE",
		"FRONT_FACE",
		"DEPTH_RANGE",
		"DEPTH_WRITEMASK",
		"DEPTH_CLEAR_VALUE",
		"DEPTH_FUNC",
		"STENCIL_CLEAR_VALUE",
		"STENCIL_FUNC",
		"STENCIL_FAIL",
		"STENCIL_PASS_DEPTH_FAIL",
		"STENCIL_PASS_DEPTH_PASS",
		"STENCIL_REF",
		"STENCIL_VALUE_MASK",
		"STENCIL_WRITEMASK",
		"STENCIL_BACK_FUNC",
		"STENCIL_BACK_FAIL",
		"STENCIL_BACK_PASS_DEPTH_FAIL",
		"STENCIL_BACK_PASS_DEPTH_PASS",
		"STENCIL_BACK_REF",
		"STENCIL_BACK_VALUE_MASK",
		"STENCIL_BACK_WRITEMASK",
		"VIEWPORT",
		"SCISSOR_BOX",
		"SCISSOR_TEST",
		"COLOR_CLEAR_VALUE",
		"COLOR_WRITEMASK",
		"UNPACK_ALIGNMENT",
		"PACK_ALIGNMENT",
		"MAX_TEXTURE_SIZE",
		"MAX_VIEWPORT_DIMS",
		"SUBPIXEL_BITS",
		"RED_BITS",
		"GREEN_BITS",
		"BLUE_BITS",
		"ALPHA_BITS",
		"DEPTH_BITS",
		"STENCIL_BITS",
		"POLYGON_OFFSET_UNITS",
		"POLYGON_OFFSET_FILL",
        "POLYGON_OFFSET_FACTOR",
		"TEXTURE_BINDING_2D",
		"SAMPLE_BUFFERS",
		"SAMPLES",
		"SAMPLE_COVERAGE_VALUE",
		"SAMPLE_COVERAGE_INVERT",

		"MAX_CUBE_MAP_TEXTURE_SIZE",
		"MAX_RENDERBUFFER_SIZE",

		# Program-related
		"MAX_VERTEX_ATTRIBS",
		"MAX_VERTEX_UNIFORM_VECTORS",
		"MAX_VARYING_VECTORS",
		"MAX_COMBINED_TEXTURE_IMAGE_UNITS",
		"MAX_VERTEX_TEXTURE_IMAGE_UNITS",
		"MAX_TEXTURE_IMAGE_UNITS",
		"MAX_FRAGMENT_UNIFORM_VECTORS"
		]),

	# *missing*
	# Program query
	("ProgramParam", [
		"ACTIVE_ATTRIBUTES",
		"ACTIVE_ATTRIBUTE_MAX_LENGTH",
		"ACTIVE_UNIFORMS",
		"ACTIVE_UNIFORM_BLOCKS",
		"ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH",
		"ACTIVE_UNIFORM_MAX_LENGTH",
		"ATTACHED_SHADERS",
		"DELETE_STATUS",
		"INFO_LOG_LENGTH",
		"LINK_STATUS",
		"PROGRAM_BINARY_RETRIEVABLE_HINT",
		"TRANSFORM_FEEDBACK_BUFFER_MODE",
		"TRANSFORM_FEEDBACK_VARYINGS",
		"TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH",
		"VALIDATE_STATUS",
		"GEOMETRY_INPUT_TYPE",
		"GEOMETRY_OUTPUT_TYPE",
		"GEOMETRY_VERTICES_OUT",
		"GEOMETRY_SHADER_INVOCATIONS",
		]),

	# *missing*
	# Uniform query
	("UniformParam", [
		"UNIFORM_TYPE",
		"UNIFORM_SIZE",
		"UNIFORM_NAME_LENGTH",
		"UNIFORM_BLOCK_INDEX",
		"UNIFORM_OFFSET",
		"UNIFORM_ARRAY_STRIDE",
		"UNIFORM_MATRIX_STRIDE",
		"UNIFORM_IS_ROW_MAJOR"
		]),

	# *missing*
	# Framebuffers
	("FramebufferAttachment",			["COLOR_ATTACHMENT0", "COLOR_ATTACHMENT1", "COLOR_ATTACHMENT2", "COLOR_ATTACHMENT3",
										 "COLOR_ATTACHMENT4", "COLOR_ATTACHMENT5", "COLOR_ATTACHMENT6", "COLOR_ATTACHMENT7",
										 "COLOR_ATTACHMENT8", "COLOR_ATTACHMENT9", "COLOR_ATTACHMENT10", "COLOR_ATTACHMENT11",
										 "COLOR_ATTACHMENT12", "COLOR_ATTACHMENT13", "COLOR_ATTACHMENT14", "COLOR_ATTACHMENT15",
										 "DEPTH_ATTACHMENT", "STENCIL_ATTACHMENT", "DEPTH_STENCIL_ATTACHMENT",
										 "BACK", "FRONT_LEFT", "FRONT_RIGHT", "BACK_LEFT", "BACK_RIGHT",
										 "DEPTH", "STENCIL"]),
	# *missing*
	("FramebufferAttachmentParameter",	["FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE", "FRAMEBUFFER_ATTACHMENT_OBJECT_NAME",
										 "FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL", "FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE",
										 "FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER", "FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE",
										 "FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING", "FRAMEBUFFER_ATTACHMENT_RED_SIZE",
										 "FRAMEBUFFER_ATTACHMENT_GREEN_SIZE", "FRAMEBUFFER_ATTACHMENT_BLUE_SIZE",
										 "FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE", "FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE",
										 "FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE", "FRAMEBUFFER_ATTACHMENT_LAYERED"]),
	("FramebufferTarget",				["FRAMEBUFFER", "RENDERBUFFER", "DRAW_FRAMEBUFFER", "READ_FRAMEBUFFER"]),
	("FramebufferStatus",				["FRAMEBUFFER_COMPLETE", "FRAMEBUFFER_INCOMPLETE_ATTACHMENT", "FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT",
										 "FRAMEBUFFER_INCOMPLETE_DIMENSIONS", "FRAMEBUFFER_UNSUPPORTED", "FRAMEBUFFER_INCOMPLETE_MULTISAMPLE",
										 "FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS"]),
	("FramebufferAttachmentType",		["NONE", "FRAMEBUFFER_DEFAULT", "TEXTURE", "RENDERBUFFER"]),
	("FramebufferColorEncoding",		["LINEAR", "SRGB"]),

	("FramebufferParameter", [
		"FRAMEBUFFER_DEFAULT_WIDTH",
		"FRAMEBUFFER_DEFAULT_HEIGHT",
		"FRAMEBUFFER_DEFAULT_SAMPLES",
		"FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS",
		"FRAMEBUFFER_DEFAULT_LAYERS",
		]),

	# Renderbuffers
	("RenderbufferParameter",			["RENDERBUFFER_WIDTH", "RENDERBUFFER_HEIGHT", "RENDERBUFFER_INTERNAL_FORMAT", "RENDERBUFFER_RED_SIZE",
										"RENDERBUFFER_GREEN_SIZE", "RENDERBUFFER_BLUE_SIZE", "RENDERBUFFER_ALPHA_SIZE", "RENDERBUFFER_DEPTH_SIZE",
										"RENDERBUFFER_STENCIL_SIZE", "RENDERBUFFER_SAMPLES"]),

	# Primitives
	("PrimitiveType",		["POINTS", "LINES", "LINE_STRIP", "LINE_LOOP", "TRIANGLES", "TRIANGLE_STRIP", "TRIANGLE_FAN", "LINES_ADJACENCY", "LINE_STRIP_ADJACENCY", "TRIANGLES_ADJACENCY", "TRIANGLE_STRIP_ADJACENCY"]),

	# Blending
	("BlendFactor",			["ZERO", "ONE", "SRC_ALPHA_SATURATE",
							 "SRC_COLOR", "ONE_MINUS_SRC_COLOR", "SRC_ALPHA", "ONE_MINUS_SRC_ALPHA",
							 "SRC1_COLOR", "ONE_MINUS_SRC1_COLOR", "SRC1_ALPHA", "ONE_MINUS_SRC1_ALPHA",
							 "DST_COLOR", "ONE_MINUS_DST_COLOR", "DST_ALPHA", "ONE_MINUS_DST_ALPHA",
							 "CONSTANT_COLOR", "ONE_MINUS_CONSTANT_COLOR", "CONSTANT_ALPHA", "ONE_MINUS_CONSTANT_ALPHA"]),
	("BlendEquation",		["FUNC_ADD", "FUNC_SUBTRACT", "FUNC_REVERSE_SUBTRACT", "MIN", "MAX"]),

	# Buffer Objects
	("BufferTarget",		[
		"ARRAY_BUFFER",
		"ELEMENT_ARRAY_BUFFER",
		"COPY_READ_BUFFER",
		"COPY_WRITE_BUFFER",
		"PIXEL_PACK_BUFFER",
		"PIXEL_UNPACK_BUFFER",
		"TRANSFORM_FEEDBACK_BUFFER",
		"UNIFORM_BUFFER",
		"DRAW_INDIRECT_BUFFER",
		"SHADER_STORAGE_BUFFER",
		"TEXTURE_BUFFER"
		]),
	("BufferBinding",		["ARRAY_BUFFER_BINDING", "ELEMENT_ARRAY_BUFFER_BINDING"]),
	("Usage",				[
		"STREAM_DRAW",
		"STREAM_READ",
		"STREAM_COPY",
		"STATIC_DRAW",
		"STATIC_READ",
		"STATIC_COPY",
		"DYNAMIC_DRAW",
		"DYNAMIC_READ",
		"DYNAMIC_COPY"]),
	("BufferQuery",			["BUFFER_SIZE", "BUFFER_USAGE", "BUFFER_ACCESS_FLAGS", "BUFFER_MAPPED", "BUFFER_MAP_OFFSET", "BUFFER_MAP_LENGTH"]),

	# Culling
	("Face",				["FRONT", "BACK", "FRONT_AND_BACK"]),

	# Comparison function
	("CompareFunc",			["NEVER", "LESS", "LEQUAL", "GREATER", "EQUAL", "NOTEQUAL", "GEQUAL", "ALWAYS"]),

	# Enable-disable bit
	("EnableCap",			["TEXTURE_2D", "CULL_FACE", "BLEND", "DITHER", "STENCIL_TEST", "DEPTH_TEST", "SCISSOR_TEST",
							 "POLYGON_OFFSET_FILL", "SAMPLE_ALPHA_TO_COVERAGE", "SAMPLE_COVERAGE",
							 "PRIMITIVE_RESTART_FIXED_INDEX", "RASTERIZER_DISCARD",
							 "FRAMEBUFFER_SRGB", "SAMPLE_SHADING", "DEPTH_CLAMP",
							 "PRIMITIVE_RESTART"]),

	# Polygon winding
	("Winding",				["CW", "CCW"]),

	# Hints
	("HintMode",			["DONT_CARE", "FASTEST", "NICEST"]),
	("Hint",				["GENERATE_MIPMAP_HINT"]),

	# Stencil ops
	("StencilOp",			["ZERO", "KEEP", "REPLACE", "INCR", "DECR", "INVERT", "INCR_WRAP", "DECR_WRAP"]),

	# Shader type
	("ShaderType",			["VERTEX_SHADER", "FRAGMENT_SHADER"]),

	# Buffers
	("Buffer",				["COLOR", "DEPTH", "STENCIL", "DEPTH_STENCIL"]),

	# Invalidate buffer target
	("InvalidateAttachment",["COLOR", "DEPTH", "STENCIL",
							 "COLOR_ATTACHMENT0",
							 "COLOR_ATTACHMENT1",
							 "COLOR_ATTACHMENT2",
							 "COLOR_ATTACHMENT3",
							 "COLOR_ATTACHMENT4",
							 "COLOR_ATTACHMENT5",
							 "COLOR_ATTACHMENT6",
							 "COLOR_ATTACHMENT7",
							 "DEPTH_ATTACHMENT",
							 "STENCIL_ATTACHMENT",
							 "DEPTH_STENCIL_ATTACHMENT"]),

	# Draw/ReadBuffer attachment
	("DrawReadBuffer",		["COLOR", "DEPTH", "STENCIL", "BACK", "NONE",
							 "COLOR_ATTACHMENT0",
							 "COLOR_ATTACHMENT1",
							 "COLOR_ATTACHMENT2",
							 "COLOR_ATTACHMENT3",
							 "COLOR_ATTACHMENT4",
							 "COLOR_ATTACHMENT5",
							 "COLOR_ATTACHMENT6",
							 "COLOR_ATTACHMENT7",
							 "DEPTH_ATTACHMENT",
							 "STENCIL_ATTACHMENT",
							 "DEPTH_STENCIL_ATTACHMENT"]),

	# Textures
	("TextureTarget",		["TEXTURE_1D",
							 "TEXTURE_2D", "TEXTURE_CUBE_MAP",
							 "TEXTURE_CUBE_MAP_POSITIVE_X", "TEXTURE_CUBE_MAP_NEGATIVE_X",
							 "TEXTURE_CUBE_MAP_POSITIVE_Y", "TEXTURE_CUBE_MAP_NEGATIVE_Y",
							 "TEXTURE_CUBE_MAP_POSITIVE_Z", "TEXTURE_CUBE_MAP_NEGATIVE_Z",
							 "TEXTURE_3D", "TEXTURE_2D_ARRAY", "TEXTURE_2D_MULTISAMPLE",
							 "TEXTURE_2D_MULTISAMPLE_ARRAY",
							 "TEXTURE_BUFFER",
							 "TEXTURE_CUBE_MAP_ARRAY"]),
	("TextureParameter", [
		"TEXTURE_WRAP_S",
		"TEXTURE_WRAP_T",
		"TEXTURE_WRAP_R",
		"TEXTURE_BASE_LEVEL",
		"TEXTURE_MAX_LEVEL",
		"TEXTURE_COMPARE_MODE",
		"TEXTURE_COMPARE_FUNC",
		"TEXTURE_MAX_LOD",
		"TEXTURE_MIN_LOD",
		"TEXTURE_SWIZZLE_R",
		"TEXTURE_SWIZZLE_G",
		"TEXTURE_SWIZZLE_B",
		"TEXTURE_SWIZZLE_A",
		"TEXTURE_MIN_FILTER",
		"TEXTURE_MAG_FILTER",

		# Gettable only
		"TEXTURE_IMMUTABLE_LEVELS",
		"TEXTURE_IMMUTABLE_FORMAT",
		]),
	("TextureLevelParameter", [
		"TEXTURE_SAMPLES",
		"TEXTURE_FIXED_SAMPLE_LOCATIONS",
		"TEXTURE_WIDTH",
		"TEXTURE_HEIGHT",
		"TEXTURE_DEPTH",
		"TEXTURE_INTERNAL_FORMAT",
		"TEXTURE_RED_SIZE",
		"TEXTURE_GREEN_SIZE",
		"TEXTURE_BLUE_SIZE",
		"TEXTURE_ALPHA_SIZE",
		"TEXTURE_DEPTH_SIZE",
		"TEXTURE_STENCIL_SIZE",
		"TEXTURE_SHARED_SIZE",
		"TEXTURE_RED_TYPE",
		"TEXTURE_GREEN_TYPE",
		"TEXTURE_BLUE_TYPE",
		"TEXTURE_ALPHA_TYPE",
		"TEXTURE_DEPTH_TYPE",
		"TEXTURE_COMPRESSED",
		]),
	("RepeatMode",			["REPEAT", "CLAMP_TO_EDGE", "MIRRORED_REPEAT"]),
	("TextureFilter",		["NEAREST", "LINEAR", "NEAREST_MIPMAP_NEAREST", "LINEAR_MIPMAP_NEAREST",
							 "NEAREST_MIPMAP_LINEAR", "LINEAR_MIPMAP_LINEAR"]),
	("TextureWrapMode",		["REPEAT", "CLAMP_TO_EDGE", "MIRRORED_REPEAT"]),
	("TextureSwizzle",		["RED", "GREEN", "BLUE", "ALPHA", "ZERO", "ONE"]),
	("TextureCompareMode",	["NONE", "COMPARE_REF_TO_TEXTURE"]),
	("CubeMapFace",			["TEXTURE_CUBE_MAP_POSITIVE_X", "TEXTURE_CUBE_MAP_NEGATIVE_X",
							 "TEXTURE_CUBE_MAP_POSITIVE_Y", "TEXTURE_CUBE_MAP_NEGATIVE_Y",
							 "TEXTURE_CUBE_MAP_POSITIVE_Z", "TEXTURE_CUBE_MAP_NEGATIVE_Z"]),
	("PixelStoreParameter",	[
		"UNPACK_ALIGNMENT",
		"UNPACK_IMAGE_HEIGHT",
		"UNPACK_ROW_LENGTH",
		"UNPACK_SKIP_IMAGES",
		"UNPACK_SKIP_ROWS",
		"UNPACK_SKIP_PIXELS",
		"PACK_ROW_LENGTH",
		"PACK_SKIP_ROWS",
		"PACK_SKIP_PIXELS"]),
	("PixelFormat", [
		# GLES2 unsized formats
		"LUMINANCE",
		"LUMINANCE_ALPHA",
		"ALPHA",
		"RGB",
		"RGBA",

		# GLES2 sized formats
		"RGBA4",
		"RGB5_A1",
		"RGB565",
		"DEPTH_COMPONENT16",
		"STENCIL_INDEX8",

		# GLES3 unsized formats
		"RG",
		"RED",
		"RGBA_INTEGER",
		"RGB_INTEGER",
		"RG_INTEGER",
		"RED_INTEGER",
		"DEPTH_COMPONENT",
		"DEPTH_STENCIL",

		# GLES3 sized formats
		"RGBA32F",
		"RGBA32I",
		"RGBA32UI",
		"RGBA16",
		"RGBA16_SNORM",
		"RGBA16F",
		"RGBA16I",
		"RGBA16UI",
		"RGBA8",
		"RGBA8I",
		"RGBA8UI",
		"SRGB8_ALPHA8",
		"RGB10_A2",
		"RGB10_A2UI",
		"RGBA8_SNORM",
		"RGB8",
		"R11F_G11F_B10F",
		"RGB32F",
		"RGB32I",
		"RGB32UI",
		"RGB16",
		"RGB16_SNORM",
		"RGB16F",
		"RGB16I",
		"RGB16UI",
		"RGB8_SNORM",
		"RGB8I",
		"RGB8UI",
		"SRGB8",
		"RGB9_E5",
		"RG32F",
		"RG32I",
		"RG32UI",
		"RG16",
		"RG16_SNORM",
		"RG16F",
		"RG16I",
		"RG16UI",
		"RG8",
		"RG8I",
		"RG8UI",
		"RG8_SNORM",
		"R32F",
		"R32I",
		"R32UI",
		"R16",
		"R16_SNORM",
		"R16F",
		"R16I",
		"R16UI",
		"R8",
		"R8I",
		"R8UI",
		"R8_SNORM",
		"DEPTH_COMPONENT32F",
		"DEPTH_COMPONENT24",
		"DEPTH32F_STENCIL8",
		"DEPTH24_STENCIL8",

		# OES_required_internalformat
		"RGB10",

		# OES_depth32
		"DEPTH_COMPONENT32",

		# EXT_sRGB
		"SRGB",
		"SRGB_ALPHA",
		]),

	("CompressedTexFormat", [
		# ETC2/EAC formats
		"COMPRESSED_R11_EAC",
		"COMPRESSED_SIGNED_R11_EAC",
		"COMPRESSED_RG11_EAC",
		"COMPRESSED_SIGNED_RG11_EAC",
		"COMPRESSED_RGB8_ETC2",
		"COMPRESSED_SRGB8_ETC2",
		"COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2",
		"COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2",
		"COMPRESSED_RGBA8_ETC2_EAC",
		"COMPRESSED_SRGB8_ALPHA8_ETC2_EAC",

		# ASTC formats
		"COMPRESSED_RGBA_ASTC_4x4_KHR",
		"COMPRESSED_RGBA_ASTC_5x4_KHR",
		"COMPRESSED_RGBA_ASTC_5x5_KHR",
		"COMPRESSED_RGBA_ASTC_6x5_KHR",
		"COMPRESSED_RGBA_ASTC_6x6_KHR",
		"COMPRESSED_RGBA_ASTC_8x5_KHR",
		"COMPRESSED_RGBA_ASTC_8x6_KHR",
		"COMPRESSED_RGBA_ASTC_8x8_KHR",
		"COMPRESSED_RGBA_ASTC_10x5_KHR",
		"COMPRESSED_RGBA_ASTC_10x6_KHR",
		"COMPRESSED_RGBA_ASTC_10x8_KHR",
		"COMPRESSED_RGBA_ASTC_10x10_KHR",
		"COMPRESSED_RGBA_ASTC_12x10_KHR",
		"COMPRESSED_RGBA_ASTC_12x12_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR",
		"COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR"
		]),

	# Shader var type
	("ShaderVarType", [
		"FLOAT",
		"FLOAT_VEC2",
		"FLOAT_VEC3",
		"FLOAT_VEC4",
		"INT",
		"INT_VEC2",
		"INT_VEC3",
		"INT_VEC4",
		"UNSIGNED_INT",
		"UNSIGNED_INT_VEC2",
		"UNSIGNED_INT_VEC3",
		"UNSIGNED_INT_VEC4",
		"BOOL",
		"BOOL_VEC2",
		"BOOL_VEC3",
		"BOOL_VEC4",
		"FLOAT_MAT2",
		"FLOAT_MAT3",
		"FLOAT_MAT4",
		"FLOAT_MAT2x3",
		"FLOAT_MAT2x4",
		"FLOAT_MAT3x2",
		"FLOAT_MAT3x4",
		"FLOAT_MAT4x2",
		"FLOAT_MAT4x3",
		"SAMPLER_2D",
		"SAMPLER_3D",
		"SAMPLER_CUBE",
		"SAMPLER_2D_SHADOW",
		"SAMPLER_2D_ARRAY",
		"SAMPLER_2D_ARRAY_SHADOW",
		"SAMPLER_CUBE_SHADOW",
		"INT_SAMPLER_2D",
		"INT_SAMPLER_3D",
		"INT_SAMPLER_CUBE",
		"INT_SAMPLER_2D_ARRAY",
		"UNSIGNED_INT_SAMPLER_2D",
		"UNSIGNED_INT_SAMPLER_3D",
		"UNSIGNED_INT_SAMPLER_CUBE",
		"UNSIGNED_INT_SAMPLER_2D_ARRAY",
		"SAMPLER_2D_MULTISAMPLE",
		"INT_SAMPLER_2D_MULTISAMPLE",
		"UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE",
		"IMAGE_2D",
		"IMAGE_3D",
		"IMAGE_CUBE",
		"IMAGE_2D_ARRAY",
		"INT_IMAGE_2D",
		"INT_IMAGE_3D",
		"INT_IMAGE_CUBE",
		"INT_IMAGE_2D_ARRAY",
		"UNSIGNED_INT_IMAGE_2D",
		"UNSIGNED_INT_IMAGE_3D",
		"UNSIGNED_INT_IMAGE_CUBE",
		"UNSIGNED_INT_IMAGE_2D_ARRAY",
		"UNSIGNED_INT_ATOMIC_COUNTER",
	]),

	# Shader params
	("ShaderParam", [ "SHADER_TYPE", "DELETE_STATUS", "COMPILE_STATUS", "INFO_LOG_LENGTH", "SHADER_SOURCE_LENGTH"]),

	# Vertex attribute queries
	("VertexAttribParameterName", [
		"VERTEX_ATTRIB_ARRAY_BUFFER_BINDING",
		"VERTEX_ATTRIB_ARRAY_ENABLED",
		"VERTEX_ATTRIB_ARRAY_SIZE",
		"VERTEX_ATTRIB_ARRAY_STRIDE",
		"VERTEX_ATTRIB_ARRAY_TYPE",
		"VERTEX_ATTRIB_ARRAY_NORMALIZED",
		"VERTEX_ATTRIB_ARRAY_INTEGER",
		"VERTEX_ATTRIB_ARRAY_DIVISOR",
		"CURRENT_VERTEX_ATTRIB",
		"VERTEX_ATTRIB_BINDING",
		"VERTEX_ATTRIB_RELATIVE_OFFSET",
	]),

	("Boolean", ["FALSE", "TRUE"]),

	# GetPName
	("GettableState", [
		"ELEMENT_ARRAY_BUFFER_BINDING",		"ARRAY_BUFFER_BINDING",				"VERTEX_ARRAY_BINDING",								"VIEWPORT",									"DEPTH_RANGE",
		"TRANSFORM_FEEDBACK_BINDING",		"LINE_WIDTH",						"CULL_FACE_MODE",									"FRONT_FACE",								"POLYGON_OFFSET_FACTOR",
		"POLYGON_OFFSET_UNITS",				"SAMPLE_COVERAGE_VALUE",			"SAMPLE_COVERAGE_INVERT",							"ACTIVE_TEXTURE",							"TEXTURE_BINDING_1D",
		"TEXTURE_BINDING_2D",				"TEXTURE_BINDING_3D",				"TEXTURE_BINDING_2D_ARRAY",
		"TEXTURE_BINDING_CUBE_MAP",			"SAMPLER_BINDING",					"SCISSOR_BOX",										"STENCIL_FUNC",								"STENCIL_VALUE_MASK",
		"STENCIL_REF",						"STENCIL_FAIL",						"STENCIL_PASS_DEPTH_FAIL",							"STENCIL_PASS_DEPTH_PASS",					"STENCIL_BACK_FUNC",
		"STENCIL_BACK_VALUE_MASK",			"STENCIL_BACK_REF",					"STENCIL_BACK_FAIL",								"STENCIL_BACK_PASS_DEPTH_FAIL",				"STENCIL_BACK_PASS_DEPTH_PASS",
		"DEPTH_FUNC",						"BLEND_SRC_RGB",					"BLEND_SRC_ALPHA",									"BLEND_DST_RGB",							"BLEND_DST_ALPHA",
		"BLEND_EQUATION_RGB",				"BLEND_EQUATION_ALPHA",				"BLEND_COLOR",										"COLOR_WRITEMASK",							"DEPTH_WRITEMASK",
		"STENCIL_WRITEMASK",				"STENCIL_BACK_WRITEMASK",			"COLOR_CLEAR_VALUE",								"DEPTH_CLEAR_VALUE",						"STENCIL_CLEAR_VALUE",
		"DRAW_FRAMEBUFFER_BINDING",			"READ_FRAMEBUFFER_BINDING",			"RENDERBUFFER_BINDING",								"DRAW_BUFFER0",								"DRAW_BUFFER1",
		"DRAW_BUFFER2",						"DRAW_BUFFER3",						"DRAW_BUFFER4",										"DRAW_BUFFER5",								"DRAW_BUFFER6",
		"DRAW_BUFFER7",						"DRAW_BUFFER8",						"DRAW_BUFFER9",										"DRAW_BUFFER10",							"DRAW_BUFFER11",
		"DRAW_BUFFER12",					"DRAW_BUFFER13",					"DRAW_BUFFER14",									"DRAW_BUFFER15",							"READ_BUFFER",
		"UNPACK_IMAGE_HEIGHT",				"UNPACK_SKIP_IMAGES",				"UNPACK_ROW_LENGTH",								"UNPACK_SKIP_ROWS",							"UNPACK_SKIP_PIXELS",
		"UNPACK_ALIGNMENT",					"PACK_ROW_LENGTH",					"PACK_SKIP_ROWS",									"PACK_SKIP_PIXELS",							"PACK_ALIGNMENT",
		"PIXEL_PACK_BUFFER_BINDING",		"PIXEL_UNPACK_BUFFER_BINDING",		"CURRENT_PROGRAM",									"TRANSFORM_FEEDBACK_BUFFER_BINDING",		"TRANSFORM_FEEDBACK_PAUSED",
		"TRANSFORM_FEEDBACK_ACTIVE",		"UNIFORM_BUFFER_BINDING",			"GENERATE_MIPMAP_HINT",								"FRAGMENT_SHADER_DERIVATIVE_HINT",			"MAX_ELEMENT_INDEX",
		"SUBPIXEL_BITS",					"MAX_3D_TEXTURE_SIZE",				"MAX_TEXTURE_SIZE",									"MAX_ARRAY_TEXTURE_LAYERS",					"MAX_TEXTURE_LOD_BIAS",
		"MAX_CUBE_MAP_TEXTURE_SIZE",		"MAX_RENDERBUFFER_SIZE",			"MAX_DRAW_BUFFERS",									"MAX_COLOR_ATTACHMENTS",					"MAX_VIEWPORT_DIMS",
		"ALIASED_POINT_SIZE_RANGE",			"ALIASED_LINE_WIDTH_RANGE",			"MAX_ELEMENTS_INDICES",								"MAX_ELEMENTS_VERTICES",					"COMPRESSED_TEXTURE_FORMATS",
		"NUM_COMPRESSED_TEXTURE_FORMATS",	"PROGRAM_BINARY_FORMATS",			"NUM_PROGRAM_BINARY_FORMATS",						"SHADER_BINARY_FORMATS",					"NUM_SHADER_BINARY_FORMATS",
		"SHADER_COMPILER",					"MAX_SERVER_WAIT_TIMEOUT",			"NUM_EXTENSIONS",									"MAJOR_VERSION",							"MINOR_VERSION",
		"MAX_VERTEX_ATTRIBS",				"MAX_VERTEX_UNIFORM_COMPONENTS",	"MAX_VERTEX_UNIFORM_VECTORS",						"MAX_VERTEX_UNIFORM_BLOCKS",				"MAX_VERTEX_OUTPUT_COMPONENTS",
		"MAX_VERTEX_TEXTURE_IMAGE_UNITS",	"MAX_FRAGMENT_UNIFORM_COMPONENTS",	"MAX_FRAGMENT_UNIFORM_VECTORS",						"MAX_FRAGMENT_UNIFORM_BLOCKS",				"MAX_FRAGMENT_INPUT_COMPONENTS",
		"MAX_TEXTURE_IMAGE_UNITS",			"MIN_PROGRAM_TEXEL_OFFSET",			"MAX_PROGRAM_TEXEL_OFFSET",							"MAX_UNIFORM_BUFFER_BINDINGS",				"MAX_UNIFORM_BLOCK_SIZE",
		"UNIFORM_BUFFER_OFFSET_ALIGNMENT",	"MAX_COMBINED_UNIFORM_BLOCKS",		"MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS",			"MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS",	"MAX_VARYING_COMPONENTS",
		"MAX_VARYING_VECTORS",				"MAX_COMBINED_TEXTURE_IMAGE_UNITS",	"MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS",	"MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS",	"MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS",
		"SAMPLE_BUFFERS",					"SAMPLES",							"MAX_SAMPLES",										"DEPTH_BITS",								"STENCIL_BITS",
		"IMPLEMENTATION_COLOR_READ_TYPE",	"IMPLEMENTATION_COLOR_READ_FORMAT",	"COPY_READ_BUFFER_BINDING",							"COPY_WRITE_BUFFER_BINDING",				"RED_BITS",
		"GREEN_BITS",						"BLUE_BITS",						"ALPHA_BITS",										"MAX_COLOR_TEXTURE_SAMPLES",				"TIMESTAMP",
		"MAX_DEPTH_TEXTURE_SAMPLES",		"MAX_INTEGER_SAMPLES",				"TEXTURE_BINDING_2D_MULTISAMPLE",					"TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY",		"MAX_VERTEX_ATTRIB_STRIDE",
		"MAX_VERTEX_ATTRIB_BINDINGS",		"MAX_VERTEX_ATTRIB_RELATIVE_OFFSET","MIN_SAMPLE_SHADING_VALUE",							"FRAGMENT_INTERPOLATION_OFFSET_BITS",		"MAX_FRAGMENT_INTERPOLATION_OFFSET",
		"MIN_FRAGMENT_INTERPOLATION_OFFSET","MAX_GEOMETRY_SHADER_INVOCATIONS",	"LAYER_PROVOKING_VERTEX",							"MAX_GEOMETRY_UNIFORM_COMPONENTS",			"MAX_GEOMETRY_SHADER_STORAGE_BLOCKS",
		"MAX_GEOMETRY_UNIFORM_BLOCKS",		"MAX_GEOMETRY_INPUT_COMPONENTS",	"MAX_GEOMETRY_OUTPUT_COMPONENTS",					"MAX_GEOMETRY_IMAGE_UNIFORMS",				"MAX_GEOMETRY_TEXTURE_IMAGE_UNITS",
		"MAX_GEOMETRY_OUTPUT_VERTICES",		"MAX_GEOMETRY_ATOMIC_COUNTERS",		"MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS",				"MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS",		"MAX_FRAMEBUFFER_LAYERS",
		"PROVOKING_VERTEX",					"PRIMITIVE_RESTART_INDEX",			"MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS",				"MAX_FRAGMENT_ATOMIC_COUNTERS",				"MAX_FRAGMENT_IMAGE_UNIFORMS",
		"MAX_COMPUTE_UNIFORM_BLOCKS",		"MAX_COMPUTE_TEXTURE_IMAGE_UNITS",	"MAX_COMPUTE_UNIFORM_COMPONENTS",					"MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS", 		"MAX_COMPUTE_ATOMIC_COUNTERS",
		"MAX_COMPUTE_IMAGE_UNIFORMS",		"MAX_COMPUTE_SHADER_STORAGE_BLOCKS","MAX_FRAGMENT_SHADER_STORAGE_BLOCKS", 				"MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS",	"MAX_VERTEX_ATOMIC_COUNTER_BUFFERS",
		"MAX_VERTEX_ATOMIC_COUNTERS",		"MAX_VERTEX_IMAGE_UNIFORMS",		"MAX_VERTEX_SHADER_STORAGE_BLOCKS",					"MAX_COMBINED_SHADER_OUTPUT_RESOURCES",		"MAX_ATOMIC_COUNTER_BUFFER_BINDINGS",
		"MAX_ATOMIC_COUNTER_BUFFER_SIZE",	"MAX_IMAGE_UNITS",					"MAX_COMBINED_ATOMIC_COUNTER_BUFFERS",				"MAX_COMBINED_IMAGE_UNIFORMS",				"MAX_SHADER_STORAGE_BUFFER_BINDINGS",
		"MAX_SHADER_STORAGE_BLOCK_SIZE",	"MAX_COMBINED_ATOMIC_COUNTERS",		"MAX_COMBINED_SHADER_STORAGE_BLOCKS",				"SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT",
	]),

	("GettableIndexedState", [
		"TRANSFORM_FEEDBACK_BUFFER_BINDING",
		"UNIFORM_BUFFER_BINDING",
		"TRANSFORM_FEEDBACK_BUFFER_START",
		"TRANSFORM_FEEDBACK_BUFFER_SIZE",
		"UNIFORM_BUFFER_START",
		"UNIFORM_BUFFER_SIZE",
		"SAMPLE_MASK_VALUE",
		"VERTEX_BINDING_OFFSET",
		"VERTEX_BINDING_STRIDE",
		"VERTEX_BINDING_DIVISOR",
		"VERTEX_BINDING_BUFFER",
	]),

	("GettableString", [
		"EXTENSIONS",
		"RENDERER",
		"SHADING_LANGUAGE_VERSION",
		"VENDOR",
		"VERSION"
	]),

	("InternalFormatParameter", ["NUM_SAMPLE_COUNTS", "SAMPLES"]),
	("InternalFormatTarget", [
		"RENDERBUFFER",
		"TEXTURE_2D_MULTISAMPLE",
		"TEXTURE_2D_MULTISAMPLE_ARRAY",
		"TEXTURE_2D",
		"TEXTURE_3D",
		"TEXTURE_2D_ARRAY",
		"TEXTURE_CUBE_MAP",
	]),

	("MultisampleParameter", ["SAMPLE_POSITION"]),

	# Occlusion and timer queries
	("QueryTarget", [
		"SAMPLES_PASSED",
		"ANY_SAMPLES_PASSED",
		"PRIMITIVES_GENERATED",
		"TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN",
		"TIME_ELAPSED",
	]),

	("QueryParam",			["CURRENT_QUERY", "QUERY_COUNTER_BITS"]),
	("QueryObjectParam",	["QUERY_RESULT", "QUERY_RESULT_AVAILABLE"]),

	("ImageAccess", ["READ_ONLY", "WRITE_ONLY", "READ_WRITE"]),

	("ProgramInterface", [
		"UNIFORM",
		"UNIFORM_BLOCK",
		"ATOMIC_COUNTER_BUFFER",
		"PROGRAM_INPUT",
		"PROGRAM_OUTPUT",
		"TRANSFORM_FEEDBACK_VARYING",
		"BUFFER_VARIABLE",
		"SHADER_STORAGE_BLOCK",
	]),

	("ProgramResourceProperty", [
		"ACTIVE_VARIABLES",
		"BUFFER_BINDING",
		"NUM_ACTIVE_VARIABLES",
		"ARRAY_SIZE",
		"ARRAY_STRIDE",
		"BLOCK_INDEX",
		"IS_ROW_MAJOR",
		"MATRIX_STRIDE",
		"ATOMIC_COUNTER_BUFFER_INDEX",
		"BUFFER_DATA_SIZE",
		"LOCATION",
		"NAME_LENGTH",
		"OFFSET",
		"REFERENCED_BY_VERTEX_SHADER",
		"REFERENCED_BY_FRAGMENT_SHADER",
		"REFERENCED_BY_COMPUTE_SHADER",
		"REFERENCED_BY_GEOMETRY_SHADER",
		"REFERENCED_BY_TESS_CONTROL_SHADER",
		"REFERENCED_BY_TESS_EVALUATION_SHADER",
		"TOP_LEVEL_ARRAY_SIZE",
		"TOP_LEVEL_ARRAY_STRIDE",
		"TYPE",
		"IS_PER_PATCH",
	]),

	("PrecisionFormatType", ["LOW_FLOAT", "MEDIUM_FLOAT", "HIGH_FLOAT", "LOW_INT", "MEDIUM_INT", "HIGH_INT"]),

	("TransformFeedbackTarget", ["TRANSFORM_FEEDBACK"]),

	("ProvokingVertex", ["FIRST_VERTEX_CONVENTION", "LAST_VERTEX_CONVENTION", "UNDEFINED_VERTEX"]),

	("DebugMessageSource", [
		"DEBUG_SOURCE_API",
		"DEBUG_SOURCE_WINDOW_SYSTEM",
		"DEBUG_SOURCE_SHADER_COMPILER",
		"DEBUG_SOURCE_THIRD_PARTY",
		"DEBUG_SOURCE_APPLICATION",
		"DEBUG_SOURCE_OTHER", "DONT_CARE"
	]),
	("DebugMessageType", [
		"DEBUG_TYPE_ERROR",
		"DEBUG_TYPE_DEPRECATED_BEHAVIOR",
		"DEBUG_TYPE_UNDEFINED_BEHAVIOR",
		"DEBUG_TYPE_PORTABILITY",
		"DEBUG_TYPE_PERFORMANCE",
		"DEBUG_TYPE_OTHER",
		"DEBUG_TYPE_MARKER",
		"DEBUG_TYPE_PUSH_GROUP",
		"DEBUG_TYPE_POP_GROUP",
		"DONT_CARE"
	]),
	("DebugMessageSeverity", [
		"DEBUG_SEVERITY_HIGH",
		"DEBUG_SEVERITY_MEDIUM",
		"DEBUG_SEVERITY_LOW",
		"DEBUG_SEVERITY_NOTIFICATION",
		"DONT_CARE"
	]),

	# Pipeline query
	("PipelineParam", [
		"ACTIVE_PROGRAM",
		"INFO_LOG_LENGTH",
		"VALIDATE_STATUS",
		"VERTEX_SHADER",
		"FRAGMENT_SHADER",
		"COMPUTE_SHADER",
		"GEOMETRY_SHADER",
		"TESS_CONTROL_SHADER",
		"TESS_EVALUATION_SHADER",
	]),
]

# EnableCap EnumGroups are also GettableState EnumGroups
[x for x in ENUM_GROUPS if x[0]=="GettableState"][0][1].extend([x for x in ENUM_GROUPS if x[0]=="EnableCap"][0][1])

def isValueDefined (definitions, value):
	return ("GL_" + value) in definitions

def allValuesUndefined (definitions, values):
	for value in values:
		if isValueDefined(definitions, value):
			return False
	return True

def anyValueDefined (definitions, values):
	return not allValuesUndefined(definitions, values)

def writeStrUtilPrototypes (enumGroups, bitfieldGroups, definitions, dstFile):
	def genNameProtos ():
		for groupName, values in enumGroups:
			if anyValueDefined(definitions, values):
				yield "const char*\tget%sName\t(int value);" % groupName
			else:
				print "Warning: Empty value set for %s, skipping" % groupName

	def genBitfieldProtos ():
		for groupName, values in bitfieldGroups:
			if anyValueDefined(definitions, values):
				yield "tcu::Format::Bitfield<16>\tget%sStr\t(int value);" % groupName
			else:
				print "Warning: Empty value set for %s, skipping" % groupName

	def genStrImpl ():
		for groupName, values in enumGroups:
			if anyValueDefined(definitions, values):
				yield "inline tcu::Format::Enum\tget%sStr\t(int value)\t{ return tcu::Format::Enum(get%sName,\tvalue); }" % (groupName, groupName)

	writeInlFile(dstFile, indentLines(chain(genNameProtos(), genBitfieldProtos(), genStrImpl())))

def genEnumStrImplementation (groupName, values, definitions):
	if allValuesUndefined(definitions, values):
		return

	yield ""
	yield "const char* get%sName (int value)" % groupName
	yield "{"
	yield "\tswitch (value)"
	yield "\t{"

	def genCases ():
		for value in values:
			if isValueDefined(definitions, value):
				yield "case GL_%s:\treturn \"GL_%s\";" % (value, value)
			else:
				print "Warning: %s not defined, skipping" % value
		yield "default:\treturn DE_NULL;"

	for caseLine in indentLines(genCases()):
		yield "\t\t" + caseLine

	yield "\t}"
	yield "}"

def genBitfieldStrImplementation (groupName, values, definitions):
	if allValuesUndefined(definitions, values):
		return

	yield ""
	yield "tcu::Format::Bitfield<16> get%sStr (int value)" % groupName
	yield "{"
	yield "\tstatic const tcu::Format::BitDesc s_desc[] ="
	yield "\t{"

	def genFields ():
		for value in values:
			if isValueDefined(definitions, value):
				yield "tcu::Format::BitDesc(GL_%s,\t\"GL_%s\")," % (value, value)
			else:
				print "Warning: %s not defined, skipping" % value

	for fieldLine in indentLines(genFields()):
		yield "\t\t" + fieldLine

	yield "\t};"
	yield "\treturn tcu::Format::Bitfield<16>(value, &s_desc[0], &s_desc[DE_LENGTH_OF_ARRAY(s_desc)]);"
	yield "}"

def genStrUtilImplementations (enumGroups, bitfieldGroups, definitions):
	for groupName, values in enumGroups:
		for line in genEnumStrImplementation(groupName, values, definitions):
			yield line
	for groupName, values in bitfieldGroups:
		for line in genBitfieldStrImplementation(groupName, values, definitions):
			yield line

def writeStrUtilImplementations (enumGroups, bitfieldGroups, definitions, dstFile):
	writeInlFile(dstFile, genStrUtilImplementations(enumGroups, bitfieldGroups, definitions))

def genStrUtil (iface):
	definitions = set(enum.name for enum in iface.enums)
	writeStrUtilPrototypes(ENUM_GROUPS, BITFIELD_GROUPS, definitions, os.path.join(OPENGL_DIR, "gluStrUtilPrototypes.inl"))
	writeStrUtilImplementations(ENUM_GROUPS, BITFIELD_GROUPS, definitions, os.path.join(OPENGL_DIR, "gluStrUtil.inl"))

if __name__ == "__main__":
	genStrUtil(getHybridInterface())
