
#include <GLFW/glfw3.h>
#include "WindowsWindow.h"
#include "OpenglContext.h"

constexpr int HEIGHT = 600;
constexpr int WIDTH = 800;
const char* TITLE = "Window Test";

int main()
{

	const auto* window = new Platform::WindowsWindow(WIDTH, HEIGHT, TITLE);
	Platform::OpenglContext::InitContext(window);


	while (!glfwWindowShouldClose(window->GetNativeHandle()))
	{
		window->OnUpdate();
	}

	delete window;
	window = nullptr;

	return 0;
}
