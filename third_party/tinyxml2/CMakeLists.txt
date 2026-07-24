add_library(tinyxml2 STATIC tinyxml2.cpp)

list(APPEND urdf_link_libraries tinyxml2)
set(urdf_link_libraries ${urdf_link_libraries} PARENT_SCOPE)

install(FILES tinyxml2.h
        DESTINATION include/tinyxml2
)
install(TARGETS tinyxml2
        EXPORT tinyxml2Targets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)
install(EXPORT tinyxml2Targets
        FILE tinyxml2Targets.cmake
        NAMESPACE tinyxml2::
        DESTINATION share/tinyxml2
)
# Install third_party licenses, 
# by default in share/license
install(FILES LICENSE.txt
        DESTINATION share/license/tinyxml2
)
