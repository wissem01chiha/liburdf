#ifndef INCLUDE_URDF_COMMON_PROPERTY_BASE_H_
#define INCLUDE_URDF_COMMON_PROPERTY_BASE_H_

// Copyright 2024-2026 Wissem CHIHA

#include <string>

class PropertyBase
{
 public:
  virtual bool validate() const { return true; };
  virtual std::string toString() const = 0;

 protected:
  PropertyBase() {};
  virtual ~PropertyBase() {};
  virtual bool isA(const char* name) const = 0;
  virtual PropertyBase* getPointer() { return this; };
  virtual void clear() = 0;
};
#endif  // INCLUDE_URDF_COMMON_PROPERTY_BASE_H_
