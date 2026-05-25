#ifndef INCLUDE_URDF_CORE_BOX_H_
#define INCLUDE_URDF_CORE_BOX_H_

// Copyright 2024-2026 Wissem CHIHA

#include <string>

#include "common/geometry_base.h"
#include "utility/math_utils.h"

class Box final : public GeometryBase
{
 public:
  Box();
  explicit Box(double* xyz);
  Box(double x, double y, double z);
  bool isA(const char* name) const override;
  const char* getTypename() const override;
  bool empty() const override;
  std::string toString() const override;
  void setOrigin(double x, double y, double z) override;
  void getOrigin(double* xyz) const override;
  Vec3 getDim() const;
  void clear() override;
  ~Box();

 private:
  Vec3 dim;
};
#endif  // INCLUDE_URDF_CORE_BOX_H_
