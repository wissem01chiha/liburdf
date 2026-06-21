#ifndef INCLUDE_URDF_CORE_CYLINDER_H_
#define INCLUDE_URDF_CORE_CYLINDER_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/geometry_base.h"

class Cylinder final : public GeometryBase {
 public:
  Cylinder();
  Cylinder(double r, double l);
  bool isA(const char* name) const override;
  std::string toString() const override;
  void clear() override;
  bool empty() const override;
  const char* getTypename() const override;
  void setOrigin(double x, double y, double z) override;
  void getOrigin(double* xyz) const override;
  void setLength(double l);
  void setRadius(double r);
  double getLength() override;
  double getRadius() override;

 private:
  double length, radius;
};
#endif  // INCLUDE_URDF_GEOMETRY_CYLINDER_H_
