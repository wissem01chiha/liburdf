#ifndef INCLUDE_URDF_INTERNAL_VERSION_H_
#define INCLUDE_URDF_INTERNAL_VERSION_H_

// Copyright 2024-2026 Wissem CHIHA

#include <memory>
#include <vector>

#include "common/property_base.h"

/**
 * \brief Version handling class.
 * \note Only accepts version strings of the type <major>.<minor>.
 * \todo Update to accept <major>, <minor>, or <major> <minor> (spaced) in a
 * future release.
 */
class Version final : public PropertyBase {
 public:
  Version();
  Version(const char* attr);
  Version(const Version& rhs);
  Version& operator=(const Version& rhs);
  bool isA(const char* name) const override;
  void clear() override;
  std::string toString() const override;
  bool equal(double maj, double min);
  double getMajor() const;
  double getMinor() const;
  ~Version();

 private:
  double major_, minor_;
};
#endif  // INCLUDE_URDF_INTERNAL_VERSION_H_