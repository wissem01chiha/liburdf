#include "internal/mesh_parser.h"

#include <gtest/gtest.h>

TEST(MeshParserTest, ParseMeshLowScaleTest) {

    const char* xmlContent = R"(
            <mesh filename="package://demo/meshes/part.stl" scale="0.001 0.001 0.001"/>
        )";
    
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError error = doc.Parse(xmlContent);
    ASSERT_EQ(error, tinyxml2::XML_SUCCESS);
    
    MeshParser parser;
    ASSERT_EQ(parser.parse(doc.FirstChildElement("mesh")),0);
    
    auto mesh = parser.get();
    ASSERT_NE(mesh, nullptr);
    // check the links scales are fetched correctly
    EXPECT_DOUBLE_EQ(mesh->getScale()[0], 0.001);
    EXPECT_DOUBLE_EQ(mesh->getScale()[1], 0.001);
    EXPECT_DOUBLE_EQ(mesh->getScale()[2], 0.001);
}

TEST(MeshParserTest, ParseMeshUpperScaleTest) {

    const char* xmlContent = R"(
            <mesh filename="package://demo/meshes/part.stl" scale="1000 1000 1000"/>
        )";
    
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError error = doc.Parse(xmlContent);
    ASSERT_EQ(error, tinyxml2::XML_SUCCESS);
    
    MeshParser parser;
    ASSERT_EQ(parser.parse(doc.FirstChildElement("mesh")),0);
    
    auto mesh = parser.get();
    ASSERT_NE(mesh, nullptr);
    // check the links scales are fetched correctly
    EXPECT_DOUBLE_EQ(mesh->getScale()[0], 1000);
    EXPECT_DOUBLE_EQ(mesh->getScale()[1], 1000);
    EXPECT_DOUBLE_EQ(mesh->getScale()[2], 1000);
}