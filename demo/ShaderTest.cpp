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

    float vertices[] = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


	while (window->IsOpen())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
		shader->Use();


		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		window->OnUpdate();
	}

	return 0;
}