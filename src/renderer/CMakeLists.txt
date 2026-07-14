add_library(renderer)

target_sources(renderer PRIVATE
    "Shader.cpp"
    "Mesh.cpp"
    "Texture.cpp"
)

target_include_directories(renderer PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(renderer PUBLIC glad stb glm)