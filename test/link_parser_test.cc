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