# This file collects all external dependencies to avoid cluttering the main CMakeLists.txt
#
# For now we just fetch all external dependencies, regardless of whether they are actually installed on the build
# system or not.
include(FetchContent)

set(_fetchcontent_targets)

# LICENSE: BSD-3
if(BUILD_TESTS)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
        GIT_PROGRESS ON
        FIND_PACKAGE_ARGS NAMES GTest
    )
    set(_fetchcontent_targets "${_fetchcontent_targets}" "googletest")
endif(BUILD_TESTS)

# ============================================================================
message(STATUS ">>>>> Start fetching external dependencies <<<<<")
FetchContent_MakeAvailable(${_fetchcontent_targets})
message(STATUS ">>>>> Done fetching external dependencies <<<<<")

# ============================================================================

unset(_fetchcontent_targets)

# ============================================================================
# Fetch the scripts that deal with the compiler sanitizers
FetchContent_Declare(
    sanitizers_cmake
    GIT_REPOSITORY https://github.com/arsenm/sanitizers-cmake.git
    GIT_TAG master
)
FetchContent_GetProperties(sanitizers_cmake)

if(NOT sanitizers_cmake_POPULATED)
    FetchContent_Populate(sanitizers_cmake)
    list(APPEND CMAKE_MODULE_PATH "${sanitizers_cmake_SOURCE_DIR}/cmake")
endif()