#ifndef INCLUDE_URDF_CORE_INERTIA_H_
#define INCLUDE_URDF_CORE_INERTIA_H_

// Copyright 2024-2026 Wissem CHIHA

#include <memory>
#include <string>

#include "common/geometry_base.h"
#include "common/property_base.h"
#include "core/pose.h"

/**
 * \brief Represents the inertia of an object.
 * The inertia is defined with respect to a given origin and the components of
 * the inertia matrix, which represent the rotational inertia about the object's
 * axes.
 */
class Inertia final : public PropertyBase, public GeometryBase {
 public:
  Inertia();
  Inertia(double mass, double ixx, double ixy, double ixz, double iyy,
          double iyz, double izz);
  bool isA(const char* name) const override;
  bool validate() const override;
  void clear() override;
  std::string toString() const override;
  const char* getTypename() const override;
  bool empty() const override;
  void setOrigin(double x, double y, double z) override;
  void getOrigin(double* xyz) const override;
  void setMass(const double m);
  void setIxx(double ixx_);
  void setIxy(double ixy_);
  void setIxz(double ixz_);
  void setIyy(double iyy_);
  void setIyz(double iyz_);
  void setIzz(double izz_);

 private:
  std::shared_ptr<Pose> origin;
  double mass;
  double ixx, ixy, ixz, iyy, iyz, izz;
};
#endif  // INCLUDE_URDF_CORE_INERTIA_H_
