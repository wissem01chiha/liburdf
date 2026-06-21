#ifndef INCLUDE_URDF_DETAIL_INTERNAL_GRAPH_H_
#define INCLUDE_URDF_DETAIL_INTERNAL_GRAPH_H_

// Copyright 2024-2026 Wissem CHIHA

#include "core/model.h"

/**
 * @brief base class for building multibody graph model
 */
class InternalGraph {
 public:
  InternalGraph();
  InternalGraph(Model m);
  InternalGraph(std::shared_ptr<Model> m);
  std::vector<std::shared_ptr<Link>> getRootLinks();
  std::vector<std::shared_ptr<Link>> getChildLinks(std::shared_ptr<Link> link);
  std::vector<std::shared_ptr<Link>> getParentLinks(std::shared_ptr<Link> link);
  std::vector<std::string> getChildLinkNames(std::shared_ptr<Link> link);
  std::vector<std::string> getParentLinkNames(std::shared_ptr<Link> link);
  std::string toString(std::shared_ptr<Link> link);

 private:
  std::shared_ptr<Model> m_;
};
#endif  // INCLUDE_URDF_DETAIL_INTERNAL_GRAPH_H_
