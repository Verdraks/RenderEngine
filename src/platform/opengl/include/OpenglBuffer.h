#pragma once

#include "Buffer.h"

namespace Platform
{
    class OpenglVertexBuffer : public Renderer::VertexBuffer
    {
    public:
        OpenglVertexBuffer(const void *data, unsigned int size, unsigned int usage);
        ~OpenglVertexBuffer();

        void Bind() override;
        void Unbind() override;

    private:
        unsigned int m_id;
    };

    class OpenglIndexBuffer : public Renderer::IndexBuffer
    {
    public:
        OpenglIndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage);
        ~OpenglIndexBuffer();

        void Bind() override;
        void Unbind() override;

    private:
        unsigned int m_id;
    };

    class OpenglVertexArrayBuffer : public Renderer::VertexArrayBuffer
    {
    public:
        OpenglVertexArrayBuffer();
        ~OpenglVertexArrayBuffer();

        void Bind() override;
        void Unbind() override;

    private:
        unsigned int m_id;
    };
}