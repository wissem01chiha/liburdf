#ifndef INCLUDE_URDF_CORE_POSE_H_
#define INCLUDE_URDF_CORE_POSE_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/property_base.h"
#include "utility/math_utils.h"

/**
 * @brief Represents a pose, consisting of position and rotation.
 */
class Pose final : public PropertyBase {
 public:
  Pose();
  Pose(const Pose& rhs);
  Pose& operator=(const Pose& rhs);
  Pose& operator=(Pose&& rhs) noexcept;
  bool isA(const char* name) const override;
  std::string toString() const override;
  Vec3 getPosition();
  Rot3 getRotation();
  void setPosition(double x, double y, double z);
  void setRotation(double x, double y, double z, double w);
  void setRotation(double r, double p, double y);
  void clear() override;
  ~Pose();

 private:
  Vec3 position;
  Rot3 rotation;
};
#endif  // INCLUDE_URDF_CORE_POSE_POSE_H_
