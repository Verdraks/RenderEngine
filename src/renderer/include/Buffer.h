#pragma once

namespace Renderer
{
    class VertexBuffer
    {
    public:
        VertexBuffer(const void *data, unsigned int size, unsigned int usage) {};
        virtual ~VertexBuffer() = default;

        virtual void Bind() = 0;
        virtual void Unbind() = 0;
    };

    class IndexBuffer
    {
    public:
        IndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage) {};
        ~IndexBuffer() = default;

        virtual void Bind() = 0;
        virtual void Unbind() = 0;
    };

    class VertexArrayBuffer
    {
    public:
        VertexArrayBuffer() {};
        ~VertexArrayBuffer() = default;

        virtual void Bind() = 0;
        virtual void Unbind() = 0;
    };
}