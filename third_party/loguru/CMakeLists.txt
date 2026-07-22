add_library(loguru  STATIC loguru.cpp)

list(APPEND urdf_link_libraries loguru)
set(urdf_link_libraries ${urdf_link_libraries} PARENT_SCOPE)

if(MSVC)
    target_compile_definitions(loguru PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

install(TARGETS loguru
        EXPORT loguruTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(EXPORT loguruTargets
        FILE loguruTargets.cmake
        NAMESPACE loguru::
        DESTINATION share/loguru)
