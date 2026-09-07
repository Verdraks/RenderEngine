add_library(renderer)

target_sources(renderer PRIVATE "Camera.cpp")

target_include_directories(renderer PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(renderer PUBLIC glad glm PRIVATE stb)