#ifndef INCLUDE_URDF_INTERNAL_WORLD_PARSER_H_
#define INCLUDE_URDF_INTERNAL_WORLD_PARSER_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/parser_base.h"
#include "core/world.h"

template <typename... PropertyBase>
class WorldParser final : public ParserBase<World<PropertyBase...>> {
 public:
  WorldParser();
  std::string toString() const override;
  bool parse();

 private:
  std::shared_ptr<World<PropertyBase...>> p_;
};
#endif  // INCLUDE_URDF_INTERNAL_WORLD_PARSER_H_