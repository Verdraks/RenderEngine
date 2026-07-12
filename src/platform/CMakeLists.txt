add_library(platform)

target_sources(platform PRIVATE
    
    "window/Window.cpp"
    "renderContext/opengl/OpenglContext.cpp"
)

target_compile_definitions(platform PUBLIC GLFW_INCLUDE_NONE)
target_link_libraries(platform PUBLIC glfw PRIVATE glad)
target_include_directories(platform PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/window
    ${CMAKE_CURRENT_SOURCE_DIR}/renderContext/opengl
    ${CMAKE_CURRENT_SOURCE_DIR}/renderContext
)