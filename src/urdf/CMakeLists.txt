# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

add_library(urdf STATIC)

add_subdirectory(core)
add_subdirectory(utility)
add_subdirectory(internal)
add_subdirectory(common)
add_subdirectory(detail)

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