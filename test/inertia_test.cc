#include "core/inertia.h"

#include <gtest/gtest.h>

TEST(InertiaTest, GetOriginTest) {
  Inertia i(1, 1, 0, 0, 1, 0, 1);
  double o[3] = {0, 0, 0};
  i.getOrigin(o);
  EXPECT_EQ(o[0], 0.0);
  EXPECT_EQ(o[1], 0.0);
  EXPECT_EQ(o[2], 0.0);
}

TEST(InertiaTest, GetQuatRotationTest) {
  Inertia i;
  i.setRotation(0.0, 0.0, 0.0, 1.0);
  Rot3 r = i.getRotation();
  EXPECT_EQ(r.coeffs()[0], 0.0);
  EXPECT_EQ(r.coeffs()[1], 0.0);
  EXPECT_EQ(r.coeffs()[2], 0.0);
  EXPECT_EQ(r.coeffs()[3], 1.0);
}

TEST(InertiaTest, GetRpyRotationTest) {
  Inertia i;
  i.setRotation(0.2, 0.3, 0.4);
  double rpy[3] = {0, 0, 0};
  i.getRotation(rpy);
  EXPECT_NEAR(rpy[0], 0.2, 1e-6);
  EXPECT_NEAR(rpy[1], 0.3, 1e-6);
  EXPECT_NEAR(rpy[2], 0.4, 1e-6);
}