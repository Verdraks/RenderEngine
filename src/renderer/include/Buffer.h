#pragma once

namespace Renderer
{
    class VertexBuffer
    {
    public:
        VertexBuffer(const float *data, unsigned int count, unsigned int usage) : m_count(count) {};
        virtual ~VertexBuffer() = default;

        virtual void Bind() = 0;
        virtual void Unbind() = 0;

        inline unsigned int GetCount() const { return m_count; }

    private:
        unsigned int m_count;
    };

    class IndexBuffer
    {
    public:
        IndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage) : m_count(count) {};
        ~IndexBuffer() = default;

        virtual void Bind() = 0;
        virtual void Unbind() = 0;

        inline unsigned int GetCount() const { return m_count; }

    private:
        unsigned int m_count;
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