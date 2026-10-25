#include "internal/color_parser.h"

#include <gtest/gtest.h>

TEST(ColorParserTest, ValidRgbaAttributeParserTest) {
  const char* xmlContent = R"(
                <color rgba="1.0 0.01 0.0 1.0"/>
            )";

  tinyxml2::XMLDocument doc;
  ASSERT_EQ(doc.Parse(xmlContent), tinyxml2::XML_SUCCESS);

  ColorParser parser;
  parser.parse(doc.FirstChildElement("color"));
  std::cout << parser.toString();

  auto parsedData = parser.get();
  ASSERT_NE(parsedData, nullptr);
  ASSERT_EQ(parsedData->isA("color"), true);
}