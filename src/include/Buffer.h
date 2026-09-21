#pragma once

namespace Renderer
{
    class VertexBuffer final
    {
    public:
        VertexBuffer(const float *data, unsigned int count, unsigned int usage);
        ~VertexBuffer();

        void Bind();
        void Unbind();

        inline unsigned int GetCount() const { return m_count; }

    private:
        unsigned int m_count;
        unsigned int m_id;
    };

    class IndexBuffer final
    {
    public:
        IndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage);
        ~IndexBuffer();

                void Bind();
        void Unbind();

        inline unsigned int GetCount() const { return m_count; }

    private:
        unsigned int m_count;
        unsigned int m_id;
    };

    class VertexArrayBuffer final
    {
    public:
        VertexArrayBuffer();
        ~VertexArrayBuffer();

        void Bind();
        void Unbind();

    private:
        unsigned int m_id;
    };
}