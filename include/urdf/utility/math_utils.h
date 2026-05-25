#ifndef INCLUDE_URDF_UTILITY_MATH_UTILS_H_
#define INCLUDE_URDF_UTILITY_MATH_UTILS_H_

// Copyright 2024-2026 Wissem CHIHA

#include <Eigen/Dense>

/**
 * @brief Base struct for 3D position vectors.
 */
using Vec3 = Eigen::Matrix<double, 3, 1>;

/**
 * @brief Base struct for 3D rotation elements.
 */
using Rot3 = Eigen::Quaternion<double>;


#endif  // INCLUDE_URDF_UTILITY_MATH_UTILS_H_