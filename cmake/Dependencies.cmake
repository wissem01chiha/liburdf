# SPDX-FileCopyrightText: 2024-2026 Wissem Chiha
# SPDX-License-Identifier: MIT

include(external/eigen)
if(LIBURDF_BUILD_TESTS)
    include(external/googletest)
endif()
if(LIBURDF_BUILD_PYTHON3)
    include(external/pybind11)
endif()
add_subdirectory(third_party/loguru)
add_subdirectory(third_party/tinyxml2)
add_subdirectory(third_party/cxxopts)