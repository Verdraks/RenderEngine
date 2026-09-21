add_executable(WindowTest "WindowTest.cpp")
target_link_libraries(WindowTest PRIVATE src)

add_executable(ShaderTest "ShaderTest.cpp")
target_link_libraries(ShaderTest PRIVATE src glm::glm-header-only)