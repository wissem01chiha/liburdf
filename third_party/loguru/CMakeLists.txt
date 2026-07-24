add_library(loguru  STATIC loguru.cpp)

list(APPEND urdf_link_libraries loguru)
set(urdf_link_libraries ${urdf_link_libraries} PARENT_SCOPE)

if(MSVC)
    target_compile_definitions(loguru PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

install(FILES loguru.hpp
        DESTINATION include/loguru
)
install(TARGETS loguru
        EXPORT loguruTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(EXPORT loguruTargets
        FILE loguruTargets.cmake
        NAMESPACE loguru::
        DESTINATION share/loguru)

# Install third_party licenses, 
# by default in share/license
install(FILES LICENSE.txt
        DESTINATION share/license/loguru
)
