#ifndef INCLUDE_URDF_CORE_JOINT_DYNAMICS_H
#define INCLUDE_URDF_CORE_JOINT_DYNAMICS_H

// Copyright 2024-2026 Wissem CHIHA

#include <string>

#include "common/property_base.h"

class JointDynamics final : public PropertyBase {
 public:
  JointDynamics();
  bool isA(const char* name) const override;
  std::string toString() const override;
  void clear() override;
  void setDamping(double d);
  void setFriction(double f);
  void setInertia(double i);

 private:
  double damping, friction, inertia;
};
#endif  // INCLUDE_URDF_CORE_JOINT_DYNAMICS_H