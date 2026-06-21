#ifndef INCLUDE_URDF_CORE_DATA_TYPE_H_
#define INCLUDE_URDF_CORE_DATA_TYPE_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/property_base.h"

/**
 * @class DataType
 * @brief data-types defintion, for sensor this is the main data types for
 * all entites defintion and quanties for physical and numeric
 * @code{.xml}
 * <data-types>
 * <data name="TorqueSensor">
 * <type>float</type>
 * <unit>Newton-meter</unit>
 * </data>
 *  <data name="JointAngle">
 *   <type>float</type>
 *   <unit>radians</unit>
 *  </data>
 * </data-types>
 * @endcode
 */
class DataType final : public PropertyBase {
 public:
  DataType();
  std::string toString() const override;
  bool isA(const char* name) const override;
  void clear() override;

 private:
  std::string name;
  std::string type;
};

#endif  // INCLUDE_URDF_CORE_DATA_TYPE_H_
