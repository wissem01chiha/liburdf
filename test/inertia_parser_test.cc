#include "internal/inertia_parser.h"

#include <gtest/gtest.h>

TEST(InertiaParserTest, GlobalParseTest) {
  const char* xmlString = R"(
      <inertial>
        <origin xyz="0 0 0.5" rpy="0 0 0"/>
        <mass value="1.2568"/>
        <inertia ixx="100"  ixy="0.28"  ixz="4.25" iyy="10" iyz="0" izz="100" />
      </inertial>
  )";

  tinyxml2::XMLDocument doc;
  ASSERT_EQ(doc.Parse(xmlString), tinyxml2::XML_SUCCESS);
  tinyxml2::XMLElement* element = doc.FirstChildElement("inertial");

  InertiaParser ip;
  ip.parse(element);
  std::cout << ip.toString();
}

TEST(InertiaParserTest, ParseInertialPoseTest) {
  const char* xmlString = R"(
      <?xml version="1.0"?>
      <robot name="r6_inertial_rpy">
        <link name="a">
          <inertial>
            <origin xyz="0.1 0.2 0.3" rpy="1.5707963267948966 0 0"/>
            <mass value="1"/>
            <inertia ixx="1" ixy="0" ixz="0" iyy="2" iyz="0" izz="3"/>
          </inertial>
        </link>
      </robot>
      )";

  tinyxml2::XMLDocument doc;
  ASSERT_EQ(doc.Parse(xmlString), tinyxml2::XML_SUCCESS);
  tinyxml2::XMLElement* element = doc.FirstChildElement("robot")
                                      ->FirstChildElement("link")
                                      ->FirstChildElement("inertial");

  InertiaParser ip;
  ASSERT_EQ(ip.parse(element), 0);
  std::shared_ptr<Inertia> inertia = ip.get();
  double origin[3];
  inertia->getOrigin(origin);
  EXPECT_NEAR(origin[0], 0.1, 1e-6);
  EXPECT_NEAR(origin[1], 0.2, 1e-6);
  EXPECT_NEAR(origin[2], 0.3, 1e-6);

  double rpy[3];
  inertia->getRotation(rpy);
  EXPECT_NEAR(rpy[0], 1.5707963267948966, 1e-6);
  EXPECT_NEAR(rpy[1], 0, 1e-6);
  EXPECT_NEAR(rpy[2], 0, 1e-6);
  EXPECT_NEAR(inertia->getMass(), 1, 1e-6);
  EXPECT_NEAR(inertia->getIxx(), 1, 1e-6);
  EXPECT_NEAR(inertia->getIxy(), 0, 1e-6);
  EXPECT_NEAR(inertia->getIxz(), 0, 1e-6);
  EXPECT_NEAR(inertia->getIyy(), 2, 1e-6);
  EXPECT_NEAR(inertia->getIyz(), 0, 1e-6);
  EXPECT_NEAR(inertia->getIzz(), 3, 1e-6);
}
