# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(liburdf VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1)
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(LIBURDF_BUILD_SHARED  "Build shared library" OFF)
option(LIBURDF_BUILD_SCRIPTS "Enable building Cxx scripts" ON)
option(LIBURDF_BUILD_TESTS   "Enable building Cxx tests" ON)
option(LIBURDF_BUILD_PYTHON3 "Enable building Python3 binaries" ON)
option(LIBURDF_BUILD_LUA     "Enable building Lua binaries" ON)
option(LIBURDF_INSTALL       "Enable installation of liburdf" ON)

# Note : Only set default for single-config generators :
# Ninja, Makefiles, ...
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the build type" FORCE)
endif()

# for shared modules, like pythin bindings, we need to compile with 
# -fPIC we see this only on unix platforms, with pydinds
if(UNIX)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

set(urdf_cflags "")
set(urdf_include_dirs "")
set(urdf_link_libraries "")
set(urdf_test_sources "")
set(urdf_test_libraries "")
set(urdf_test_cflags "")
set(urdf_test_assets "")
set(urdf_python_sources "")
set(urdf_script_sources "")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(Dependencies)
include(Version)
include(Windows)
include(CompilerExtraFlags)
include(CMakePackageConfigHelpers)
include(CTest)

list(APPEND urdf_include_dirs "${PROJECT_SOURCE_DIR}/third_party")
list(APPEND urdf_test_include_dirs "${PROJECT_SOURCE_DIR}/third_party")

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

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc
  @ONLY
)

if(LIBURDF_INSTALL)
    install(DIRECTORY 
        ${CMAKE_SOURCE_DIR}/include/urdf 
        DESTINATION include
    )

    install(TARGETS urdf eigen
            EXPORT urdfTargets
            ARCHIVE DESTINATION lib
            LIBRARY DESTINATION lib
            RUNTIME DESTINATION bin)

    install(EXPORT urdfTargets
            FILE urdfTargets.cmake
            NAMESPACE urdf::
            DESTINATION share/liburdf)

    configure_package_config_file(
        "${CMAKE_SOURCE_DIR}/cmake/LiburdfConfig.cmake.in"
        "${CMAKE_BINARY_DIR}/urdfConfig.cmake"
        INSTALL_DESTINATION share/urdf
    )

    write_basic_package_version_file(
        "${CMAKE_BINARY_DIR}/urdfConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
    )

    install(FILES
        "${CMAKE_BINARY_DIR}/urdfConfig.cmake"
        "${CMAKE_BINARY_DIR}/urdfConfigVersion.cmake"
        DESTINATION share/urdf)

    install(FILES 
        ${CMAKE_SOURCE_DIR}/LICENSE 
        DESTINATION share/liburdf
    )
endif()
