#pragma once

#include "Buffer.h"

namespace Platform
{
    class OpenglVertexBuffer : public Renderer::VertexBuffer
    {
    public:
        OpenglVertexBuffer();
        ~OpenglVertexBuffer();

        void Bind() override;
        void Unbind() override;
    };

    class OpenglIndexBuffer : public Renderer::IndexBuffer
    {
    public:
        OpenglIndexBuffer();
        ~OpenglIndexBuffer();

        void Bind() override;
        void Unbind() override;
    };

    class OpenglVertexArrayBuffer : public Renderer::VertexArrayBuffer
    {
    public:
        OpenglVertexArrayBuffer();
        ~OpenglVertexArrayBuffer();

        void Bind() override;
        void Unbind() override;
    };
}