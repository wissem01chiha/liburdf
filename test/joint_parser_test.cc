#include "internal/joint_parser.h"

#include <gtest/gtest.h>

TEST(JointParserTest, ConstrutorTest) {
  tinyxml2::XMLDocument doc;
  tinyxml2::XMLError eResult = doc.LoadFile("./test/assets/joint2.urdf");
  if (eResult != tinyxml2::XML_SUCCESS) {
    std::cerr << "Error loading XML file: " << doc.ErrorStr() << std::endl;
  }

  JointParser parser;
  parser.parse(doc.FirstChildElement("joint"));
  std::cout << parser.toString();
  auto parsedData = parser.get();
  ASSERT_EQ(parsedData->isA("joint"), true);
  ASSERT_EQ(std::string(parsedData->getName()), "front_rail_joint");
  auto t = parsedData->getTransform();
  ASSERT_EQ(t.empty(), false);
};

TEST(JointParserTest, ParsesPresentOptionalBlocks) {
  tinyxml2::XMLDocument doc;
  ASSERT_EQ(doc.Parse("<joint name='j' type='revolute'>"
                      "<dynamics damping='0.1' friction='0.2'/>"
                      "<limit effort='3' velocity='4' lower='-1' upper='1'/>"
                      "<safety_controller soft_upper_limit='0.9' "
                      "soft_lower_limit='-0.9' k_position='10' k_velocity='2'/>"
                      "<calibration rising='0.8' falling='-0.8' "
                      "reference_position='0.1'/>"
                      "<mimic joint='2' multiplier='2' offset='1'/>"
                      "</joint>"),
            tinyxml2::XML_SUCCESS)
      << doc.ErrorStr();

  JointParser parser;
  ASSERT_EQ(parser.parse(doc.FirstChildElement("joint")), 0);
  const auto joint = parser.get();
  ASSERT_NE(joint, nullptr);
  EXPECT_NE(joint->getDynamics(), nullptr);
  EXPECT_NE(joint->getLimits(), nullptr);
  EXPECT_NE(joint->getSafety(), nullptr);
  EXPECT_NE(joint->getCalibration(), nullptr);
  EXPECT_NE(joint->getMimic(), nullptr);
}

TEST(JointParserTest, OptionalBlocksAreAbsentWhenOmitted) {
  tinyxml2::XMLDocument populated_doc;
  ASSERT_EQ(populated_doc.Parse("<joint name='j' type='revolute'>"
                                "<dynamics damping='0.1' friction='0.2'/>"
                                "<mimic joint='2' multiplier='2' offset='1'/>"
                                "</joint>"),
            tinyxml2::XML_SUCCESS)
      << populated_doc.ErrorStr();

  JointParser parser;
  ASSERT_EQ(parser.parse(populated_doc.FirstChildElement("joint")), 0);
  ASSERT_NE(parser.get()->getDynamics(), nullptr);
  ASSERT_NE(parser.get()->getMimic(), nullptr);

  tinyxml2::XMLDocument doc;
  ASSERT_EQ(doc.LoadFile("./test/assets/r7_absent_blocks.urdf"),
            tinyxml2::XML_SUCCESS)
      << doc.ErrorStr();

  const tinyxml2::XMLElement* robot = doc.FirstChildElement("robot");
  ASSERT_NE(robot, nullptr);
  const tinyxml2::XMLElement* joint_xml = robot->FirstChildElement("joint");
  ASSERT_NE(joint_xml, nullptr);

  ASSERT_EQ(parser.parse(joint_xml), 0);
  const auto joint = parser.get();
  ASSERT_NE(joint, nullptr);
  EXPECT_EQ(joint->getDynamics(), nullptr);
  EXPECT_EQ(joint->getLimits(), nullptr);
  EXPECT_EQ(joint->getSafety(), nullptr);
  EXPECT_EQ(joint->getCalibration(), nullptr);
  EXPECT_EQ(joint->getMimic(), nullptr);
  EXPECT_EQ(joint->toString().find("Mimic"), std::string::npos);
}
