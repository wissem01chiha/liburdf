#include "detail/internal_graph.h"
#ifdef USE_OPENMP
#include <omp.h>
#endif

InternalGraph::InternalGraph() {}

InternalGraph::InternalGraph(Model m) { this->m_ = std::make_shared<Model>(m); }

InternalGraph::InternalGraph(std::shared_ptr<Model> m) {
  if (m) {
    this->m_ = m;
  }
}

std::vector<std::shared_ptr<Link>> InternalGraph::getRootLinks() {
  return std::vector<std::shared_ptr<Link>>();
}

std::vector<std::shared_ptr<Link>> InternalGraph::getChildLinks(
    std::shared_ptr<Link> link) {
  std::vector<std::shared_ptr<Link>> clks;
#ifdef USE_OPENMP

#else
  for (const auto& joint : m_->getJoints()) {
    if (joint->isParent(link->getName().c_str())) {
      std::vector<std::string> joint_child_links_names = joint->getChild();
      for (const auto& link_name : joint_child_links_names) {
        for (const auto& model_link : m_->getLinks()) {
          if (model_link->getName() == link_name) {
            clks.push_back(model_link);
          }
        }
      }
    }
  }
#endif
  return clks;
}

std::vector<std::shared_ptr<Link>> InternalGraph::getParentLinks(
    std::shared_ptr<Link> link) {
  std::vector<std::shared_ptr<Link>> plks;
#ifdef USE_OPENMP

#else
  for (const auto& joint : m_->getJoints()) {
    if (joint->isChild(link->getName().c_str())) {
      std::vector<std::string> joint_child_links_names = joint->getChild();
      for (const auto& link_name : joint_child_links_names) {
        for (const auto& model_link : m_->getLinks()) {
          if (model_link->getName() == link_name) {
            plks.push_back(model_link);
          }
        }
      }
    }
  }
#endif
  return plks;
}

std::vector<std::string> InternalGraph::getChildLinkNames(
    std::shared_ptr<Link> link) {
  std::vector<std::string> clkn;
  std::vector<std::shared_ptr<Link>> clk = this->getChildLinks(link);
#ifdef USE_OPENMP
#pragma omp parallel
  for (const auto clkiter : clk) {
    clkn.push_back(clkiter->getName());
  }
#else
  for (const auto clkiter : clk) {
    clkn.push_back(clkiter->getName());
  }
#endif
  return clkn;
}

std::vector<std::string> InternalGraph::getParentLinkNames(
    std::shared_ptr<Link> link) {
  std::vector<std::string> plkn;
  std::vector<std::shared_ptr<Link>> plk = this->getParentLinks(link);
#ifdef USE_OPENMP
#pragma omp parallel
  for (const auto plkiter : plk) {
    plkn.push_back(plkiter->getName());
  }
#else
  for (const auto& plkiter : plk) {
    plkn.push_back(plkiter->getName());
  }
#endif
  return plkn;
}

std::string InternalGraph::toString(std::shared_ptr<Link> link) {
  std::string graph = "digraph G {\n";
  graph += "node [shape=box];\n";
  std::vector<std::string> lkns = this->getChildLinkNames(link);

  for (const auto& lkn : lkns) {
    graph += lkn;
  }
  graph += "node [shape=ellipse, color=blue, fontcolor=blue];\n";
  for (const auto& lkn : lkns) {
    graph += lkn;
  }
  graph += "}\n";
  return graph;
}
