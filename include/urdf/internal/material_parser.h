#ifndef INCLUDE_URDF_INTERNAL_MATERIAL_PARSER_H_
#define INCLUDE_URDF_INTERNAL_MATERIAL_PARSER_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/parser_base.h"
#include "common/property_parser.h"
#include "core/material.h"
#include "internal/color_parser.h"

/**
 * @brief Parses a material XMl elment
 */
class MaterialParser final : public ParserBase<Material> {
 public:
  MaterialParser();
  std::string toString() const override;
  bool empty() const override;
  void clear() override;
  const char* getTypename() const override;
  bool isA(const char* name) const override;
  int parse(const tinyxml2::XMLElement* xml) override;
  std::shared_ptr<Material> get() override;
  ~MaterialParser() override;

 private:
  std::shared_ptr<Material> p_;
};
#endif  // INCLUDE_URDF_INTERNAL_MATERIALPARSER_H
