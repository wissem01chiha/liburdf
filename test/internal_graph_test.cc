#include "detail/internal_graph.h"

#include <gtest/gtest.h>

TEST(InternalGraphTest, ConstructorTest) {
  Model model;
  InternalGraph graph(model);
  EXPECT_TRUE(true);
}

TEST(InternalGraphTest, getChildLinksTest) {
  std::shared_ptr<Model> model = std::make_shared<Model>();
  InternalGraph graph(model);

  std::shared_ptr<Link> link = std::make_shared<Link>();
  auto children = graph.getChildLinks(link);

  EXPECT_TRUE(children.empty());
}

TEST(InternalGraphTest, getParentLinksTest) {
  std::shared_ptr<Model> model = std::make_shared<Model>();
  InternalGraph graph(model);

  std::shared_ptr<Link> link = std::make_shared<Link>();
  auto parents = graph.getParentLinks(link);

  EXPECT_TRUE(parents.empty());
}

TEST(InternalGraphTest, getChildLinkNamesTest) {
  std::shared_ptr<Model> model = std::make_shared<Model>();
  InternalGraph graph(model);

  std::shared_ptr<Link> link = std::make_shared<Link>();
  auto childNames = graph.getChildLinkNames(link);

  EXPECT_TRUE(childNames.empty());
}

TEST(InternalGraphTest, getParentLinkNamesTest) {
  std::shared_ptr<Model> model = std::make_shared<Model>();
  InternalGraph graph(model);

  std::shared_ptr<Link> link = std::make_shared<Link>();
  auto parentNames = graph.getParentLinkNames(link);

  EXPECT_TRUE(parentNames.empty());
}

TEST(InternalGraphTest, toStringTest) {
  std::shared_ptr<Model> model = std::make_shared<Model>();
  InternalGraph graph(model);

  std::shared_ptr<Link> link = std::make_shared<Link>();
  std::string description = graph.toString(link);

  EXPECT_FALSE(description.empty());
}
