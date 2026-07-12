add_library(renderer)

target_sources(renderer PRIVATE
    "shader/Shader.cpp"
    "mesh/Mesh.cpp"
    "texture/Texture.cpp"
)

target_link_libraries(renderer PUBLIC glad stb glm)
target_include_directories(renderer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/shader
    ${CMAKE_CURRENT_SOURCE_DIR}/mesh
    ${CMAKE_CURRENT_SOURCE_DIR}/texture
)