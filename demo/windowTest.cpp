
#include "window.h"
#include <GLFW/glfw3.h>

constexpr int HEIGHT = 600;
constexpr int WIDTH = 800;
const char* TITLE = "Window Test";

int main()
{

	auto* window = Platform::Window::Create(WIDTH,HEIGHT,TITLE);

	GLFWwindow* nativeHandle = static_cast<GLFWwindow*>(window->GetNativeHandle());

	while (!glfwWindowShouldClose(nativeHandle))
	{
		window->OnUpdate();
	}

	delete window;
	window = nullptr;

	return 0;
}
