#include <gtest/gtest.h>
#include "core/camera.h"
#include "core/pose.h"
#include "core/image.h"

TEST(CameraTest, DefaultConstructor) {
    Camera camera;
    EXPECT_EQ(camera.getType(), Camera::Type::B8G8R8);
    EXPECT_EQ(camera.getHfov(), 1.0);
    EXPECT_EQ(camera.getNear(), 1.0);
    EXPECT_EQ(camera.getFar(), 1.0);
    EXPECT_EQ(camera.getUpdateRate(), 1.0);
    EXPECT_TRUE(camera.empty());
    EXPECT_TRUE(camera.isA("camera"));
}

TEST(CameraTest, CopyConstructor) {
    Camera cam1;
    cam1.setHfov(2.0);
    cam1.setNear(0.5);
    cam1.setFar(10.0);
    cam1.setType(Camera::Type::R8G8B8);

    Camera cam2(cam1);
    EXPECT_EQ(cam2.getHfov(), 2.0);
    EXPECT_EQ(cam2.getNear(), 0.5);
    EXPECT_EQ(cam2.getFar(), 10.0);
    EXPECT_EQ(cam2.getType(), Camera::Type::R8G8B8);
}

TEST(CameraTest, SetTypeFromEnumAndString) {
    Camera cam;
    cam.setType(Camera::Type::BAYER_RGGB8);
    EXPECT_EQ(cam.getType(), Camera::Type::BAYER_RGGB8);

    cam.setType("BAYER_BGGR8");
    EXPECT_EQ(cam.getType(), Camera::Type::BAYER_BGGR8);
}

TEST(CameraTest, OriginHandling) {
    Camera cam;
    auto pose = std::make_shared<Pose>();
    pose->setPosition(1.0, 2.0, 3.0);
    cam.setOrigin(pose);

    double xyz[3];
    cam.getOrigin(xyz);
    EXPECT_DOUBLE_EQ(xyz[0], 1.0);
    EXPECT_DOUBLE_EQ(xyz[1], 2.0);
    EXPECT_DOUBLE_EQ(xyz[2], 3.0);
}

TEST(CameraTest, RangeHandling) {
    Camera cam;
    Image<double, 4> range(1, 1);
    double* data = range.data();
    data[0] = 1.0; data[1] = 2.0; data[2] = 3.0; data[3] = 4.0;
    cam.setRange(range);

    Image<double, 4> out(1, 1);
    cam.getRange(out);
    const double* val = out.data();
    EXPECT_DOUBLE_EQ(val[0], 1.0);
    EXPECT_DOUBLE_EQ(val[1], 2.0);
    EXPECT_DOUBLE_EQ(val[2], 3.0);
    EXPECT_DOUBLE_EQ(val[3], 4.0);
}

TEST(CameraTest, ImageHandling) {
    Camera cam;
    auto img = std::make_shared<Image<double, 4>>(1, 1);
    double* data = img->data();
    data[0] = 0.1; data[1] = 0.2; data[2] = 0.3; data[3] = 0.4;
    cam.set(img);

    Image<double, 4> out(1, 1);
    cam.get(out);
    const double* val = out.data();
    EXPECT_DOUBLE_EQ(val[0], 0.1);
    EXPECT_DOUBLE_EQ(val[1], 0.2);
    EXPECT_DOUBLE_EQ(val[2], 0.3);
    EXPECT_DOUBLE_EQ(val[3], 0.4);
}

TEST(CameraTest, ClearAndEmpty) {
    Camera cam;
    auto img = std::make_shared<Image<double, 4>>(1, 1);
    cam.set(img);
    EXPECT_FALSE(cam.empty());

    cam.clear();
    EXPECT_TRUE(cam.empty());
}