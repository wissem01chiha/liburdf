#include <gtest/gtest.h>
#include "core/model.h"

TEST(ModelTest, EmptyOnConstruction) {
    Model m;
    EXPECT_TRUE(m.empty());
    EXPECT_TRUE(m.getLinks().empty());
    EXPECT_TRUE(m.getJoints().empty());
}

TEST(ModelTest, ClearResetsState) {
    Model m;
    m.setName("Robot");
    m.setLink(std::make_shared<Link>());
    m.setJoint(std::make_shared<Joint>());
    EXPECT_FALSE(m.empty());

    m.clear();
    EXPECT_TRUE(m.empty());
    EXPECT_EQ(m.getName(), "");
}

TEST(ModelTest, AddLinksAndRetrieve) {
    Model m;
    auto l1 = std::make_shared<Link>();
    auto l2 = std::make_shared<Link>();
    m.setLink(l1);
    m.setLink(l2);
    auto links = m.getLinks();
    EXPECT_EQ(links.size(), 2);
    EXPECT_EQ(links[0], l1);
    EXPECT_EQ(links[1], l2);
}

TEST(ModelTest, AddJointsAndRetrieve) {
    Model m;
    auto j1 = std::make_shared<Joint>();
    auto j2 = std::make_shared<Joint>();
    m.setJoint(j1);
    m.setJoint(j2);
    auto joints = m.getJoints();
    EXPECT_EQ(joints.size(), 2);
    EXPECT_EQ(joints[0], j1);
    EXPECT_EQ(joints[1], j2);
}

TEST(ModelTest, TypeInformation) {
    Model m;
    EXPECT_TRUE(m.isA("model"));
    EXPECT_STREQ(m.getTypename(), "model");
    EXPECT_FALSE(m.toString().empty());
}

TEST(ModelTest, TestGetName) {

    Model m;
    m.setName("TestModel");
    EXPECT_STREQ(m.getName().c_str(), "TestModel");
}

