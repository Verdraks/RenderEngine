#include "GlfwWindow.h"
#include "OpenglContext.h"

constexpr int HEIGHT = 600;
constexpr int WIDTH = 800;
const char *TITLE = "Window Test";

int main()
{

	const Core::WindowProperties properties{WIDTH, HEIGHT, TITLE};

	const Platform::GlfwWindow *window = new Platform::GlfwWindow(properties, nullptr);

	while (window->IsValid())
	{
		window->Update();
	}

	delete window;
	window = nullptr;

	return 0;
}
