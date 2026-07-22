# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        list(APPEND urdf_cflags "-O0" "-g" "-DDEBUG")
    elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
        list(APPEND urdf_cflags "-O3")
    endif()
        list(APPEND urdf_test_cflags PRIVATE -g  -DDEBUG)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        list(APPEND urdf_cflags "/Od" "/Zi" "/DDEBUG")
    elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
        list(APPEND urdf_cflags "/O2")
    endif()
    list(APPEND urdf_test_cflags PRIVATE /Zi /DDEBUG)
    list(APPEND urdf_test_cflags PRIVATE /DEBUG)
endif()