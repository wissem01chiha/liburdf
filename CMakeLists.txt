# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

if(POLICY CMP0091)
    cmake_policy(SET CMP0091 NEW)
endif()

project(urdf LANGUAGES C CXX)

set(PROJECT_DESCRIPTION  "URDF file I/O library")
set(PROJECT_HOMEPAGE_URL "https://github.com/wissem01chiha/liburdf")

set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1)
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(LIBURDF_BUILD_SHARED   "Build shared library" OFF)
option(LIBURDF_BUILD_TESTS    "Enable building Cxx tests" ON)
option(LIBURDF_BUILD_SCRIPTS  "Enable building Cxx scripts" ON)
option(LIBURDF_BUILD_EXAMPLES "Enable building Cxx examples" ON)
option(LIBURDF_BUILD_PYTHON3  "Enable building Python3 binaries" OFF)
option(LIBURDF_BUILD_LUA      "Enable building Lua binaries" ON)

option(LIBURDF_ENABLE_TESTING_COVERAGE "Enable Test Coverage" OFF)

option(LIBURDF_ENABLE_SANITIZERS "Enable Sanitizers" OFF)
option(LIBURDF_ENABLE_ASAN "Enable Address Sanitizer" ON)
option(LIBURDF_ENABLE_UBSAN "Enable Undefined Behavior Sanitizer" ON)
option(LIBURDF_ENABLE_MSAN "Enable Memory Sanitizer" ON)

# Note : Only set default for single-config generators :
# Ninja, Makefiles, ...
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the build type" FORCE)
endif()

# project global vars
set(urdf_cflags "")
set(urdf_include_dirs "")
set(urdf_link_libraries "")
set(urdf_test_sources "")
set(urdf_test_libraries "")
set(urdf_test_cflags "")
set(urdf_test_assets "")
set(urdf_link_cflags "")
set(urdf_python_sources "")
set(urdf_script_sources "")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(CompilerFlags)
include(Dependencies)
include(Version)
include(Windows)
include(Unix)
include(CTest)

add_subdirectory(src/urdf)

if (LIBURDF_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)  
endif()

if(LIBURDF_BUILD_PYTHON3)
    add_subdirectory(python)
endif()

if(LIBURDF_BUILD_SCRIPTS)
    add_subdirectory(scripts)
endif()

include(Install)
