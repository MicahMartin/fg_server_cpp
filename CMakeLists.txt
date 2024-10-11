cmake_minimum_required( VERSION 3.19 )
message( STATUS "using CMake ${CMAKE_VERSION}" )


# Require out-of-source builds
file( TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH )
# Add paths to modules
list( APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/" )
# Turn on link time optimization for everything
set( CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON )
# Output compile commands to compile_commands.json (for debugging CMake issues)
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

project( FightingGameServer 
  LANGUAGES CXX
  VERSION 0.2.0
)

include( ccache )

set( GODOT_CPP_SYSTEM_HEADERS ON CACHE BOOL "" FORCE )
add_subdirectory( extern/godot-cpp )
add_subdirectory( server )
