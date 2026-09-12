
#include "internal/urdf_parser.h"

#include <gtest/gtest.h>
#include <loguru/loguru.hpp>

void InitializeLogging() {
  static const bool initialized = [] {
    char program_name[] = "urdf_parser_test";
    char* argv[] = {program_name, nullptr};
    int argc = 1;
    loguru::g_stderr_verbosity = loguru::Verbosity_WARNING;
    loguru::init(argc, argv);
    return true;
  }();
  (void)initialized;
}

TEST(URDFParserTest, ParseValidURDF) {
  InitializeLogging();

  URDFParser parser;
  ASSERT_EQ(parser.parse("./test/assets/onrobot_rg6_model.urdf"), 0);

  const auto model = parser.get();
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->getName(), "onrobot_rg6_model");
  EXPECT_FALSE(model->getLinks().empty());
}

TEST(URDFParserTest, EmptyValues) {
  InitializeLogging();

  URDFParser parser;

  EXPECT_TRUE(parser.empty());
  EXPECT_TRUE(parser.isA("model"));
  EXPECT_STREQ(parser.getTypename(), "model");
}

