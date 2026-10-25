#include "internal/link_parser.h"

#include <gtest/gtest.h>

TEST(LinkParserTest, ParserTest) {
  tinyxml2::XMLDocument doc;
  tinyxml2::XMLError eResult = doc.LoadFile("./test/assets/simple_test.urdf");
  if (eResult != tinyxml2::XML_SUCCESS) {
    std::cerr << "Error loading XML file: " << doc.ErrorStr() << std::endl;
  }

  LinkParser parser;
  const tinyxml2::XMLElement* xml = doc.FirstChildElement("model");
  parser.parse(xml->FirstChildElement("link"));
  std::cout << parser.toString();
  const auto linkdata = parser.get();
  auto link_collison = linkdata->getCollision();
  std::cout << link_collison->toString();

  ASSERT_NE(linkdata, nullptr);
  EXPECT_NE(linkdata->getInertia(), nullptr);
  EXPECT_NE(linkdata->getVisual(), nullptr);
  EXPECT_NE(linkdata->getCollision(), nullptr);
};

TEST(LinkParserTest, ParseMultipleVisualsAndCollisions) {
  tinyxml2::XMLDocument doc;
  tinyxml2::XMLError eResult = doc.LoadFile("./test/assets/r9_multi_geom.urdf");
  ASSERT_EQ(eResult, tinyxml2::XML_SUCCESS) << doc.ErrorStr();

  const tinyxml2::XMLElement* robot = doc.FirstChildElement("robot");
  ASSERT_NE(robot, nullptr);
  const tinyxml2::XMLElement* link = robot->FirstChildElement("link");
  ASSERT_NE(link, nullptr);

  LinkParser parser;
  ASSERT_EQ(parser.parse(link), 0);
  const auto linkdata = parser.get();
  ASSERT_NE(linkdata, nullptr);

  const auto visuals = linkdata->getVisuals();
  ASSERT_EQ(visuals.size(), 2);
  EXPECT_TRUE(visuals[0]->getGeometry()->isA("box"));
  EXPECT_TRUE(visuals[1]->getGeometry()->isA("sphere"));
  EXPECT_EQ(linkdata->getVisual(), visuals[0]);
  EXPECT_DOUBLE_EQ(visuals[0]->getPose()->getPosition()[0], 1);
  EXPECT_DOUBLE_EQ(visuals[1]->getPose()->getPosition()[0], 2);

  const auto collisions = linkdata->getCollisions();
  ASSERT_EQ(collisions.size(), 2);
  EXPECT_TRUE(collisions[0]->getGeometry()->isA("box"));
  EXPECT_TRUE(collisions[1]->getGeometry()->isA("sphere"));
  EXPECT_EQ(linkdata->getCollision(), collisions[0]);
  EXPECT_DOUBLE_EQ(collisions[0]->getPose()->getPosition()[0], 1);
  EXPECT_DOUBLE_EQ(collisions[1]->getPose()->getPosition()[0], 2);
}

TEST(LinkParserTest, OptionalBlocksAreAbsentWhenOmitted) {
  tinyxml2::XMLDocument populated_doc;
  ASSERT_EQ(populated_doc.LoadFile("./test/assets/r9_multi_geom.urdf"),
            tinyxml2::XML_SUCCESS)
      << populated_doc.ErrorStr();
  const tinyxml2::XMLElement* populated_robot =
      populated_doc.FirstChildElement("robot");
  ASSERT_NE(populated_robot, nullptr);

  LinkParser link_parser;
  ASSERT_EQ(link_parser.parse(populated_robot->FirstChildElement("link")), 0);
  ASSERT_EQ(link_parser.get()->getVisuals().size(), 2);

  tinyxml2::XMLDocument doc;
  ASSERT_EQ(doc.LoadFile("./test/assets/r7_absent_blocks.urdf"),
            tinyxml2::XML_SUCCESS)
      << doc.ErrorStr();

  const tinyxml2::XMLElement* robot = doc.FirstChildElement("robot");
  ASSERT_NE(robot, nullptr);
  const tinyxml2::XMLElement* link_xml = robot->FirstChildElement("link");
  size_t link_count = 0;
  for (; link_xml; link_xml = link_xml->NextSiblingElement("link")) {
    ASSERT_EQ(link_parser.parse(link_xml), 0);
    const auto link = link_parser.get();
    ASSERT_NE(link, nullptr);
    EXPECT_EQ(link->getInertia(), nullptr);
    EXPECT_EQ(link->getVisual(), nullptr);
    EXPECT_EQ(link->getVisuals().size(), 0);
    EXPECT_EQ(link->getCollision(), nullptr);
    EXPECT_EQ(link->getCollisions().size(), 0);
    EXPECT_EQ(link->getMaterial(), nullptr);
    ++link_count;
  }
  EXPECT_EQ(link_count, 2);
}