add_executable(DEMO_RENDER demoRender.cpp)
target_link_libraries(DEMO_RENDER PRIVATE glfw glad)

add_executable(WINDOW_TEST windowTest.cpp)
target_link_libraries(WINDOW_TEST PRIVATE platform glfw)