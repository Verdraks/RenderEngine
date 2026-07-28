add_executable(WindowTest "WindowTest.cpp")
target_link_libraries(WindowTest PRIVATE  platform)

add_executable(ShaderTest "ShaderTest.cpp")
target_link_libraries(ShaderTest PRIVATE renderer platform glm::glm-header-only)