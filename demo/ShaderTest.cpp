#include "Texture.h"
#include "Shader.h"
#include "Mesh.h"
#include "Window.h"
#include <array>
#include <memory>
#include <math.h>
#include <iostream>

constexpr int HEIGHT = 600;
constexpr int WIDTH = 800;
const char *TITLE = "Window Shader Test";

int main()
{
    const std::unique_ptr<Platform::Window> window = std::make_unique<Platform::Window>(WIDTH, HEIGHT, TITLE);

    const std::string vertexShaderPath = ASSETS_DIR + std::string("/shaders/vertex_shader.glsl");
    const std::string fragmentShaderPath = ASSETS_DIR + std::string("/shaders/fragment_shader.glsl");
    const std::string texturePath = ASSETS_DIR + std::string("/textures/wall.jpg");

    const std::unique_ptr<Shader> shader = std::make_unique<Shader>(vertexShaderPath.c_str(), fragmentShaderPath.c_str());

    const std::unique_ptr<Texture> texture = std::make_unique<Texture>(texturePath.c_str());

    float vertices[] = {
        // positions          // colors           // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3};

    size_t verticesCount = std::size(vertices);
    size_t indicesCount = std::size(indices);
    size_t stride = 8 * sizeof(float);

    const std::unique_ptr<Mesh> triangle = std::make_unique<Mesh>(GL_STATIC_DRAW);
    triangle->BindVertices(vertices, verticesCount);
    triangle->BindIndices(indices, indicesCount);
    triangle->SetVertexAttributePos(stride);
    triangle->SetVertextAttributeColor(stride);
    triangle->SetVertexAttributeTexCoord(stride);

    while (window->IsOpen())
    {
        Platform::OpenglContext::Clean();

        window->OnPreUpdate();

        double time = glfwGetTime();
        float offsetY = sin(time) * 5.0f;
        float offsetX = cos(time) * 5.0f;

        shader->SetVector("vertexOffset", {offsetX, offsetY, 0.0f});
        texture->Use();
        shader->Use();
        triangle->Draw();

        Platform::OpenglContext::Clear();

        window->OnUpdate();
    }

    return 0;
}