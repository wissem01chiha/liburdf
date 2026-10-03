#include "core/inertia.h"

#include <gtest/gtest.h>

TEST(InertiaTest, getOriginTest) {
  Inertia i(1, 1, 0, 0, 1, 0, 1);
  double o[3] = {0, 0, 0};
  i.getOrigin(o);
  EXPECT_EQ(o[0], 0.0);
  EXPECT_EQ(o[1], 0.0);
  EXPECT_EQ(o[2], 0.0);
}