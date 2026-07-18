#pragma once

#include "Buffer.h"

namespace Platform
{
    class OpenglVertexBuffer final : public Renderer::VertexBuffer
    {
    public:
        OpenglVertexBuffer(const float *data, unsigned int count, unsigned int usage);
        ~OpenglVertexBuffer();

        void Bind() override final;
        void Unbind() override final;

    private:
        unsigned int m_id;
    };

    class OpenglIndexBuffer final : public Renderer::IndexBuffer
    {
    public:
        OpenglIndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage);
        ~OpenglIndexBuffer();

        void Bind() override final;
        void Unbind() override final;

    private:
        unsigned int m_id;
    };

    class OpenglVertexArrayBuffer final : public Renderer::VertexArrayBuffer
    {
    public:
        OpenglVertexArrayBuffer();
        ~OpenglVertexArrayBuffer();

        void Bind() override final;
        void Unbind() override final;

    private:
        unsigned int m_id;
    };
}