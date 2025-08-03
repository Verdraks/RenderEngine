cmake_minimum_required(VERSION 3.16)

project(RenderEngine VERSION 1.0 LANGUAGES CXX)

option(TEST_INCLUDE "Include tests files for build" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(thirdparty)
add_subdirectory(src/platform)
add_subdirectory(demo)

if (TEST_INCLUDE)
	enable_testing()
	add_subdirectory(tests)
endif()