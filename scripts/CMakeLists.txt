# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

set(urdf_script_sources
    urdf_parse.cc
    urdf_to_graphiz.cc
)

foreach(urdf_script_source_file IN LISTS urdf_script_sources)
    get_filename_component(urdf_script_excutable ${urdf_script_source_file} NAME_WE)
    add_executable(${urdf_script_excutable} src/${urdf_script_source_file})
    target_include_directories(${urdf_script_excutable} PRIVATE 
                                ${CMAKE_SOURCE_DIR}/include
                                ${CMAKE_SOURCE_DIR}/third_party
                            )
    target_link_libraries(${urdf_script_excutable} PRIVATE urdf)
    add_dependencies(${urdf_script_excutable} urdf)
endforeach() 