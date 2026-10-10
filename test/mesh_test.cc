#include "core/mesh.h"

#include <gtest/gtest.h>

class MeshTest : public ::testing::Test {
 protected:
  Mesh mesh;
};

TEST_F(MeshTest, print) {
  mesh.setColor(1.0, 0.5, 0.25, 1.0);
  mesh.setFilename("../test/valid_path.txt");
  mesh.setScale(0.5, 0.5, 0.5);

  std::cout << mesh.toString();
}

TEST_F(MeshTest, setScaleNegative) {
  mesh.setScale(-1.0, 0.5, 0.5);
  EXPECT_EQ(mesh.getScale()[0], 1.0);
  EXPECT_EQ(mesh.getScale()[1], 1.0);
  EXPECT_EQ(mesh.getScale()[2], 1.0);
}

TEST_F(MeshTest, setScaleZero) {
  mesh.setScale(0.0, 0.0, 0.0);
  EXPECT_EQ(mesh.getScale()[0], 0.0);
  EXPECT_EQ(mesh.getScale()[1], 0.0);
  EXPECT_EQ(mesh.getScale()[2], 0.0);
}

TEST_F(MeshTest, setScalePositive) {
  mesh.setScale(0.5, 0.5, 0.5);
  EXPECT_EQ(mesh.getScale()[0], 0.5);
  EXPECT_EQ(mesh.getScale()[1], 0.5);
  EXPECT_EQ(mesh.getScale()[2], 0.5);
}