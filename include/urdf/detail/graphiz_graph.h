#ifndef INCLUDE_URDF_DETAIL_GRAPHIZ_GRAPH_H_
#define INCLUDE_URDF_DETAIL_GRAPHIZ_GRAPH_H_

// Copyright 2024-2026 Wissem CHIHA

#include "core/model.h"
#include "detail/internal_graph.h"

/**
 * @class GraphizGraph
 * @brief A helper class for Writing robot model in graphiz format
 * from the internal graph reresentation.
 */
class GraphizGraph final {
 public:
  GraphizGraph();
  GraphizGraph(const InternalGraph& ig);

 private:
  InternalGraph ig_;
};

#endif  // INCLUDE_URDF_DETAIL_GRAPHIZ_GRAPH_H_