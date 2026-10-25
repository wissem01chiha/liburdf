# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

# for shared modules, like python bindings, we need to compile with 
# -fPIC we see this only on unix platforms, with pybind11
if(UNIX)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()