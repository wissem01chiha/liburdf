#ifndef INCLUDE_URDF_INTERNAL_SPHERE_PARSER_H_
#define INCLUDE_URDF_INTERNAL_SPHERE_PARSER_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/parser_base.h"
#include "core/sphere.h"

class SphereParser final : public ParserBase<Sphere> {
 public:
  SphereParser();
  int parse(const tinyxml2::XMLElement* xml) override;
  bool isA(const char* name) const override;
  const char* getTypename() const override;
  std::string toString() const override;
  bool empty() const override;
  void clear() override;
  std::shared_ptr<Sphere> get() override;
  ~SphereParser() = default;

 private:
  std::shared_ptr<Sphere> p_;
};
#endif  // INCLUDE_URDF_INTERNAL_SPHERE_PARSER_H_
