#ifndef INCLUDE_URDF_INTERNAL_VISUAL_PARSER_H_
#define INCLUDE_URDF_INTERNAL_VISUAL_PARSER_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/geometry_base.h"
#include "common/parser_base.h"
#include "core/box.h"
#include "core/cylinder.h"
#include "core/material.h"
#include "core/mesh.h"
#include "core/sphere.h"
#include "core/visual.h"
#include "internal/geometry_parser.h"
#include "internal/material_parser.h"
#include "internal/pose_parser.h"

class VisualParser final : public ParserBase<Visual>
{
 public:
  VisualParser();
  std::string toString() const override;
  bool empty() const override;
  void clear() override;
  const char* getTypename() const override;
  bool isA(const char* name) const override;
  int parse(const tinyxml2::XMLElement* xml) override;
  std::shared_ptr<Visual> get() override;
  ~VisualParser();

 private:
  std::shared_ptr<Visual> p_;
};
#endif  // INCLUDE_URDF_INTERNAL_VISUAL_PARSER_H_
