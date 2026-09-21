#include "Window.h"

constexpr int HEIGHT = 600;
constexpr int WIDTH = 800;
const char *TITLE = "Window Test";

int main()
{

	const Core::WindowProperties properties{WIDTH, HEIGHT, TITLE};

	Core::Window *window = new Core::Window(properties);

	while (window->IsValid())
	{
		window->Update();
	}

	delete window;
	window = nullptr;

	return 0;
}
