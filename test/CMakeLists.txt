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

set(urdf_test_sources ${urdf_test_sources} PARENT_SCOPE)
set(urdf_test_assets ${urdf_test_assets} PARENT_SCOPE)