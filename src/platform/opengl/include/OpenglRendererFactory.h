#pragma once

#include "RendererFactory.h"

namespace Platform
{
    class OpenglRendererFactory final : public Core::RendererFactory
    {
    public:
        OpenglRendererFactory();
        ~OpenglRendererFactory();

        Renderer::Mesh *CreateMesh(const float vertices[], const unsigned int verticesCount) override final;
        Renderer::Mesh *CreateMesh(const float vertices[], const unsigned int verticesCount, const unsigned int indices[], const unsigned int indicesCount) override final;

        Renderer::Shader *CreateShader(const char *vertexSource, const char *fragmentSource) override final;

        Renderer::VertexBuffer *CreateVertexBuffer(const float *data, unsigned int size, unsigned int usage) override final;
        Renderer::IndexBuffer *CreateIndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage) override final;
        Renderer::VertexArrayBuffer *CreateVertexArrayBuffer() override final;

        Renderer::Texture *CreateTexture(const char *filePath) override final;
    };
}
