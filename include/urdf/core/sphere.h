#ifndef INCLUDE_URDF_CORE_SPHERE_H_
#define INCLUDE_URDF_CORE_SPHERE_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/geometry_base.h"

class Sphere final : public GeometryBase
{
 public:
  Sphere();
  Sphere(double r);
  bool isA(const char* name) const override;
  std::string toString() const override;
  void clear() override;
  const char* getTypename() const override;
  double getRadius() const;
  void setRadius(double r);
  void setOrigin(double x, double y, double z) override;
  void getOrigin(double* xyz) const override;
  double getRadius() override;
  bool empty() const override;

 private:
  double radius;
};

#endif  // INCLUDE_URDF_CORE_SPHERE_H_
