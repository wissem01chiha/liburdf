# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

find_package(GTest QUIET)
if(GTest_FOUND)
    message(STATUS "GTest found: ${GTest_DIR}")
    list(APPEND urdf_test_libraries GTest::gtest GTest::gtest_main)
    list(APPEND urdf_test_include_dirs ${GTEST_INCLUDE_DIRS})
else()
    message(STATUS "GTest not found. Downloading and building from source...")
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.0.zip
    )
    FetchContent_GetProperties(GTest)
    if(WIN32)
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    endif()
    FetchContent_MakeAvailable(googletest)
    list(APPEND urdf_test_libraries GTest::gtest GTest::gtest_main)
    list(APPEND urdf_test_include_dirs ${googletest_SOURCE_DIR}/googletest/include)
    message(STATUS "GTest has been fetched and is available at ${googletest_SOURCE_DIR}")
endif()