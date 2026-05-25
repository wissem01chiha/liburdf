# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(liburdf VERSION 0.1.0 LANGUAGES C CXX)

option(LIBURDF_BUILD_SHARED    "Build shared library"                 OFF)
option(LIBURDF_BUILD_SCRIPTS   "Enable building Cxx scripts"           ON)
option(LIBURDF_BUILD_TESTS     "Enable building Cxx tests"             ON)
option(LIBURDF_BUILD_PYTHON3   "Enable building Python3 binaries"      ON)
option(LIBURDF_INSTALL         "Enable installation of liburdf"        ON)

# Note : only set default for single-config generators : Ninja, Makefiles, ...
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the build type" FORCE)
endif()

# for shared modules, like pythin bindings, we need to compile with -fPIC
# we see this only on unix platforms, with pydinds
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

include(CompilerChecks)
include(Dependencies)
if(LIBURDF_INSTALL)
    include(CMakePackageConfigHelpers)
endif()
if(LIBURDF_BUILD_TESTS)
    include(CTest)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        list(APPEND urdf_cflags "-O0" "-g" "-DDEBUG")
    elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
        list(APPEND urdf_cflags "-O3")
    endif()
        list(APPEND urdf_test_cflags PRIVATE -g  -DDEBUG)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        list(APPEND urdf_cflags "/Od" "/Zi" "/DDEBUG")
    elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
        list(APPEND urdf_cflags "/O2")
    endif()
    list(APPEND urdf_test_cflags PRIVATE /Zi /DDEBUG)
    list(APPEND urdf_test_cflags PRIVATE /DEBUG)
endif()
if (WIN32)
    cmake_policy(SET CMP0135 NEW)
    list(APPEND urdf_cflags "/DNOMINMAX")
endif()

add_subdirectory(third_party/loguru)
add_subdirectory(third_party/tinyxml2)
add_subdirectory(third_party/cxxopts)

list(APPEND urdf_include_dirs "${PROJECT_SOURCE_DIR}/third_party")
list(APPEND urdf_test_include_dirs "${PROJECT_SOURCE_DIR}/third_party")

add_library(urdf STATIC)
add_subdirectory(src/urdf)
target_include_directories(urdf
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/urdf>
        $<INSTALL_INTERFACE:include/urdf>
)
target_include_directories(urdf PRIVATE ${urdf_include_dirs})
target_link_libraries(urdf PUBLIC ${urdf_link_libraries})
target_compile_options(urdf PRIVATE ${urdf_cflags})

if (LIBURDF_BUILD_SHARED)
    set_target_properties(urdf PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

if (LIBURDF_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
    list(APPEND urdf_test_libraries urdf)

    foreach(urdf_test_source_file IN LISTS urdf_test_sources)
        get_filename_component(urdf_test_executable ${urdf_test_source_file} NAME_WE)
        add_executable(${urdf_test_executable} test/${urdf_test_source_file})
        target_include_directories(${urdf_test_executable} PRIVATE ${urdf_test_include_dirs})
        target_link_libraries(${urdf_test_executable} PRIVATE ${urdf_test_libraries})
        target_compile_options(${urdf_test_executable} PRIVATE ${urdf_test_cflags})
        add_dependencies(${urdf_test_executable} urdf)
        gtest_discover_tests(${urdf_test_executable})
    endforeach()

    foreach(asset ${urdf_test_assets})
        configure_file(
            ${CMAKE_CURRENT_SOURCE_DIR}/test/${asset}
            ${CMAKE_CURRENT_BINARY_DIR}/test/${asset}
            COPYONLY
        )
    endforeach()    
endif()

if(LIBURDF_BUILD_PYTHON3)
    add_subdirectory(python/src)
    foreach(urdf_python_source_file IN LISTS urdf_python_sources)
        get_filename_component(urdf_python_executable ${urdf_python_source_file} NAME_WE)
        pybind11_add_module(${urdf_python_executable} python/src/${urdf_python_source_file})
        target_link_libraries(${urdf_python_executable} PRIVATE urdf ${urdf_link_libraries})
        target_include_directories(${urdf_python_executable} PRIVATE ${urdf_include_dirs})
    endforeach()
endif()

if(LIBURDF_BUILD_SCRIPTS)
    add_subdirectory(scripts/src)
    foreach(urdf_script_source_file IN LISTS urdf_script_sources)
        get_filename_component(urdf_script_excutable ${urdf_script_source_file} NAME_WE)
        add_executable(${urdf_script_excutable} scripts/src/${urdf_script_source_file})
        target_include_directories(${urdf_script_excutable} PRIVATE 
                                    ${CMAKE_SOURCE_DIR}/include
                                    ${CMAKE_SOURCE_DIR}/third_party
                                )
        target_link_libraries(${urdf_script_excutable} PRIVATE urdf)
        add_dependencies(${urdf_script_excutable} urdf)
    endforeach() 
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
        "${CMAKE_SOURCE_DIR}/cmake/urdfConfig.cmake.in"
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
