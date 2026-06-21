#ifndef INCLUDE_URDF_INTERNAL_MODEL_PARSER_H_
#define INCLUDE_URDF_INTERNAL_MODEL_PARSER_H_

// Copyright 2024-2026 Wissem CHIHA

#include <tinyxml2/tinyxml2.h>

#include "common/parser_base.h"
#include "core/model.h"
#include "internal/joint_parser.h"
#include "internal/link_parser.h"

class ModelParser final : public ParserBase<Model> {
 public:
  ModelParser();
  int parse(const tinyxml2::XMLElement* xml) override;
  std::shared_ptr<Model> get() override;
  std::string toString() const override;
  bool isA(const char* name) const override;
  bool empty() const override;
  void clear() override;
  const char* getTypename() const override;

 private:
  std::shared_ptr<Model> p_;
};
#endif  // INCLUDE_URDF_INTERNAL_MODEL_PARSER_H_