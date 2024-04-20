cmake_minimum_required(VERSION 3.20)

# 1.) Replace T_PROJECTNAME_T, T_PROJ_DESCRIPTION_T

message(STATUS "  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄")
message(STATUS "  ██ ▄▄ ██ ▄▄▀██ ▄▄▄ █████ ██ ▄▄▄██ ▄▄▀█▄▄ ▄▄████ ▀██ █ ▄▄▀██ ▄▀▄ ██ ▄▄▄██")
message(STATUS "  ██ ▀▀ ██ ▀▀▄██ ███ █████ ██ ▄▄▄██ ██████ ██████ █ █ █ ▀▀ ██ █ █ ██ ▄▄▄██")
message(STATUS "  ██ █████ ██ ██ ▀▀▀ ██ ▀▀ ██ ▀▀▀██ ▀▀▄███ ██████ ██▄ █ ██ ██ ███ ██ ▀▀▀██")
message(STATUS "  ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀")

project(T_PROJECTNAME_T
    VERSION 0.0.0 # !!Only for local builds. Ci overwrites it anyway so keep it to 0.0.0!!
    DESCRIPTION "T_PROJ_DESCRIPTION_T"
    HOMEPAGE_URL "https://github.com/"
    LANGUAGES CXX
)

if(CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
    set(BUILD_TESTS_DEFAULT ON)
    set(USE_CCACHE_DEFAULT ON)
    set(CMAKE_ENABLE_EXPORTS ON)
else()
    set(BUILD_TESTS_DEFAULT OFF)
    set(USE_CCACHE_DEFAULT OFF)
endif()

# =====================================================================================================================
# Options:
option(BUILD_TESTS "Build the unit tests" ${BUILD_TESTS_DEFAULT})
option(BUILD_EXAMPLES "Build example targets" ON)
option(RUN_CLANG_TIDY "Run clang-tidy on targets" ON)
option(RUN_CLANG_FORMAT "Run clang-format on targets" ON)
option(USE_CCACHE "Use ccache to speed up compilation" ${USE_CCACHE_DEFAULT})

# =====================================================================================================================
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# =====================================================================================================================
# Set Version to devdirty if not built by CI
if( NOT (DEFINED ENV{CI_VERSION_MAJOR} AND DEFINED ENV{CI_VERSION_MINOR} AND DEFINED ENV{CI_VERSION_PATCH} AND DEFINED ENV{CI_VERSION_PRREL}))
    execute_process(
        COMMAND git rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE CI_COMMIT_SHORT_SHA
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    set(PROJECT_VERSION_PRREL "devdirty+${CI_COMMIT_SHORT_SHA}")
else()
    set(PROJECT_VERSION_MAJOR $ENV{CI_VERSION_MAJOR})
    set(PROJECT_VERSION_MINOR $ENV{CI_VERSION_MINOR})
    set(PROJECT_VERSION_PATCH $ENV{CI_VERSION_PATCH})
    set(PROJECT_VERSION_PRREL $ENV{CI_VERSION_PRREL})
endif()
set(SOFTWARE_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}-${PROJECT_VERSION_PRREL})

# =====================================================================================================================
# Set a few basic paths in the *runtime* environment
include(GNUInstallDirs)

# and produce a nice output:
message(STATUS "")
message(STATUS "Runtime environment:")
message(STATUS "    SOFTWARE_VERSION:          ${SOFTWARE_VERSION}")
message(STATUS "    CMAKE_INSTALL_PREFIX:      ${CMAKE_INSTALL_PREFIX}")
message(STATUS "    BINDIR:                    ${BINDIR}")
message(STATUS "    LIBDIR:                    ${LIBDIR}")
message(STATUS "")

# last, expose the runtime information to all targets
add_compile_definitions(
    SOFTWARE_VERSION="${SOFTWARE_VERSION}"
    PATH_PREFIX_CONFIG="${PATH_PREFIX_CONFIG}"
    PATH_PREFIX_KEYS="${PATH_PREFIX_KEYS}"
    PATH_PREFIX_LOG="${PATH_PREFIX_LOG}"
    PATH_PREFIX_STORAGE="${PATH_PREFIX_STORAGE}"
)

# =====================================================================================================================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(USE_CCACHE)
    message(CHECK_START "Looking for ccache")
    find_program(CCACHE_PATH ccache NO_CMAKE_FIND_ROOT_PATH)
    if(CCACHE_PATH)
        if(DEFINED CMAKE_C_COMPILER_LAUNCHER)
            message(WARNING "CMAKE_C_COMPILER_LAUNCHER has already been set externally. This takes precedence over the default value. Consider setting USE_CCACHE to false.")
        else()
            set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_PATH}")
        endif()
        if(DEFINED CMAKE_CXX_COMPILER_LAUNCHER)
        message(WARNING "CMAKE_CXX_COMPILER_LAUNCHER has already been set externally. This takes precedence over the default value. Consider setting USE_CCACHE to false.")
        else()
            set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PATH}")
        endif()
        message(CHECK_PASS "ccache enabled (${CCACHE_PATH})")

        message(CHECK_START "Checking ccache environment variables")
        unset(missingEnvVars)
        message(CHECK_START "  CCACHE_DIR")
        if(DEFINED ENV{CCACHE_DIR})
            message(CHECK_PASS "set to $ENV{CCACHE_DIR}")
        else()
            message(WARNING "Environment variable CCACHE_DIR not set. Your system's global cache is used.")
            list(APPEND missingEnvVars CCACHE_DIR)
            message(CHECK_FAIL "not set")
        endif()
        message(CHECK_START "  CCACHE_BASEDIR")
        if(DEFINED ENV{CCACHE_BASEDIR})
            message(CHECK_PASS "set to $ENV{CCACHE_BASEDIR}")
        else()
            message(WARNING "Environment variable CCACHE_BASEDIR not set. The cache cannot be shared between different build dirs.")
            list(APPEND missingEnvVars CCACHE_BASEDIR)
            message(CHECK_FAIL "not set")
        endif()
        if(missingEnvVars)
            message(CHECK_FAIL "missing environment variables: ${missingEnvVars}")
        else()
            message(CHECK_PASS "ok")
        endif()
    else(CCACHE_PATH)
        message(CHECK_FAIL "not found. Compiling without a cache.")
    endif(CCACHE_PATH)
endif()

include(fetch_external_dependencies)

find_package(Sanitizers)
find_package(Doxygen)

# Let's get our hands dirty. Let's talk about compiler flags:
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # Warning level 4 on Microsoft Visual C++
    add_compile_options("/W4")

elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # The regular stuff...
    add_compile_options(-Wall -Wextra -Werror)

    # ...and a few specials
    add_compile_options(-Wfloat-equal -Wcast-align -Wpointer-arith -Wformat=2 -Winline -Wundef)

    # Here are a few specials that only get activated when compiling C source files
    add_compile_options($<$<COMPILE_LANGUAGE:C>:-Wstrict-prototypes> $<$<COMPILE_LANGUAGE:C>:-Wbad-function-cast>)

    # GCC can warn when a logical operator is used where a bitwise operator is likely expected
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        add_compile_options(-Wlogical-op)
    endif()

    # Enable this to warn on switch statements without a default label.
    add_compile_options(-Wswitch-default -Wswitch-enum)

    # The embedded ARM FPUs usually only implement (32bit) float in hardware. An implicit conversion to (64bit)
    # double can cause a fallback to software floating point.
    add_compile_options(-Wdouble-promotion)
endif()

if(BUILD_TESTS)
    # Used for google tests
    add_compile_options($<$<CXX_COMPILER_ID:GNU>:-Wno-error=restrict>)
    add_compile_options(-Wno-error=inline)

    include(GoogleTest)
    enable_testing()
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    if(RUN_CLANG_TIDY)
        message(CHECK_START "Checking for clang-tidy")
        find_program(CLANG_TIDY clang-tidy)

        if(CLANG_TIDY)
            message(CHECK_PASS "found (${CLANG_TIDY})")
            set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY})
        else()
            message(CHECK_FAIL "not available. Can't activate checks.")
        endif()
    endif(RUN_CLANG_TIDY)

    if(RUN_CLANG_FORMAT)
        message(CHECK_START "Checking for clang-format")
        find_program(CLANG_FORMAT clang-format)

        if(CLANG_FORMAT)
            message(CHECK_PASS "found (${CLANG_FORMAT})")
            set(CMAKE_CXX_CLANG_FORMAT ${CLANG_FORMAT})
        else()
            message(CHECK_FAIL "not available. Can't activate checks.")
        endif()
    endif(RUN_CLANG_FORMAT)
endif()

add_subdirectory(src)
