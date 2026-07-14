#pragma once

#include "RendererFactory.h"

class OpenglRendererFactory : public Core::RendererFactory
{
public:
    OpenglRendererFactory();
    ~OpenglRendererFactory();

    Shader *CreateShader(const char *vertexSource, const char *fragmentSource) override;
    VertexBuffer *CreateVertexBuffer(const void *data, unsigned int size, unsigned int usage) override;
    IndexBuffer *CreateIndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage) override;
    VertexArrayBuffer *CreateVertexArrayBuffer() override;
};
