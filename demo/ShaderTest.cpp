#include "Shader.h"
#include "Mesh.h"
#include "WindowsWindow.h"
#include <array>

constexpr int HEIGHT = 600;
constexpr int WIDTH = 800;
const char *TITLE = "Window Shader Test";

int main()
{
    const auto *window = new Platform::WindowsWindow(WIDTH, HEIGHT, TITLE);

    const char *assetsDir = ASSETS_DIR;

    const std::string vertexShaderPath = assetsDir + std::string("/shaders/vertex_shader.glsl");
    const std::string fragmentShaderPath = assetsDir + std::string("/shaders/fragment_shader.glsl");

    Shader *shader = new Shader(vertexShaderPath.c_str(), fragmentShaderPath.c_str());

    float vertices[] = {
        // positions         // colors
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
    };

    size_t verticesCount = std::size(vertices);
    size_t stride = 6 * sizeof(float);

    Mesh *triangle = new Mesh();
    triangle->BindVertices(vertices, verticesCount, GL_STATIC_DRAW);
    triangle->SetVertexAttributePos(stride);
    triangle->SetVertextAttributeColor(stride);

    while (window->IsOpen())
    {

        Platform::OpenglContext::Clear();

        // shader->SetVector("vertexOffset", { (float)sin(glfwGetTime()),0.0f, 0.0f });
        shader->Use();
        triangle->Draw();

        window->OnUpdate();
    }

    return 0;
}