add_library(platform)

target_sources(platform PRIVATE
    window.cpp
    glfw/windowglfw.cpp
)

target_link_libraries(platform PRIVATE glfw glad)
target_include_directories(platform PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/glfw
)