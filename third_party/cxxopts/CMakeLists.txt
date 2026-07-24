# cxxopts is a header only library no target to build or export
list(APPEND urdf_include_dirs "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(urdf_include_dirs ${urdf_include_dirs} PARENT_SCOPE)

install(FILES include/cxxopts.hpp
        DESTINATION include/cxxopts
)
# Install third_party licenses, 
# by default in share/license
install(FILES LICENSE
        DESTINATION share/license/cxxopts
)
