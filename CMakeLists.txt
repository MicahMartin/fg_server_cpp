cmake_minimum_required(VERSION 3.19)
message(STATUS "Using CMake ${CMAKE_VERSION}")

# Project setup
project(fg_server
    LANGUAGES CXX
    VERSION 0.2.0
)

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if (EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in the source directory. Please use a build subdirectory.")
endif()

# Add paths to modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

# Enable link-time optimization for release builds
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)

# Output compile commands for debugging
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define the shared library target
add_library(${PROJECT_NAME} SHARED)

# Set C++ standard to C++17
target_compile_features(${PROJECT_NAME}
    PRIVATE
        cxx_std_17
)

# Define library architecture and output directory
set(LIB_ARCH ${CMAKE_SYSTEM_PROCESSOR})
set(LIB_DIR "lib/${CMAKE_SYSTEM_NAME}-${LIB_ARCH}")

message(STATUS "Building ${PROJECT_NAME} for ${LIB_ARCH} on ${CMAKE_SYSTEM_NAME}")

# Set build output directory
set(BUILD_OUTPUT_DIR "${PROJECT_BINARY_DIR}/${PROJECT_NAME}/")

# Configure target properties
set_target_properties(${PROJECT_NAME}
    PROPERTIES
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN true
        RUNTIME_OUTPUT_DIRECTORY "${BUILD_OUTPUT_DIR}/${LIB_DIR}"
        LIBRARY_OUTPUT_DIRECTORY "${BUILD_OUTPUT_DIR}/${LIB_DIR}"
)

# Add server subdirectory
add_subdirectory(server)

# Set installation directory
set(INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/")
message(STATUS "Install directory: ${INSTALL_DIR}")

# Install targets
install(TARGETS ${PROJECT_NAME}
    LIBRARY
        DESTINATION ${INSTALL_DIR}/${LIB_DIR}
    RUNTIME
        DESTINATION ${INSTALL_DIR}/${LIB_DIR}
)

add_subdirectory( templates )
# Include ccache and ClangFormat configurations
include(ccache)
include(ClangFormat)

# Check if godot-cpp submodule is initialized
if (NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/extern/godot-cpp/Makefile")
    message(FATAL_ERROR
        "[${PROJECT_NAME}] The godot-cpp submodule was not downloaded. "
        "Please update submodules: git submodule update --init --recursive."
    )
endif()

# Configure godot-cpp
set(GODOT_CPP_SYSTEM_HEADERS ON CACHE BOOL "" FORCE)
add_subdirectory(extern/godot-cpp)
set_target_properties(godot-cpp
    PROPERTIES
        CXX_VISIBILITY_PRESET hidden  # Visibility needs to match the main library
)

# Add ggpo subdirectory
add_subdirectory(extern/ggpo)

# Link dependencies
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        godot-cpp
        GGPO
)
