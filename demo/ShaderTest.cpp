#include "Shader.h"
#include "Mesh.h"
#include "Window.h"
#include <array>
#include <memory>

constexpr int HEIGHT = 600;
constexpr int WIDTH = 800;
const char *TITLE = "Window Shader Test";

int main()
{
    const std::unique_ptr<Platform::Window> window = std::make_unique<Platform::Window>(WIDTH, HEIGHT, TITLE);

    const std::string vertexShaderPath = ASSETS_DIR + std::string("/shaders/vertex_shader.glsl");
    const std::string fragmentShaderPath = ASSETS_DIR + std::string("/shaders/fragment_shader.glsl");

    const std::unique_ptr<Shader> shader = std::make_unique<Shader>(vertexShaderPath.c_str(), fragmentShaderPath.c_str());

    float vertices[] = {
        // positions         // colors
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
    };

    unsigned int indices[] = {
        0, 1, 2 // triangle
    };

    size_t verticesCount = std::size(vertices);
    size_t indicesCount = std::size(indices);
    size_t stride = 6 * sizeof(float);

    const std::unique_ptr<Mesh> triangle = std::make_unique<Mesh>(GL_STATIC_DRAW);
    triangle->BindVertices(vertices, verticesCount);
    triangle->BindIndices(indices, indicesCount);
    triangle->SetVertexAttributePos(stride);
    triangle->SetVertextAttributeColor(stride);

    while (window->IsOpen())
    {
        window->OnPreUpdate();

        Platform::OpenglContext::Clear();

        // shader->SetVector("vertexOffset", {(float)sin(glfwGetTime()), 0.0f, 0.0f});
        shader->Use();
        triangle->Draw();

        window->OnUpdate();
    }

    return 0;
}