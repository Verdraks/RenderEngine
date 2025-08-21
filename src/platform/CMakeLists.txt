add_library(platform)

target_sources(platform PRIVATE
    
    "windows/WindowsWindow.cpp"
    "opengl/OpenglContext.cpp"
)

target_link_libraries(platform PUBLIC glfw PRIVATE glad)
target_include_directories(platform PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/windows
    ${CMAKE_CURRENT_SOURCE_DIR}/opengl
)