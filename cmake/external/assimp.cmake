find_package(assimp QUIET)
if(ASSIMP_FOUND)
    message(STATUS "assimp found: ${ASSIMP_INCLUDE_DIR}")
else()
    message(STATUS "assimp not found. Downloading and building from source...")
    include(FetchContent)
    FetchContent_Declare(
        assimp
        URL https://github.com/assimp/assimp/archive/v6.0.4/assimp-6.0.4.tar.gz
    )
    FetchContent_GetProperties(assimp)
    set(BUILD_TESTING OFF CACHE BOOL "Disable assimp tests")
    FetchContent_MakeAvailable(assimp)
    include_directories(SYSTEM ${assimp_SOURCE_DIR}/assimp-6.0.4)
    message(STATUS "assimp has been fetched and is available at ${assimp_SOURCE_DIR}/assimp-6.0.4")
endif()