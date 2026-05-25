#ifndef INCLUDE_URDF_UTILITY_STRING_UTILS_H_
#define INCLUDE_URDF_UTILITY_STRING_UTILS_H_

// Copyright 2024-2026 Wissem CHIHA

#include <string>
#include <vector>

/**
 * @brief Constructs an array of double values from a space-separated string.
 * @param str_ The input string containing space-separated numeric values.
 * @param arr Pointer to the output array where values will be stored.
 * @example "1.0 2.3 1.1" -> [1.0, 2.3, 1.1]
 */
void str2array(const char* str_, double* arr);

/**
 * @brief Converts a string to a double value in a locale-safe manner.
 */
void str2double(const char* in, double& num_);

/**
 * @brief Splits a string by a delimiter into a vector of strings.
 * @param str The input string to split.
 * @param split_result Vector to store the resulting substrings.
 * @param delimiter The delimiter used for splitting the string.
 */
void split(const std::string& str, std::vector<std::string>& split_result,
           const std::string& delimiter);


#endif // INCLUDE_URDF_UTILITY_STRING_UTILS_H_
