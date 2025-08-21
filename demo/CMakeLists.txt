add_executable(DEMO_RENDER "DemoRender.cpp")
target_link_libraries(DEMO_RENDER PRIVATE glfw glad)

add_executable(WINDOW_TEST "WindowTest.cpp")
target_link_libraries(WINDOW_TEST PRIVATE platform)

add_executable(SHADER_TEST "ShaderTest.cpp")
target_link_libraries(SHADER_TEST PRIVATE renderer platform)