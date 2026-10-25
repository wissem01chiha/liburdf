#include "internal/version_parser.h"

#include <gtest/gtest.h>

TEST(VersionParserTest, ParseDoubleQuotedVersion) {
  VersionParser parser;
  tinyxml2::XMLDocument doc;
  doc.Parse("<?xml version=\"1.0\"?>");
  ASSERT_EQ(parser.parse(doc), 0);
  const auto version = parser.get();
  ASSERT_NE(version, nullptr);
  EXPECT_TRUE(version->equal(1.0, 0.0));
}