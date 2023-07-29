/*------------------------------------------------------------------------
 * Vulkan Conformance Tests
 * ------------------------
 *
 * Copyright (c) 2015 The Khronos Group Inc.
 * Copyright (c) 2015 Imagination Technologies Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *//*!
 * \file
 * \brief Input Assembly Tests
 *//*--------------------------------------------------------------------*/

#include "vktPipelineInputAssemblyTests.hpp"
#include "vktPipelineClearUtil.hpp"
#include "vktPipelineImageUtil.hpp"
#include "vktPipelineVertexUtil.hpp"
#include "vktPipelineReferenceRenderer.hpp"
#include "vktTestCase.hpp"
#include "vkImageUtil.hpp"
#include "vkMemUtil.hpp"
#include "vkPrograms.hpp"
#include "vkQueryUtil.hpp"
#include "vkRef.hpp"
#include "vkRefUtil.hpp"
#include "vkTypeUtil.hpp"
#include "vkCmdUtil.hpp"
#include "vkObjUtil.hpp"
#include "tcuImageCompare.hpp"
#include "deMath.h"
#include "deMemory.h"
#include "deRandom.hpp"
#include "deStringUtil.hpp"
#include "deUniquePtr.hpp"

#include <algorithm>
#include <sstream>
#include <vector>

namespace vkt
{
namespace pipeline
{

using namespace vk;

namespace
{

class InputAssemblyTest : public vkt::TestCase
{
public:
    const static VkPrimitiveTopology s_primitiveTopologies[];
    const static uint32_t s_restartIndex32;
    const static uint16_t s_restartIndex16;
    const static uint8_t s_restartIndex8;

    InputAssemblyTest(tcu::TestContext &testContext, const std::string &name, const std::string &description,
                      VkPrimitiveTopology primitiveTopology, int primitiveCount, bool testPrimitiveRestart,
                      VkIndexType indexType);
    virtual ~InputAssemblyTest(void)
    {
    }
    virtual void initPrograms(SourceCollections &sourceCollections) const;
    virtual void checkSupport(Context &context) const;
    virtual TestInstance *createInstance(Context &context) const;
    static bool isRestartIndex(VkIndexType indexType, uint32_t indexValue);
    static uint32_t getRestartIndex(VkIndexType indexType);

protected:
    virtual void createBufferData(VkPrimitiveTopology topology, int primitiveCount, VkIndexType indexType,
                                  std::vector<uint32_t> &indexData, std::vector<Vertex4RGBA> &vertexData) const = 0;

private:
    VkPrimitiveTopology m_primitiveTopology;
    const int m_primitiveCount;
    bool m_testPrimitiveRestart;
    VkIndexType m_indexType;
};

class PrimitiveTopologyTest : public InputAssemblyTest
{
public:
    PrimitiveTopologyTest(tcu::TestContext &testContext, const std::string &name, const std::string &description,
                          VkPrimitiveTopology primitiveTopology, VkIndexType indexType);
    virtual ~PrimitiveTopologyTest(void)
    {
    }

protected:
    virtual void createBufferData(VkPrimitiveTopology topology, int primitiveCount, VkIndexType indexType,
                                  std::vector<uint32_t> &indexData, std::vector<Vertex4RGBA> &vertexData) const;

private:
};

class PrimitiveRestartTest : public InputAssemblyTest
{
public:
    PrimitiveRestartTest(tcu::TestContext &testContext, const std::string &name, const std::string &description,
                         VkPrimitiveTopology primitiveTopology, VkIndexType indexType);
    virtual ~PrimitiveRestartTest(void)
    {
    }

protected:
    virtual void createBufferData(VkPrimitiveTopology topology, int primitiveCount, VkIndexType indexType,
                                  std::vector<uint32_t> &indexData, std::vector<Vertex4RGBA> &vertexData) const;

private:
    bool isRestartPrimitive(int primitiveIndex) const;

    std::vector<uint32_t> m_restartPrimitives;
};

class InputAssemblyInstance : public vkt::TestInstance
{
public:
    InputAssemblyInstance(Context &context, VkPrimitiveTopology primitiveTopology, bool testPrimitiveRestart,
                          VkIndexType indexType, const std::vector<uint32_t> &indexBufferData,
                          const std::vector<Vertex4RGBA> &vertexBufferData);
    virtual ~InputAssemblyInstance(void);
    virtual tcu::TestStatus iterate(void);

private:
    tcu::TestStatus verifyImage(void);
    void uploadIndexBufferData16(uint16_t *destPtr, const std::vector<uint32_t> &indexBufferData);
    void uploadIndexBufferData8(uint8_t *destPtr, const std::vector<uint32_t> &indexBufferData);

    VkPrimitiveTopology m_primitiveTopology;
    bool m_primitiveRestartEnable;
    VkIndexType m_indexType;

    Move<VkBuffer> m_vertexBuffer;
    std::vector<Vertex4RGBA> m_vertices;
    de::MovePtr<Allocation> m_vertexBufferAlloc;

    Move<VkBuffer> m_indexBuffer;
    std::vector<uint32_t> m_indices;
    de::MovePtr<Allocation> m_indexBufferAlloc;

    const tcu::UVec2 m_renderSize;

    const VkFormat m_colorFormat;
    VkImageCreateInfo m_colorImageCreateInfo;
    Move<VkImage> m_colorImage;
    de::MovePtr<Allocation> m_colorImageAlloc;
    Move<VkImageView> m_colorAttachmentView;
    Move<VkRenderPass> m_renderPass;
    Move<VkFramebuffer> m_framebuffer;

    Move<VkShaderModule> m_vertexShaderModule;
    Move<VkShaderModule> m_fragmentShaderModule;

    Move<VkPipelineLayout> m_pipelineLayout;
    Move<VkPipeline> m_graphicsPipeline;

    Move<VkCommandPool> m_cmdPool;
    Move<VkCommandBuffer> m_cmdBuffer;
};

// InputAssemblyTest

const VkPrimitiveTopology InputAssemblyTest::s_primitiveTopologies[] = {
    VK_PRIMITIVE_TOPOLOGY_POINT_LIST,
    VK_PRIMITIVE_TOPOLOGY_LINE_LIST,
    VK_PRIMITIVE_TOPOLOGY_LINE_STRIP,
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP,
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN,
    VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY,
    VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY,
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY,
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY};

const uint32_t InputAssemblyTest::s_restartIndex32 = ~((uint32_t)0u);
const uint16_t InputAssemblyTest::s_restartIndex16 = ~((uint16_t)0u);
const uint8_t InputAssemblyTest::s_restartIndex8   = ~((uint8_t)0u);

InputAssemblyTest::InputAssemblyTest(tcu::TestContext &testContext, const std::string &name,
                                     const std::string &description, VkPrimitiveTopology primitiveTopology,
                                     int primitiveCount, bool testPrimitiveRestart, VkIndexType indexType)

    : vkt::TestCase(testContext, name, description)
    , m_primitiveTopology(primitiveTopology)
    , m_primitiveCount(primitiveCount)
    , m_testPrimitiveRestart(testPrimitiveRestart)
    , m_indexType(indexType)
{
}

void InputAssemblyTest::checkSupport(Context &context) const
{
    if (m_indexType == VK_INDEX_TYPE_UINT8_EXT)
        context.requireDeviceFunctionality("VK_EXT_index_type_uint8");

    switch (m_primitiveTopology)
    {
    case VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY:
    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY:
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY:
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY:
        context.requireDeviceCoreFeature(DEVICE_CORE_FEATURE_GEOMETRY_SHADER);
        break;

    case VK_PRIMITIVE_TOPOLOGY_PATCH_LIST:
        context.requireDeviceCoreFeature(DEVICE_CORE_FEATURE_TESSELLATION_SHADER);
        break;

    default:
        break;
    }
}

TestInstance *InputAssemblyTest::createInstance(Context &context) const
{
    std::vector<uint32_t> indexBufferData;
    std::vector<Vertex4RGBA> vertexBufferData;

    createBufferData(m_primitiveTopology, m_primitiveCount, m_indexType, indexBufferData, vertexBufferData);

    return new InputAssemblyInstance(context, m_primitiveTopology, m_testPrimitiveRestart, m_indexType, indexBufferData,
                                     vertexBufferData);
}

void InputAssemblyTest::initPrograms(SourceCollections &sourceCollections) const
{
    std::ostringstream vertexSource;

    vertexSource << "#version 310 es\n"
                    "layout(location = 0) in vec4 position;\n"
                    "layout(location = 1) in vec4 color;\n"
                    "layout(location = 0) out highp vec4 vtxColor;\n"
                    "void main (void)\n"
                    "{\n"
                    "    gl_Position = position;\n"
                 << (m_primitiveTopology == VK_PRIMITIVE_TOPOLOGY_POINT_LIST ? "    gl_PointSize = 3.0;\n" : "")
                 << "    vtxColor = color;\n"
                    "}\n";

    sourceCollections.glslSources.add("color_vert") << glu::VertexSource(vertexSource.str());

    sourceCollections.glslSources.add("color_frag")
        << glu::FragmentSource("#version 310 es\n"
                               "layout(location = 0) in highp vec4 vtxColor;\n"
                               "layout(location = 0) out highp vec4 fragColor;\n"
                               "void main (void)\n"
                               "{\n"
                               "    fragColor = vtxColor;\n"
                               "}\n");
}

bool InputAssemblyTest::isRestartIndex(VkIndexType indexType, uint32_t indexValue)
{
    if (indexType == VK_INDEX_TYPE_UINT16)
        return indexValue == s_restartIndex16;
    else if (indexType == VK_INDEX_TYPE_UINT8_EXT)
        return indexValue == s_restartIndex8;
    else
        return indexValue == s_restartIndex32;
}

uint32_t InputAssemblyTest::getRestartIndex(VkIndexType indexType)
{
    if (indexType == VK_INDEX_TYPE_UINT16)
        return InputAssemblyTest::s_restartIndex16;
    else if (indexType == VK_INDEX_TYPE_UINT8_EXT)
        return InputAssemblyTest::s_restartIndex8;
    else
        return InputAssemblyTest::s_restartIndex32;
}

// PrimitiveTopologyTest

PrimitiveTopologyTest::PrimitiveTopologyTest(tcu::TestContext &testContext, const std::string &name,
                                             const std::string &description, VkPrimitiveTopology primitiveTopology,
                                             VkIndexType indexType)
    : InputAssemblyTest(testContext, name, description, primitiveTopology, 10, false, indexType)
{
}

void PrimitiveTopologyTest::createBufferData(VkPrimitiveTopology topology, int primitiveCount, VkIndexType indexType,
                                             std::vector<uint32_t> &indexData,
                                             std::vector<Vertex4RGBA> &vertexData) const
{
    DE_ASSERT(primitiveCount > 0);
    DE_UNREF(indexType);

    const tcu::Vec4 red(1.0f, 0.0f, 0.0f, 1.0f);
    const tcu::Vec4 green(0.0f, 1.0f, 0.0f, 1.0f);
    const float border              = 0.2f;
    const float originX             = -1.0f + border;
    const float originY             = -1.0f + border;
    const Vertex4RGBA defaultVertex = {tcu::Vec4(-1.0f, -1.0f, 0.0f, 1.0f), green};
    float primitiveSizeY            = (2.0f - 2.0f * border);
    float primitiveSizeX;
    std::vector<uint32_t> indices;
    std::vector<Vertex4RGBA> vertices;

    // Calculate primitive size
    switch (topology)
    {
    case VK_PRIMITIVE_TOPOLOGY_POINT_LIST:
        primitiveSizeX = (2.0f - 2.0f * border) / float(primitiveCount / 2 + primitiveCount % 2 - 1);
        break;

    case VK_PRIMITIVE_TOPOLOGY_LINE_LIST:
    case VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY:
        primitiveSizeX = (2.0f - 2.0f * border) / float(primitiveCount - 1);
        break;

    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP:
    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY:
        primitiveSizeX = (2.0f - 2.0f * border) / float(primitiveCount / 2);
        break;

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST:
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY:
        primitiveSizeX = (2.0f - 2.0f * border) / float(primitiveCount + primitiveCount / 2 + primitiveCount % 2 - 1);
        break;

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP:
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY:
        primitiveSizeX = (2.0f - 2.0f * border) / float(primitiveCount / 2 + primitiveCount % 2);
        break;

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN:
        primitiveSizeX = 1.0f - border;
        primitiveSizeY = 1.0f - border;
        break;

    default:
        primitiveSizeX = 0.0f; // Garbage
        DE_ASSERT(false);
    }

    switch (topology)
    {
    case VK_PRIMITIVE_TOPOLOGY_POINT_LIST:
        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            const Vertex4RGBA vertex = {tcu::Vec4(originX + float(primitiveNdx / 2) * primitiveSizeX,
                                                  originY + float(primitiveNdx % 2) * primitiveSizeY, 0.0f, 1.0f),
                                        red};

            vertices.push_back(vertex);
            indices.push_back(primitiveNdx);
        }
        break;

    case VK_PRIMITIVE_TOPOLOGY_LINE_LIST:
        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            for (int vertexNdx = 0; vertexNdx < 2; vertexNdx++)
            {
                const Vertex4RGBA vertex = {
                    tcu::Vec4(originX + float((primitiveNdx * 2 + vertexNdx) / 2) * primitiveSizeX,
                              originY + float(vertexNdx % 2) * primitiveSizeY, 0.0f, 1.0f),
                    red};

                vertices.push_back(vertex);
                indices.push_back((primitiveNdx * 2 + vertexNdx));
            }
        }
        break;

    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP:
        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            if (primitiveNdx == 0)
            {
                Vertex4RGBA vertex = {tcu::Vec4(originX, originY, 0.0f, 1.0f), red};

                vertices.push_back(vertex);
                indices.push_back(0);

                vertex.position = tcu::Vec4(originX, originY + primitiveSizeY, 0.0f, 1.0f);
                vertices.push_back(vertex);
                indices.push_back(1);
            }
            else
            {
                const Vertex4RGBA vertex = {tcu::Vec4(originX + float((primitiveNdx + 1) / 2) * primitiveSizeX,
                                                      originY + float((primitiveNdx + 1) % 2) * primitiveSizeY, 0.0f,
                                                      1.0f),
                                            red};

                vertices.push_back(vertex);
                indices.push_back(primitiveNdx + 1);
            }
        }
        break;

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST:
        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            for (int vertexNdx = 0; vertexNdx < 3; vertexNdx++)
            {
                const Vertex4RGBA vertex = {
                    tcu::Vec4(originX + float((primitiveNdx * 3 + vertexNdx) / 2) * primitiveSizeX,
                              originY + float((primitiveNdx * 3 + vertexNdx) % 2) * primitiveSizeY, 0.0f, 1.0f),
                    red};

                vertices.push_back(vertex);
                indices.push_back(primitiveNdx * 3 + vertexNdx);
            }
        }
        break;

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP:
        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            if (primitiveNdx == 0)
            {
                for (int vertexNdx = 0; vertexNdx < 3; vertexNdx++)
                {
                    const Vertex4RGBA vertex = {tcu::Vec4(originX + float(vertexNdx / 2) * primitiveSizeX,
                                                          originY + float(vertexNdx % 2) * primitiveSizeY, 0.0f, 1.0f),
                                                red};

                    vertices.push_back(vertex);
                    indices.push_back(vertexNdx);
                }
            }
            else
            {
                const Vertex4RGBA vertex = {tcu::Vec4(originX + float((primitiveNdx + 2) / 2) * primitiveSizeX,
                                                      originY + float((primitiveNdx + 2) % 2) * primitiveSizeY, 0.0f,
                                                      1.0f),
                                            red};

                vertices.push_back(vertex);
                indices.push_back(primitiveNdx + 2);
            }
        }
        break;

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN:
    {
        const float stepAngle = de::min(DE_PI * 0.5f, (2 * DE_PI) / float(primitiveCount));

        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            if (primitiveNdx == 0)
            {
                Vertex4RGBA vertex = {tcu::Vec4(0.0f, 0.0f, 0.0f, 1.0f), red};

                vertices.push_back(vertex);
                indices.push_back(0);

                vertex.position = tcu::Vec4(primitiveSizeX, 0.0f, 0.0f, 1.0f);
                vertices.push_back(vertex);
                indices.push_back(1);

                vertex.position = tcu::Vec4(primitiveSizeX * deFloatCos(stepAngle),
                                            primitiveSizeY * deFloatSin(stepAngle), 0.0f, 1.0f);
                vertices.push_back(vertex);
                indices.push_back(2);
            }
            else
            {
                const Vertex4RGBA vertex = {tcu::Vec4(primitiveSizeX * deFloatCos(stepAngle * float(primitiveNdx + 1)),
                                                      primitiveSizeY * deFloatSin(stepAngle * float(primitiveNdx + 1)),
                                                      0.0f, 1.0f),
                                            red};

                vertices.push_back(vertex);
                indices.push_back(primitiveNdx + 2);
            }
        }
        break;
    }

    case VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY:
        vertices.push_back(defaultVertex);

        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            indices.push_back(0);

            for (int vertexNdx = 0; vertexNdx < 2; vertexNdx++)
            {
                const Vertex4RGBA vertex = {
                    tcu::Vec4(originX + float((primitiveNdx * 2 + vertexNdx) / 2) * primitiveSizeX,
                              originY + float(vertexNdx % 2) * primitiveSizeY, 0.0f, 1.0f),
                    red};

                vertices.push_back(vertex);
                indices.push_back(primitiveNdx * 2 + vertexNdx + 1);
            }

            indices.push_back(0);
        }
        break;

    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY:
        vertices.push_back(defaultVertex);
        indices.push_back(0);

        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            if (primitiveNdx == 0)
            {
                Vertex4RGBA vertex = {tcu::Vec4(originX, originY, 0.0f, 1.0f), red};

                vertices.push_back(vertex);
                indices.push_back(1);

                vertex.position = tcu::Vec4(originX, originY + primitiveSizeY, 0.0f, 1.0f);
                vertices.push_back(vertex);
                indices.push_back(2);
            }
            else
            {
                const Vertex4RGBA vertex = {tcu::Vec4(originX + float((primitiveNdx + 1) / 2) * primitiveSizeX,
                                                      originY + float((primitiveNdx + 1) % 2) * primitiveSizeY, 0.0f,
                                                      1.0f),
                                            red};

                vertices.push_back(vertex);
                indices.push_back(primitiveNdx + 2);
            }
        }

        indices.push_back(0);
        break;

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY:
        vertices.push_back(defaultVertex);

        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            for (int vertexNdx = 0; vertexNdx < 3; vertexNdx++)
            {
                const Vertex4RGBA vertex = {
                    tcu::Vec4(originX + float((primitiveNdx * 3 + vertexNdx) / 2) * primitiveSizeX,
                              originY + float((primitiveNdx * 3 + vertexNdx) % 2) * primitiveSizeY, 0.0f, 1.0f),
                    red};

                vertices.push_back(vertex);
                indices.push_back(primitiveNdx * 3 + vertexNdx + 1);
                indices.push_back(0);
            }
        }
        break;

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY:
        vertices.push_back(defaultVertex);

        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            if (primitiveNdx == 0)
            {
                for (int vertexNdx = 0; vertexNdx < 3; vertexNdx++)
                {
                    const Vertex4RGBA vertex = {tcu::Vec4(originX + float(vertexNdx / 2) * primitiveSizeX,
                                                          originY + float(vertexNdx % 2) * primitiveSizeY, 0.0f, 1.0f),
                                                red};

                    vertices.push_back(vertex);
                    indices.push_back(vertexNdx + 1);
                    indices.push_back(0);
                }
            }
            else
            {
                const Vertex4RGBA vertex = {tcu::Vec4(originX + float((primitiveNdx + 2) / 2) * primitiveSizeX,
                                                      originY + float((primitiveNdx + 2) % 2) * primitiveSizeY, 0.0f,
                                                      1.0f),
                                            red};

                vertices.push_back(vertex);
                indices.push_back(primitiveNdx + 2 + 1);
                indices.push_back(0);
            }
        }
        break;

    default:
        DE_ASSERT(false);
        break;
    }

    vertexData = vertices;
    indexData  = indices;
}

// PrimitiveRestartTest

PrimitiveRestartTest::PrimitiveRestartTest(tcu::TestContext &testContext, const std::string &name,
                                           const std::string &description, VkPrimitiveTopology primitiveTopology,
                                           VkIndexType indexType)

    : InputAssemblyTest(testContext, name, description, primitiveTopology, 10, true, indexType)
{
    DE_ASSERT(primitiveTopology == VK_PRIMITIVE_TOPOLOGY_LINE_STRIP ||
              primitiveTopology == VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP ||
              primitiveTopology == VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN ||
              primitiveTopology == VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY ||
              primitiveTopology == VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY);

    uint32_t restartPrimitives[] = {1, 5};

    m_restartPrimitives =
        std::vector<uint32_t>(restartPrimitives, restartPrimitives + sizeof(restartPrimitives) / sizeof(uint32_t));
}

void PrimitiveRestartTest::createBufferData(VkPrimitiveTopology topology, int primitiveCount, VkIndexType indexType,
                                            std::vector<uint32_t> &indexData,
                                            std::vector<Vertex4RGBA> &vertexData) const
{
    DE_ASSERT(primitiveCount > 0);
    DE_UNREF(indexType);

    const tcu::Vec4 red(1.0f, 0.0f, 0.0f, 1.0f);
    const tcu::Vec4 green(0.0f, 1.0f, 0.0f, 1.0f);
    const float border              = 0.2f;
    const float originX             = -1.0f + border;
    const float originY             = -1.0f + border;
    const Vertex4RGBA defaultVertex = {tcu::Vec4(-1.0f, -1.0f, 0.0f, 1.0f), green};
    float primitiveSizeY            = (2.0f - 2.0f * border);
    float primitiveSizeX;
    bool primitiveStart = true;
    std::vector<uint32_t> indices;
    std::vector<Vertex4RGBA> vertices;

    // Calculate primitive size
    switch (topology)
    {
    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP:
    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY:
        primitiveSizeX = (2.0f - 2.0f * border) / float(primitiveCount / 2);
        break;

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP:
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY:
        primitiveSizeX = (2.0f - 2.0f * border) / float(primitiveCount / 2 + primitiveCount % 2);
        break;

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN:
        primitiveSizeX = 1.0f - border;
        primitiveSizeY = 1.0f - border;
        break;

    default:
        primitiveSizeX = 0.0f; // Garbage
        DE_ASSERT(false);
    }

    switch (topology)
    {
    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP:
        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            if (isRestartPrimitive(primitiveNdx))
            {
                indices.push_back(InputAssemblyTest::getRestartIndex(indexType));
                primitiveStart = true;
            }
            else
            {
                if (primitiveStart)
                {
                    const Vertex4RGBA vertex = {tcu::Vec4(originX + float(primitiveNdx / 2) * primitiveSizeX,
                                                          originY + float(primitiveNdx % 2) * primitiveSizeY, 0.0f,
                                                          1.0f),
                                                red};

                    vertices.push_back(vertex);
                    indices.push_back((uint32_t)vertices.size() - 1);

                    primitiveStart = false;
                }

                const Vertex4RGBA vertex = {tcu::Vec4(originX + float((primitiveNdx + 1) / 2) * primitiveSizeX,
                                                      originY + float((primitiveNdx + 1) % 2) * primitiveSizeY, 0.0f,
                                                      1.0f),
                                            red};

                vertices.push_back(vertex);
                indices.push_back((uint32_t)vertices.size() - 1);
            }
        }
        break;

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP:
    {
        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            if (isRestartPrimitive(primitiveNdx))
            {
                indices.push_back(InputAssemblyTest::getRestartIndex(indexType));
                primitiveStart = true;
            }
            else
            {
                if (primitiveStart)
                {
                    for (int vertexNdx = 0; vertexNdx < 2; vertexNdx++)
                    {
                        const Vertex4RGBA vertex = {
                            tcu::Vec4(originX + float((primitiveNdx + vertexNdx) / 2) * primitiveSizeX,
                                      originY + float((primitiveNdx + vertexNdx) % 2) * primitiveSizeY, 0.0f, 1.0f),
                            red};

                        vertices.push_back(vertex);
                        indices.push_back((uint32_t)vertices.size() - 1);
                    }

                    primitiveStart = false;
                }
                const Vertex4RGBA vertex = {tcu::Vec4(originX + float((primitiveNdx + 2) / 2) * primitiveSizeX,
                                                      originY + float((primitiveNdx + 2) % 2) * primitiveSizeY, 0.0f,
                                                      1.0f),
                                            red};

                vertices.push_back(vertex);
                indices.push_back((uint32_t)vertices.size() - 1);
            }
        }
        break;
    }

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN:
    {
        const float stepAngle = de::min(DE_PI * 0.5f, (2 * DE_PI) / float(primitiveCount));

        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            if (isRestartPrimitive(primitiveNdx))
            {
                indices.push_back(InputAssemblyTest::getRestartIndex(indexType));
                primitiveStart = true;
            }
            else
            {
                if (primitiveStart)
                {
                    Vertex4RGBA vertex = {tcu::Vec4(0.0f, 0.0f, 0.0f, 1.0f), red};

                    vertices.push_back(vertex);
                    indices.push_back((uint32_t)vertices.size() - 1);

                    vertex.position =
                        tcu::Vec4(primitiveSizeX * deFloatCos(stepAngle * float(primitiveNdx)),
                                  primitiveSizeY * deFloatSin(stepAngle * float(primitiveNdx)), 0.0f, 1.0f),
                    vertices.push_back(vertex);
                    indices.push_back((uint32_t)vertices.size() - 1);

                    primitiveStart = false;
                }

                const Vertex4RGBA vertex = {tcu::Vec4(primitiveSizeX * deFloatCos(stepAngle * float(primitiveNdx + 1)),
                                                      primitiveSizeY * deFloatSin(stepAngle * float(primitiveNdx + 1)),
                                                      0.0f, 1.0f),
                                            red};

                vertices.push_back(vertex);
                indices.push_back((uint32_t)vertices.size() - 1);
            }
        }
        break;
    }

    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY:
        vertices.push_back(defaultVertex);

        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            if (isRestartPrimitive(primitiveNdx))
            {
                indices.push_back(0);
                indices.push_back(InputAssemblyTest::getRestartIndex(indexType));
                primitiveStart = true;
            }
            else
            {
                if (primitiveStart)
                {
                    indices.push_back(0);

                    const Vertex4RGBA vertex = {tcu::Vec4(originX + float(primitiveNdx / 2) * primitiveSizeX,
                                                          originY + float(primitiveNdx % 2) * primitiveSizeY, 0.0f,
                                                          1.0f),
                                                red};

                    vertices.push_back(vertex);
                    indices.push_back((uint32_t)vertices.size() - 1);

                    primitiveStart = false;
                }

                const Vertex4RGBA vertex = {tcu::Vec4(originX + float((primitiveNdx + 1) / 2) * primitiveSizeX,
                                                      originY + float((primitiveNdx + 1) % 2) * primitiveSizeY, 0.0f,
                                                      1.0f),
                                            red};

                vertices.push_back(vertex);
                indices.push_back((uint32_t)vertices.size() - 1);
            }
        }

        indices.push_back(0);
        break;

    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY:
        vertices.push_back(defaultVertex);

        for (int primitiveNdx = 0; primitiveNdx < primitiveCount; primitiveNdx++)
        {
            if (isRestartPrimitive(primitiveNdx))
            {
                indices.push_back(InputAssemblyTest::getRestartIndex(indexType));
                primitiveStart = true;
            }
            else
            {
                if (primitiveStart)
                {
                    for (int vertexNdx = 0; vertexNdx < 2; vertexNdx++)
                    {
                        const Vertex4RGBA vertex = {
                            tcu::Vec4(originX + float((primitiveNdx + vertexNdx) / 2) * primitiveSizeX,
                                      originY + float((primitiveNdx + vertexNdx) % 2) * primitiveSizeY, 0.0f, 1.0f),
                            red};

                        vertices.push_back(vertex);
                        indices.push_back((uint32_t)vertices.size() - 1);
                        indices.push_back(0);
                    }

                    primitiveStart = false;
                }

                const Vertex4RGBA vertex = {tcu::Vec4(originX + float((primitiveNdx + 2) / 2) * primitiveSizeX,
                                                      originY + float((primitiveNdx + 2) % 2) * primitiveSizeY, 0.0f,
                                                      1.0f),
                                            red};

                vertices.push_back(vertex);
                indices.push_back((uint32_t)vertices.size() - 1);
                indices.push_back(0);
            }
        }
        break;

    default:
        DE_ASSERT(false);
        break;
    }

    vertexData = vertices;
    indexData  = indices;
}

bool PrimitiveRestartTest::isRestartPrimitive(int primitiveIndex) const
{
    return std::find(m_restartPrimitives.begin(), m_restartPrimitives.end(), primitiveIndex) !=
           m_restartPrimitives.end();
}

// InputAssemblyInstance

InputAssemblyInstance::InputAssemblyInstance(Context &context, VkPrimitiveTopology primitiveTopology,
                                             bool testPrimitiveRestart, VkIndexType indexType,
                                             const std::vector<uint32_t> &indexBufferData,
                                             const std::vector<Vertex4RGBA> &vertexBufferData)

    : vkt::TestInstance(context)
    , m_primitiveTopology(primitiveTopology)
    , m_primitiveRestartEnable(testPrimitiveRestart)
    , m_indexType(indexType)
    , m_vertices(vertexBufferData)
    , m_indices(indexBufferData)
    , m_renderSize((primitiveTopology == VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN) ? tcu::UVec2(32, 32) : tcu::UVec2(64, 16))
    , m_colorFormat(VK_FORMAT_R8G8B8A8_UNORM)
{
    const DeviceInterface &vk       = context.getDeviceInterface();
    const VkDevice vkDevice         = context.getDevice();
    const uint32_t queueFamilyIndex = context.getUniversalQueueFamilyIndex();
    SimpleAllocator memAlloc(
        vk, vkDevice, getPhysicalDeviceMemoryProperties(context.getInstanceInterface(), context.getPhysicalDevice()));
    const VkComponentMapping componentMappingRGBA = {VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G,
                                                     VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_A};

    // Create color image
    {
        const VkImageCreateInfo colorImageParams = {
            VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,                                   // VkStructureType sType;
            DE_NULL,                                                               // const void* pNext;
            0u,                                                                    // VkImageCreateFlags flags;
            VK_IMAGE_TYPE_2D,                                                      // VkImageType imageType;
            m_colorFormat,                                                         // VkFormat format;
            {m_renderSize.x(), m_renderSize.y(), 1u},                              // VkExtent3D extent;
            1u,                                                                    // uint32_t mipLevels;
            1u,                                                                    // uint32_t arrayLayers;
            VK_SAMPLE_COUNT_1_BIT,                                                 // VkSampleCountFlagBits samples;
            VK_IMAGE_TILING_OPTIMAL,                                               // VkImageTiling tiling;
            VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT, // VkImageUsageFlags usage;
            VK_SHARING_MODE_EXCLUSIVE,                                             // VkSharingMode sharingMode;
            1u,                                                                    // uint32_t queueFamilyIndexCount;
            &queueFamilyIndex,        // const uint32_t* pQueueFamilyIndices;
            VK_IMAGE_LAYOUT_UNDEFINED // VkImageLayout initialLayout;
        };

        m_colorImageCreateInfo = colorImageParams;
        m_colorImage           = createImage(vk, vkDevice, &m_colorImageCreateInfo);

        // Allocate and bind color image memory
        m_colorImageAlloc =
            memAlloc.allocate(getImageMemoryRequirements(vk, vkDevice, *m_colorImage), MemoryRequirement::Any);
        VK_CHECK(vk.bindImageMemory(vkDevice, *m_colorImage, m_colorImageAlloc->getMemory(),
                                    m_colorImageAlloc->getOffset()));
    }

    // Create color attachment view
    {
        const VkImageViewCreateInfo colorAttachmentViewParams = {
            VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,    // VkStructureType sType;
            DE_NULL,                                     // const void* pNext;
            0u,                                          // VkImageViewCreateFlags flags;
            *m_colorImage,                               // VkImage image;
            VK_IMAGE_VIEW_TYPE_2D,                       // VkImageViewType viewType;
            m_colorFormat,                               // VkFormat format;
            componentMappingRGBA,                        // VkComponentMapping components;
            {VK_IMAGE_ASPECT_COLOR_BIT, 0u, 1u, 0u, 1u}, // VkImageSubresourceRange subresourceRange;
        };

        m_colorAttachmentView = createImageView(vk, vkDevice, &colorAttachmentViewParams);
    }

    // Create render pass
    m_renderPass = makeRenderPass(vk, vkDevice, m_colorFormat);

    // Create framebuffer
    {
        const VkFramebufferCreateInfo framebufferParams = {
            VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO, // VkStructureType sType;
            DE_NULL,                                   // const void* pNext;
            0u,                                        // VkFramebufferCreateFlags flags;
            *m_renderPass,                             // VkRenderPass renderPass;
            1u,                                        // uint32_t attachmentCount;
            &m_colorAttachmentView.get(),              // const VkImageView* pAttachments;
            (uint32_t)m_renderSize.x(),                // uint32_t width;
            (uint32_t)m_renderSize.y(),                // uint32_t height;
            1u                                         // uint32_t layers;
        };

        m_framebuffer = createFramebuffer(vk, vkDevice, &framebufferParams);
    }

    // Create pipeline layout
    {
        const VkPipelineLayoutCreateInfo pipelineLayoutParams = {
            VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO, // VkStructureType sType;
            DE_NULL,                                       // const void* pNext;
            0u,                                            // VkPipelineLayoutCreateFlags flags;
            0u,                                            // uint32_t setLayoutCount;
            DE_NULL,                                       // const VkDescriptorSetLayout* pSetLayouts;
            0u,                                            // uint32_t pushConstantRangeCount;
            DE_NULL                                        // const VkPushConstantRange* pPushConstantRanges;
        };

        m_pipelineLayout = createPipelineLayout(vk, vkDevice, &pipelineLayoutParams);
    }

    m_vertexShaderModule   = createShaderModule(vk, vkDevice, m_context.getBinaryCollection().get("color_vert"), 0);
    m_fragmentShaderModule = createShaderModule(vk, vkDevice, m_context.getBinaryCollection().get("color_frag"), 0);

    // Create pipeline
    {
        const VkPipelineShaderStageCreateInfo shaderStageParams[2] = {
            {
                VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, // VkStructureType sType;
                DE_NULL,                                             // const void* pNext;
                0u,                                                  // VkPipelineShaderStageCreateFlags flags;
                VK_SHADER_STAGE_VERTEX_BIT,                          // VkShaderStageFlagBits stage;
                *m_vertexShaderModule,                               // VkShaderModule module;
                "main",                                              // const char* pName;
                DE_NULL                                              // const VkSpecializationInfo* pSpecializationInfo;
            },
            {
                VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, // VkStructureType sType;
                DE_NULL,                                             // const void* pNext;
                0u,                                                  // VkPipelineShaderStageCreateFlags flags;
                VK_SHADER_STAGE_FRAGMENT_BIT,                        // VkShaderStageFlagBits stage;
                *m_fragmentShaderModule,                             // VkShaderModule module;
                "main",                                              // const char* pName;
                DE_NULL                                              // const VkSpecializationInfo* pSpecializationInfo;
            }};

        const VkVertexInputBindingDescription vertexInputBindingDescription = {
            0u,                         // uint32_t binding;
            sizeof(Vertex4RGBA),        // uint32_t stride;
            VK_VERTEX_INPUT_RATE_VERTEX // VkVertexInputRate inputRate;
        };

        const VkVertexInputAttributeDescription vertexInputAttributeDescriptions[2] = {
            {
                0u,                            // uint32_t location;
                0u,                            // uint32_t binding;
                VK_FORMAT_R32G32B32A32_SFLOAT, // VkFormat format;
                0u                             // uint32_t offset;
            },
            {
                1u,                            // uint32_t location;
                0u,                            // uint32_t binding;
                VK_FORMAT_R32G32B32A32_SFLOAT, // VkFormat format;
                offsetof(Vertex4RGBA, color),  // uint32_t offset;
            }};

        const VkPipelineVertexInputStateCreateInfo vertexInputStateParams = {
            VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO, // VkStructureType sType;
            DE_NULL,                                                   // const void* pNext;
            0u,                                                        // VkPipelineVertexInputStateCreateFlags flags;
            1u,                                                        // uint32_t vertexBindingDescriptionCount;
            &vertexInputBindingDescription,  // const VkVertexInputBindingDescription* pVertexBindingDescriptions;
            2u,                              // uint32_t vertexAttributeDescriptionCount;
            vertexInputAttributeDescriptions // const VkVertexInputAttributeDescription* pVertexAttributeDescriptions;
        };

        const VkPipelineInputAssemblyStateCreateInfo inputAssemblyStateParams = {
            VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO, // VkStructureType sType;
            DE_NULL,                                                     // const void* pNext;
            0u,                      // VkPipelineInputAssemblyStateCreateFlags flags;
            m_primitiveTopology,     // VkPrimitiveTopology topology;
            m_primitiveRestartEnable // VkBool32 primitiveRestartEnable;
        };

        const VkViewport viewport = makeViewport(m_renderSize);
        const VkRect2D scissor    = makeRect2D(m_renderSize);

        const VkPipelineViewportStateCreateInfo viewportStateParams = {
            VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO, // VkStructureType sType;
            DE_NULL,                                               // const void* pNext;
            0u,                                                    // VkPipelineViewportStateCreateFlags flags;
            1u,                                                    // uint32_t viewportCount;
            &viewport,                                             // const VkViewport* pViewports;
            1u,                                                    // uint32_t scissorCount;
            &scissor,                                              // const VkRect2D* pScissors;
        };

        const VkPipelineRasterizationStateCreateInfo rasterStateParams = {
            VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO, // VkStructureType sType;
            DE_NULL,                                                    // const void* pNext;
            0u,                              // VkPipelineRasterizationStateCreateFlags flags;
            false,                           // VkBool32 depthClampEnable;
            false,                           // VkBool32 rasterizerDiscardEnable;
            VK_POLYGON_MODE_FILL,            // VkPolygonMode polygonMode;
            VK_CULL_MODE_NONE,               // VkCullModeFlags cullMode;
            VK_FRONT_FACE_COUNTER_CLOCKWISE, // VkFrontFace frontFace;
            VK_FALSE,                        // VkBool32 depthBiasEnable;
            0.0f,                            // float depthBiasConstantFactor;
            0.0f,                            // float depthBiasClamp;
            0.0f,                            // float depthBiasSlopeFactor;
            1.0f                             // float lineWidth;
        };

        const VkPipelineColorBlendAttachmentState colorBlendAttachmentState = {
            false,                                                // VkBool32 blendEnable;
            VK_BLEND_FACTOR_ONE,                                  // VkBlendFactor srcColorBlendFactor;
            VK_BLEND_FACTOR_ZERO,                                 // VkBlendFactor dstColorBlendFactor;
            VK_BLEND_OP_ADD,                                      // VkBlendOp colorBlendOp;
            VK_BLEND_FACTOR_ONE,                                  // VkBlendFactor srcAlphaBlendFactor;
            VK_BLEND_FACTOR_ZERO,                                 // VkBlendFactor dstAlphaBlendFactor;
            VK_BLEND_OP_ADD,                                      // VkBlendOp alphaBlendOp;
            VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | // VkColorComponentFlags colorWriteMask;
                VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT};

        const VkPipelineColorBlendStateCreateInfo colorBlendStateParams = {
            VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO, // VkStructureType sType;
            DE_NULL,                                                  // const void* pNext;
            0u,                                                       // VkPipelineColorBlendStateCreateFlags flags;
            false,                                                    // VkBool32 logicOpEnable;
            VK_LOGIC_OP_COPY,                                         // VkLogicOp logicOp;
            1u,                                                       // uint32_t attachmentCount;
            &colorBlendAttachmentState, // const VkPipelineColorBlendAttachmentState* pAttachments;
            {0.0f, 0.0f, 0.0f, 0.0f}    // float blendConstants[4];
        };

        const VkPipelineMultisampleStateCreateInfo multisampleStateParams = {
            VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO, // VkStructureType sType;
            DE_NULL,                                                  // const void* pNext;
            0u,                                                       // VkPipelineMultisampleStateCreateFlags flags;
            VK_SAMPLE_COUNT_1_BIT,                                    // VkSampleCountFlagBits rasterizationSamples;
            false,                                                    // VkBool32 sampleShadingEnable;
            0.0f,                                                     // float minSampleShading;
            DE_NULL,                                                  // const VkSampleMask* pSampleMask;
            false,                                                    // VkBool32 alphaToCoverageEnable;
            false                                                     // VkBool32 alphaToOneEnable;
        };

        VkPipelineDepthStencilStateCreateInfo depthStencilStateParams = {
            VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO, // VkStructureType sType;
            DE_NULL,                                                    // const void* pNext;
            0u,                                                         // VkPipelineDepthStencilStateCreateFlags flags;
            false,                                                      // VkBool32 depthTestEnable;
            false,                                                      // VkBool32 depthWriteEnable;
            VK_COMPARE_OP_LESS,                                         // VkCompareOp depthCompareOp;
            false,                                                      // VkBool32 depthBoundsTestEnable;
            false,                                                      // VkBool32 stencilTestEnable;
            // VkStencilOpState front;
            {
                VK_STENCIL_OP_KEEP,  // VkStencilOp failOp;
                VK_STENCIL_OP_KEEP,  // VkStencilOp passOp;
                VK_STENCIL_OP_KEEP,  // VkStencilOp depthFailOp;
                VK_COMPARE_OP_NEVER, // VkCompareOp compareOp;
                0u,                  // uint32_t compareMask;
                0u,                  // uint32_t writeMask;
                0u,                  // uint32_t reference;
            },
            // VkStencilOpState back;
            {
                VK_STENCIL_OP_KEEP,  // VkStencilOp failOp;
                VK_STENCIL_OP_KEEP,  // VkStencilOp passOp;
                VK_STENCIL_OP_KEEP,  // VkStencilOp depthFailOp;
                VK_COMPARE_OP_NEVER, // VkCompareOp compareOp;
                0u,                  // uint32_t compareMask;
                0u,                  // uint32_t writeMask;
                0u,                  // uint32_t reference;
            },
            0.0f, // float minDepthBounds;
            1.0f  // float maxDepthBounds;
        };

        const VkGraphicsPipelineCreateInfo graphicsPipelineParams = {
            VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO, // VkStructureType sType;
            DE_NULL,                                         // const void* pNext;
            0u,                                              // VkPipelineCreateFlags flags;
            2u,                                              // uint32_t stageCount;
            shaderStageParams,                               // const VkPipelineShaderStageCreateInfo* pStages;
            &vertexInputStateParams,   // const VkPipelineVertexInputStateCreateInfo* pVertexInputState;
            &inputAssemblyStateParams, // const VkPipelineInputAssemblyStateCreateInfo* pInputAssemblyState;
            DE_NULL,                   // const VkPipelineTessellationStateCreateInfo* pTessellationState;
            &viewportStateParams,      // const VkPipelineViewportStateCreateInfo* pViewportState;
            &rasterStateParams,        // const VkPipelineRasterizationStateCreateInfo* pRasterizationState;
            &multisampleStateParams,   // const VkPipelineMultisampleStateCreateInfo* pMultisampleState;
            &depthStencilStateParams,  // const VkPipelineDepthStencilStateCreateInfo* pDepthStencilState;
            &colorBlendStateParams,    // const VkPipelineColorBlendStateCreateInfo* pColorBlendState;
            (const VkPipelineDynamicStateCreateInfo *)DE_NULL, // const VkPipelineDynamicStateCreateInfo* pDynamicState;
            *m_pipelineLayout,                                 // VkPipelineLayout layout;
            *m_renderPass,                                     // VkRenderPass renderPass;
            0u,                                                // uint32_t subpass;
            0u,                                                // VkPipeline basePipelineHandle;
            0u                                                 // int32_t basePipelineIndex;
        };

        m_graphicsPipeline = createGraphicsPipeline(vk, vkDevice, DE_NULL, &graphicsPipelineParams);
    }

    // Create vertex and index buffer
    {
        const VkBufferCreateInfo indexBufferParams = {
            VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO, // VkStructureType sType;
            DE_NULL,                              // const void* pNext;
            0u,                                   // VkBufferCreateFlags flags;
            m_indices.size() * sizeof(uint32_t),  // VkDeviceSize size;
            VK_BUFFER_USAGE_INDEX_BUFFER_BIT,     // VkBufferUsageFlags usage;
            VK_SHARING_MODE_EXCLUSIVE,            // VkSharingMode sharingMode;
            1u,                                   // uint32_t queueFamilyIndexCount;
            &queueFamilyIndex                     // const uint32_t* pQueueFamilyIndices;
        };

        const VkBufferCreateInfo vertexBufferParams = {
            VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,    // VkStructureType sType;
            DE_NULL,                                 // const void* pNext;
            0u,                                      // VkBufferCreateFlags flags;
            m_vertices.size() * sizeof(Vertex4RGBA), // VkDeviceSize size;
            VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,       // VkBufferUsageFlags usage;
            VK_SHARING_MODE_EXCLUSIVE,               // VkSharingMode sharingMode;
            1u,                                      // uint32_t queueFamilyIndexCount;
            &queueFamilyIndex                        // const uint32_t* pQueueFamilyIndices;
        };

        m_indexBuffer      = createBuffer(vk, vkDevice, &indexBufferParams);
        m_indexBufferAlloc = memAlloc.allocate(getBufferMemoryRequirements(vk, vkDevice, *m_indexBuffer),
                                               MemoryRequirement::HostVisible);

        VK_CHECK(vk.bindBufferMemory(vkDevice, *m_indexBuffer, m_indexBufferAlloc->getMemory(),
                                     m_indexBufferAlloc->getOffset()));

        m_vertexBuffer      = createBuffer(vk, vkDevice, &vertexBufferParams);
        m_vertexBufferAlloc = memAlloc.allocate(getBufferMemoryRequirements(vk, vkDevice, *m_vertexBuffer),
                                                MemoryRequirement::HostVisible);

        VK_CHECK(vk.bindBufferMemory(vkDevice, *m_vertexBuffer, m_vertexBufferAlloc->getMemory(),
                                     m_vertexBufferAlloc->getOffset()));

        // Load vertices into index buffer
        if (m_indexType == VK_INDEX_TYPE_UINT32)
        {
            deMemcpy(m_indexBufferAlloc->getHostPtr(), m_indices.data(), m_indices.size() * sizeof(uint32_t));
        }
        else if (m_indexType == VK_INDEX_TYPE_UINT8_EXT)
        {
            uploadIndexBufferData8((uint8_t *)m_indexBufferAlloc->getHostPtr(), m_indices);
        }
        else // m_indexType == VK_INDEX_TYPE_UINT16
        {
            uploadIndexBufferData16((uint16_t *)m_indexBufferAlloc->getHostPtr(), m_indices);
        }

        // Load vertices into vertex buffer
        deMemcpy(m_vertexBufferAlloc->getHostPtr(), m_vertices.data(), m_vertices.size() * sizeof(Vertex4RGBA));

        flushAlloc(vk, vkDevice, *m_indexBufferAlloc);
        flushAlloc(vk, vkDevice, *m_vertexBufferAlloc);
    }

    // Create command pool
    m_cmdPool = createCommandPool(vk, vkDevice, VK_COMMAND_POOL_CREATE_TRANSIENT_BIT, queueFamilyIndex);

    // Create command buffer
    {
        const VkClearValue attachmentClearValue = defaultClearValue(m_colorFormat);

        const VkImageMemoryBarrier attachmentLayoutBarrier = {
            VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,      // VkStructureType sType;
            DE_NULL,                                     // const void* pNext;
            0u,                                          // VkAccessFlags srcAccessMask;
            VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,        // VkAccessFlags dstAccessMask;
            VK_IMAGE_LAYOUT_UNDEFINED,                   // VkImageLayout oldLayout;
            VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,    // VkImageLayout newLayout;
            VK_QUEUE_FAMILY_IGNORED,                     // uint32_t srcQueueFamilyIndex;
            VK_QUEUE_FAMILY_IGNORED,                     // uint32_t dstQueueFamilyIndex;
            *m_colorImage,                               // VkImage image;
            {VK_IMAGE_ASPECT_COLOR_BIT, 0u, 1u, 0u, 1u}, // VkImageSubresourceRange subresourceRange;
        };

        m_cmdBuffer = allocateCommandBuffer(vk, vkDevice, *m_cmdPool, VK_COMMAND_BUFFER_LEVEL_PRIMARY);

        beginCommandBuffer(vk, *m_cmdBuffer, 0u);

        vk.cmdPipelineBarrier(*m_cmdBuffer, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                              VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, (VkDependencyFlags)0, 0u, DE_NULL, 0u,
                              DE_NULL, 1u, &attachmentLayoutBarrier);

        beginRenderPass(vk, *m_cmdBuffer, *m_renderPass, *m_framebuffer,
                        makeRect2D(0, 0, m_renderSize.x(), m_renderSize.y()), attachmentClearValue);

        const VkDeviceSize vertexBufferOffset = 0;

        vk.cmdBindPipeline(*m_cmdBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, *m_graphicsPipeline);
        vk.cmdBindVertexBuffers(*m_cmdBuffer, 0, 1, &m_vertexBuffer.get(), &vertexBufferOffset);
        vk.cmdBindIndexBuffer(*m_cmdBuffer, *m_indexBuffer, 0, m_indexType);
        vk.cmdDrawIndexed(*m_cmdBuffer, (uint32_t)m_indices.size(), 1, 0, 0, 0);

        endRenderPass(vk, *m_cmdBuffer);
        endCommandBuffer(vk, *m_cmdBuffer);
    }
}

InputAssemblyInstance::~InputAssemblyInstance(void)
{
}

tcu::TestStatus InputAssemblyInstance::iterate(void)
{
    const DeviceInterface &vk = m_context.getDeviceInterface();
    const VkDevice vkDevice   = m_context.getDevice();
    const VkQueue queue       = m_context.getUniversalQueue();

    submitCommandsAndWait(vk, vkDevice, queue, m_cmdBuffer.get());

    return verifyImage();
}

tcu::TestStatus InputAssemblyInstance::verifyImage(void)
{
    const tcu::TextureFormat tcuColorFormat   = mapVkFormat(m_colorFormat);
    const tcu::TextureFormat tcuStencilFormat = tcu::TextureFormat();
    const ColorVertexShader vertexShader;
    const ColorFragmentShader fragmentShader(tcuColorFormat, tcuStencilFormat);
    const rr::Program program(&vertexShader, &fragmentShader);
    ReferenceRenderer refRenderer(m_renderSize.x(), m_renderSize.y(), 1, tcuColorFormat, tcuStencilFormat, &program);
    bool compareOk = false;

    // Render reference image
    {
        const rr::PrimitiveType topology = mapVkPrimitiveTopology(m_primitiveTopology);
        rr::RenderState renderState(refRenderer.getViewportState(),
                                    m_context.getDeviceProperties().limits.subPixelPrecisionBits);

        if (m_primitiveTopology == VK_PRIMITIVE_TOPOLOGY_POINT_LIST)
            renderState.point.pointSize = 3.0f;

        if (m_primitiveRestartEnable)
        {
            std::vector<uint32_t> indicesRange;

            for (size_t indexNdx = 0; indexNdx < m_indices.size(); indexNdx++)
            {
                const bool isRestart = InputAssemblyTest::isRestartIndex(m_indexType, m_indices[indexNdx]);

                if (!isRestart)
                    indicesRange.push_back(m_indices[indexNdx]);

                if (isRestart || indexNdx == (m_indices.size() - 1))
                {
                    // Draw the range of indices found so far

                    std::vector<Vertex4RGBA> nonIndexedVertices;
                    for (size_t i = 0; i < indicesRange.size(); i++)
                        nonIndexedVertices.push_back(m_vertices[indicesRange[i]]);

                    refRenderer.draw(renderState, topology, nonIndexedVertices);
                    indicesRange.clear();
                }
            }
        }
        else
        {
            std::vector<Vertex4RGBA> nonIndexedVertices;
            for (size_t i = 0; i < m_indices.size(); i++)
                nonIndexedVertices.push_back(m_vertices[m_indices[i]]);

            refRenderer.draw(renderState, topology, nonIndexedVertices);
        }
    }

    // Compare result with reference image
    {
        const DeviceInterface &vk       = m_context.getDeviceInterface();
        const VkDevice vkDevice         = m_context.getDevice();
        const VkQueue queue             = m_context.getUniversalQueue();
        const uint32_t queueFamilyIndex = m_context.getUniversalQueueFamilyIndex();
        SimpleAllocator allocator(
            vk, vkDevice,
            getPhysicalDeviceMemoryProperties(m_context.getInstanceInterface(), m_context.getPhysicalDevice()));
        de::UniquePtr<tcu::TextureLevel> result(readColorAttachment(vk, vkDevice, queue, queueFamilyIndex, allocator,
                                                                    *m_colorImage, m_colorFormat, m_renderSize)
                                                    .release());

        compareOk = tcu::intThresholdPositionDeviationCompare(
            m_context.getTestContext().getLog(), "IntImageCompare", "Image comparison", refRenderer.getAccess(),
            result->getAccess(), tcu::UVec4(2, 2, 2, 2), tcu::IVec3(1, 1, 0), true, tcu::COMPARE_LOG_RESULT);
    }

    if (compareOk)
        return tcu::TestStatus::pass("Result image matches reference");
    else
        return tcu::TestStatus::fail("Image mismatch");
}

void InputAssemblyInstance::uploadIndexBufferData16(uint16_t *destPtr, const std::vector<uint32_t> &indexBufferData)
{
    for (size_t i = 0; i < indexBufferData.size(); i++)
    {
        DE_ASSERT(indexBufferData[i] <= 0xFFFF);
        destPtr[i] = (uint16_t)indexBufferData[i];
    }
}

void InputAssemblyInstance::uploadIndexBufferData8(uint8_t *destPtr, const std::vector<uint32_t> &indexBufferData)
{
    for (size_t i = 0; i < indexBufferData.size(); i++)
    {
        DE_ASSERT(indexBufferData[i] <= 0xFF);
        destPtr[i] = (uint8_t)indexBufferData[i];
    }
}

// Utilities for test names

std::string getPrimitiveTopologyCaseName(VkPrimitiveTopology topology)
{
    const std::string fullName = getPrimitiveTopologyName(topology);

    DE_ASSERT(de::beginsWith(fullName, "VK_PRIMITIVE_TOPOLOGY_"));

    return de::toLower(fullName.substr(22));
}

de::MovePtr<tcu::TestCaseGroup> createPrimitiveTopologyTests(tcu::TestContext &testCtx)
{
    de::MovePtr<tcu::TestCaseGroup> primitiveTopologyTests(new tcu::TestCaseGroup(testCtx, "primitive_topology", ""));

    de::MovePtr<tcu::TestCaseGroup> indexUint16Tests(new tcu::TestCaseGroup(testCtx, "index_type_uint16", ""));
    de::MovePtr<tcu::TestCaseGroup> indexUint32Tests(new tcu::TestCaseGroup(testCtx, "index_type_uint32", ""));
    de::MovePtr<tcu::TestCaseGroup> indexUint8Tests(new tcu::TestCaseGroup(testCtx, "index_type_uint8", ""));

    for (int topologyNdx = 0; topologyNdx < DE_LENGTH_OF_ARRAY(InputAssemblyTest::s_primitiveTopologies); topologyNdx++)
    {
        const VkPrimitiveTopology topology = InputAssemblyTest::s_primitiveTopologies[topologyNdx];

        indexUint16Tests->addChild(new PrimitiveTopologyTest(testCtx, getPrimitiveTopologyCaseName(topology), "",
                                                             topology, VK_INDEX_TYPE_UINT16));

        indexUint32Tests->addChild(new PrimitiveTopologyTest(testCtx, getPrimitiveTopologyCaseName(topology), "",
                                                             topology, VK_INDEX_TYPE_UINT32));

        indexUint8Tests->addChild(new PrimitiveTopologyTest(testCtx, getPrimitiveTopologyCaseName(topology), "",
                                                            topology, VK_INDEX_TYPE_UINT8_EXT));
    }

    primitiveTopologyTests->addChild(indexUint16Tests.release());
    primitiveTopologyTests->addChild(indexUint32Tests.release());
    primitiveTopologyTests->addChild(indexUint8Tests.release());

    return primitiveTopologyTests;
}

de::MovePtr<tcu::TestCaseGroup> createPrimitiveRestartTests(tcu::TestContext &testCtx)
{
    const VkPrimitiveTopology primitiveRestartTopologies[] = {
        VK_PRIMITIVE_TOPOLOGY_LINE_STRIP, VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP, VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN,
        VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY, VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY};

    de::MovePtr<tcu::TestCaseGroup> primitiveRestartTests(
        new tcu::TestCaseGroup(testCtx, "primitive_restart", "Restarts indices of "));

    de::MovePtr<tcu::TestCaseGroup> indexUint16Tests(new tcu::TestCaseGroup(testCtx, "index_type_uint16", ""));
    de::MovePtr<tcu::TestCaseGroup> indexUint32Tests(new tcu::TestCaseGroup(testCtx, "index_type_uint32", ""));
    de::MovePtr<tcu::TestCaseGroup> indexUint8Tests(new tcu::TestCaseGroup(testCtx, "index_type_uint8", ""));

    for (int topologyNdx = 0; topologyNdx < DE_LENGTH_OF_ARRAY(primitiveRestartTopologies); topologyNdx++)
    {
        const VkPrimitiveTopology topology = primitiveRestartTopologies[topologyNdx];

        indexUint16Tests->addChild(new PrimitiveRestartTest(testCtx, getPrimitiveTopologyCaseName(topology), "",
                                                            topology, VK_INDEX_TYPE_UINT16));

        indexUint32Tests->addChild(new PrimitiveRestartTest(testCtx, getPrimitiveTopologyCaseName(topology), "",
                                                            topology, VK_INDEX_TYPE_UINT32));

        indexUint8Tests->addChild(new PrimitiveRestartTest(testCtx, getPrimitiveTopologyCaseName(topology), "",
                                                           topology, VK_INDEX_TYPE_UINT8_EXT));
    }

    primitiveRestartTests->addChild(indexUint16Tests.release());
    primitiveRestartTests->addChild(indexUint32Tests.release());
    primitiveRestartTests->addChild(indexUint8Tests.release());

    return primitiveRestartTests;
}

} // namespace

tcu::TestCaseGroup *createInputAssemblyTests(tcu::TestContext &testCtx)
{
    de::MovePtr<tcu::TestCaseGroup> inputAssemblyTests(
        new tcu::TestCaseGroup(testCtx, "input_assembly", "Input assembly tests"));

    inputAssemblyTests->addChild(createPrimitiveTopologyTests(testCtx).release());
    inputAssemblyTests->addChild(createPrimitiveRestartTests(testCtx).release());

    return inputAssemblyTests.release();
}

} // namespace pipeline
} // namespace vkt
