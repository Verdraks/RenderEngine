cmake_minimum_required(VERSION 3.16)

project(RenderEngine VERSION 1.0 LANGUAGES CXX)

option(TEST_INCLUDE "Include tests files for build" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
add_compile_definitions(ASSETS_DIR="${ASSETS_DIR}")


add_subdirectory(thirdparty)
add_subdirectory(src/platform)
add_subdirectory(src/renderer)
add_subdirectory(demo)

if (TEST_INCLUDE)
	enable_testing()
	add_subdirectory(tests)
endif()