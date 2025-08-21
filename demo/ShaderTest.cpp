#include "Shader.h"
#include "WindowsWindow.h"

constexpr int HEIGHT = 600;
constexpr int WIDTH = 800;
const char* TITLE = "Window Shader Test";


int main() {

	const auto* window = new Platform::WindowsWindow(WIDTH, HEIGHT, TITLE);

	const char* assetsDir = ASSETS_DIR;

	const std::string vertexShaderPath = assetsDir + std::string("/shaders/vertex_shader.glsl");
	const std::string fragmentShaderPath = assetsDir + std::string("/shaders/fragment_shader.glsl");

	Shader* shader = new Shader(vertexShaderPath.c_str(), fragmentShaderPath.c_str());



	return 0;
}