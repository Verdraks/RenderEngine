add_library(src)

target_sources(src PRIVATE
    "Buffer.cpp"
    "Camera.cpp"
    "Mesh.cpp"
    "Shader.cpp"
    "Texture.cpp"
    "Window.cpp"
    "WindowOpenglContext.cpp"
)

target_include_directories(src PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(src PUBLIC glfw glad glm PRIVATE stb)

target_compile_definitions(src PUBLIC GLFW_INCLUDE_NONE)