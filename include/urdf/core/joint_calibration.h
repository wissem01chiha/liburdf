#ifndef INCLUDE_URDF_CORE_JOINT_CALIBRATION_H_
#define INCLUDE_URDF_CORE_JOINT_CALIBRATION_H_

// Copyright 2024-2026 Wissem CHIHA

#include <string>

#include "common/property_base.h"

class JointCalibration final : public PropertyBase {
 public:
  JointCalibration();
  bool isA(const char* name) const override;
  std::string toString() const override;
  void clear() override;
  void setRising(double r);
  void setFalling(double f);
  void setReferencePosition(double rp);

 private:
  double referencePosition, rising, falling;
};
#endif  // INCLUDE_URDF_CORE_JOINT_CALIBRATION_H_