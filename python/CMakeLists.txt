# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

set(urdf_python_sources
    pyurdf_parser.cc
    pyurdf.cc
)

foreach(urdf_python_source_file IN LISTS urdf_python_sources)
    get_filename_component(urdf_python_executable ${urdf_python_source_file} NAME_WE)
    pybind11_add_module(${urdf_python_executable} src/${urdf_python_source_file})
    target_link_libraries(${urdf_python_executable} PRIVATE urdf ${urdf_link_libraries})
    target_include_directories(${urdf_python_executable} PRIVATE ${urdf_include_dirs})
endforeach()