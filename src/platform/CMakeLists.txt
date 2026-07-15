add_library(platform)

target_sources(platform PRIVATE
    
    "glfw/GlfwWindow.cpp"
    "opengl/OpenglBuffer.cpp"
    "opengl/OpenglTexture.cpp"
    "opengl/OpenglContext.cpp"
    "opengl/OpenglGraphicsFactory.cpp"
)

target_include_directories(platform PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/glfw/include
${CMAKE_CURRENT_SOURCE_DIR}/opengl/include
)

target_link_libraries(platform PUBLIC glfw core PRIVATE glad renderer)

target_compile_definitions(platform PUBLIC GLFW_INCLUDE_NONE)