add_library(tinyxml2 tinyxml2.cpp)

list(APPEND urdf_link_libraries tinyxml2)
set(urdf_link_libraries ${urdf_link_libraries} PARENT_SCOPE)

install(TARGETS tinyxml2
        EXPORT tinyxml2Targets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(EXPORT tinyxml2Targets
        FILE tinyxml2Targets.cmake
        NAMESPACE tinyxml2::
        DESTINATION share/tinyxml2)
