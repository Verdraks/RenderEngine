#pragma once

#include "RendererFactory.h"

namespace Platform
{
    class OpenglRendererFactory final : public Core::RendererFactory
    {
    public:
        OpenglRendererFactory();
        ~OpenglRendererFactory();

        Shader *CreateShader(const char *vertexSource, const char *fragmentSource) override final;
        VertexBuffer *CreateVertexBuffer(const void *data, unsigned int size, unsigned int usage) override final;
        IndexBuffer *CreateIndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage) override final;
        VertexArrayBuffer *CreateVertexArrayBuffer() override final;
    };
}
