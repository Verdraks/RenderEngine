add_library(platform)

target_sources(platform PRIVATE
    
    "window/Window.cpp"
    "opengl/OpenglContext.cpp"
)

target_link_libraries(platform PUBLIC glfw PRIVATE glad)
target_include_directories(platform PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/window
    ${CMAKE_CURRENT_SOURCE_DIR}/opengl
)