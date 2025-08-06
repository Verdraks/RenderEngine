
#include <GLFW/glfw3.h>
#include "WindowsWindow.h"
#include "OpenglContext.h"

constexpr int HEIGHT = 600;
constexpr int WIDTH = 800;
const char* TITLE = "Window Test";

int main()
{
	const auto* window = new Platform::WindowsWindow(WIDTH, HEIGHT, TITLE);

	while (window->IsOpen())
	{
		window->OnUpdate();
	}

	delete window;
	window = nullptr;

	return 0;
}
