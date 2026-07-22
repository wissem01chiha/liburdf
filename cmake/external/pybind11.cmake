# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

find_package(pybind11 QUIET)
if(pybind11_FOUND)
    message(STATUS "Pybind Found : ${pybind11_INCLUDE_DIRS}")
else()
    include(FetchContent)
    set(FETCHCONTENT_QUIET FALSE)
    FetchContent_Declare(
    pybind11
    URL https://github.com/pybind/pybind11/archive/v3.0.3.tar.gz
    )
    FetchContent_GetProperties(pybind11)
    if(NOT pybind11_POPULATED)
        FetchContent_Populate(pybind11)
        add_subdirectory(${pybind11_SOURCE_DIR} ${pybind11_BINARY_DIR})
    endif()
endif(pybind11_FOUND)