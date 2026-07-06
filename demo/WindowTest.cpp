#include "Window.h"
#include "OpenglContext.h"

constexpr int HEIGHT = 600;
constexpr int WIDTH = 800;
const char *TITLE = "Window Test";

int main()
{
	const auto *window = new Platform::Window(WIDTH, HEIGHT, TITLE);

	while (window->IsOpen())
	{
		window->OnPreUpdate();
		window->OnUpdate();
	}

	delete window;
	window = nullptr;

	return 0;
}
