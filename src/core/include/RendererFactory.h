#pragma once

#include "Buffer.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

namespace Core
{
    class RendererFactory
    {
    public:
        virtual ~RendererFactory() = default;

        virtual Renderer::Mesh *CreateMesh(const float vertices[], const unsigned int verticesCount) = 0;
        virtual Renderer::Mesh *CreateMesh(const float vertices[], const unsigned int verticesCount, const unsigned int indices[], const unsigned int indicesCount) = 0;

        virtual Renderer::Shader *CreateShader(const char *vertexSource, const char *fragmentSource) = 0;

        virtual Renderer::VertexBuffer *CreateVertexBuffer(const float *data, unsigned int size, unsigned int usage) = 0;
        virtual Renderer::IndexBuffer *CreateIndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage) = 0;
        virtual Renderer::VertexArrayBuffer *CreateVertexArrayBuffer() = 0;

        virtual Renderer::Texture *CreateTexture(const char *filePath) = 0;
    };
}