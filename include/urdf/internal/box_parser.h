#ifndef INCLUDE_URDF_INTERNAL_BOX_PARSER_H_
#define INCLUDE_URDF_INTERNAL_BOX_PARSER_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/geometry_base.h"
#include "common/parser_base.h"
#include "core/box.h"

/**
 * @brief Parser for Box geometry, inherits from ParserBase<Box>
 * and provides the functionality to parse the box geometry from XML.
 */
class BoxParser : public ParserBase<Box> {
 public:
  BoxParser();
  int parse(const tinyxml2::XMLElement* xml) override;
  bool isA(const char* name) const override;
  const char* getTypename() const override;
  std::string toString() const override;
  bool empty() const override;
  void clear() override;
  std::shared_ptr<Box> get() override;
  ~BoxParser() override;

 private:
  std::shared_ptr<Box> p_;
};
#endif  // INCLUDE_URDF_INTERNAL_BOX_PARSER_H_
