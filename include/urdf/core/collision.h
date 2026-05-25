#ifndef INCLUDE_URDF_CORE_COLLISION_H_
#define INCLUDE_URDF_CORE_COLLISION_H_

// Copyright 2024-2026 Wissem CHIHA

#include <memory>

#include "common/geometry_base.h"
#include "common/property_base.h"
#include "core/pose.h"

class Collision final : public PropertyBase
{
 public:
  Collision();
  bool isA(const char* name) const override;
  void clear() override;
  std::string toString() const override;
  void setGeometry(std::shared_ptr<GeometryBase> geometry);
  std::shared_ptr<GeometryBase> getGeometry() const;
  void setOrigin(std::shared_ptr<Pose> o_);
  void getOrigin(double* xyz) const;

 private:
  std::shared_ptr<GeometryBase> geometry;
  std::shared_ptr<Pose> origin;
};
#endif  // TINYURDF_COLLISION_H_