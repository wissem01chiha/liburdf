#ifndef INCLUDE_URDF_INTERNAL_COLOR_PARSER_H_
#define INCLUDE_URDF_INTERNAL_COLOR_PARSER_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/parser_base.h"
#include "core/color.h"

/***
 * \brief Base parser for color description element
 * \note This is an elementary base parser.
 * \example <color rgba="1.0 0.01 0.0 1.0"/>
 * \note There is no other acceptable format for color definition!
 */
class ColorParser final : public ParserBase<Color> {
 public:
  ColorParser();
  std::string toString() const override;
  bool empty() const override;
  void clear() override;
  const char* getTypename() const override;
  bool isA(const char* name) const override;
  int parse(const tinyxml2::XMLElement* xml) override;
  std::shared_ptr<Color> get() override;

 private:
  std::shared_ptr<Color> p_;
};
#endif  // INCLUDE_URDF_INTERNAL_COLOR_PARSER_H_
