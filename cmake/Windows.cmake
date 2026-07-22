# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

if(WIN32)
    cmake_policy(SET CMP0135 NEW)
    list(APPEND urdf_cflags "/DNOMINMAX")
    add_compile_options(/Zm2000)
endif()