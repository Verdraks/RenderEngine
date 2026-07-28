add_library(renderer INTERFACE)

target_include_directories(renderer INTERFACE
${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(renderer INTERFACE glad stb glm)