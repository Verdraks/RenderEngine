#include "Window.h"
#include "OpenglContext.h"

constexpr int HEIGHT = 600;
constexpr int WIDTH = 800;
const char *TITLE = "Window Test";

int main()
{
	const Platform::Window *window = new Platform::Window(WIDTH, HEIGHT, TITLE);

	while (window->IsValid())
	{
		window->Update();
		window->LateUpdate();
	}

	delete window;
	window = nullptr;

	return 0;
}
