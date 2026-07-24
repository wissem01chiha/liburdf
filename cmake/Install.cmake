# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

configure_package_config_file(
    "${CMAKE_SOURCE_DIR}/cmake/urdfConfig.cmake.in"
    "${CMAKE_BINARY_DIR}/urdfConfig.cmake"
    INSTALL_DESTINATION share/liburdf
)
write_basic_package_version_file(
    "${CMAKE_BINARY_DIR}/urdfConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(DIRECTORY 
    ${CMAKE_SOURCE_DIR}/include/urdf 
    DESTINATION include
)
install(TARGETS urdf eigen
        EXPORT urdfTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)
install(EXPORT urdfTargets
        FILE urdfTargets.cmake
        NAMESPACE urdf::
        DESTINATION share/liburdf
)
install(FILES
    "${CMAKE_BINARY_DIR}/urdfConfig.cmake"
    "${CMAKE_BINARY_DIR}/urdfConfigVersion.cmake"
    DESTINATION share/liburdf)
install(FILES 
    ${CMAKE_SOURCE_DIR}/LICENSE.txt
    DESTINATION share/license/liburdf
)
install(FILES 
    ${CMAKE_BINARY_DIR}/urdf.pc
    DESTINATION lib/pkgconfig
)

set(CPACK_PACKAGE_VENDOR "Wissem Chiha")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "URDF file I/O library")
set(CMAKE_PROJECT_HOMEPAGE_URL "https://github.com/wissem01chiha/liburdf")
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
include(CPack)