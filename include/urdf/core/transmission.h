#ifndef INCLUDE_URDF_CORE_TRANSMISSION_H_
#define INCLUDE_URDF_CORE_TRANSMISSION_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/object_base.h"

/**
 * @brief Represents a Transmission elment defintion, for a joint
 * @code{.xml}
 * <transmission name="transmission">
 *  <type>transmission_interface/SimpleTransmission</type>
 *  <joint name="joint_name">
 *      <hardwareInterface>EffortJointInterface</hardwareInterface>
 *  </joint>
 *  <actuator name="actuator_name">
 *      <mechanicalReduction>50</mechanicalReduction>
 *       <hardwareInterface>EffortJointInterface</hardwareInterface>
 *  </actuator>
 *  </transmission>
 * @endcode
 */
class Transmission final : public ObjectBase {
 public:
  enum class Type {

  };
  Transmission();
  ~Transmission() override;
  void clear() override;
  std::string toString() const override;
  bool isA(const char* name) const override;
  const char* getTypename() const override;
  bool empty() const override;
  std::string getJointName();
  std::string getActuatorName();
  std::string getName();

 private:
  std::string name;
  std::string joint_name;
  std::string actuator_name;
};

#endif  // INCLUDE_URDF_CORE_TRANSMISSION_H_