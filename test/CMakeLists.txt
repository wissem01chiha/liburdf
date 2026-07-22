set(urdf_test_sources
    camera_test.cc
    geometry_parser_test.cc
    inertia_parser_test.cc
    version_test.cc
    pose_test.cc
    color_test.cc
    joint_test.cc
    mesh_test.cc
    link_test.cc
    pose_parser_test.cc
    property_parser_test.cc
    visual_parser_test.cc
    collision_parser_test.cc
    link_parser_test.cc
    joint_parser_test.cc
    string_utils_test.cc
    model_test.cc
    model_parser_test.cc
    material_parser_test.cc
)

set(urdf_test_assets
    assets/anymal.urdf
    assets/cali-bee.stl
    assets/iiwa14.urdf
    assets/joint.urdf
    assets/joint2.urdf
    assets/link.urdf
    assets/lwa4p.urdf
    assets/simple_test.urdf
    assets/simple_test2.urdf
    assets/simple.urdf
    assets/spot.urdf
    assets/texture.txt
    assets/valid_path.txt
)

list(APPEND urdf_test_libraries urdf)

foreach(urdf_test_source_file IN LISTS urdf_test_sources)
    get_filename_component(urdf_test_executable ${urdf_test_source_file} NAME_WE)
    add_executable(${urdf_test_executable} ${urdf_test_source_file})
    target_include_directories(${urdf_test_executable} PRIVATE ${urdf_test_include_dirs})
    target_link_libraries(${urdf_test_executable} PRIVATE ${urdf_test_libraries})
    target_compile_options(${urdf_test_executable} PRIVATE ${urdf_test_cflags})
    add_dependencies(${urdf_test_executable} urdf)
    gtest_discover_tests(${urdf_test_executable})
endforeach()

foreach(asset ${urdf_test_assets})
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/${asset}
        ${CMAKE_CURRENT_BINARY_DIR}/${asset}
        COPYONLY
    )
endforeach()
