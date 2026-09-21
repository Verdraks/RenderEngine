#pragma once
#include "Buffer.h"
#include "glad/glad.h"
#include <memory>
#include <string>

namespace Renderer
{
    class Mesh final
    {
    public:
        Mesh(const float vertices[], const unsigned int verticesCount);
        Mesh(const float vertices[], const unsigned int verticesCount, const unsigned int indices[], const unsigned int indicesCount);
        ~Mesh();

        void SetVertexAttribute(const int location, const int size, const GLuint type, const size_t &stride, const void *const ptrAttribute);
        void MarkDynamic();
        void MarkStatic();
        void Draw() const;

    private:
        std::unique_ptr<VertexBuffer> m_vertexBuffer;
        std::unique_ptr<IndexBuffer> m_indexBuffer;
        std::unique_ptr<VertexArrayBuffer> m_vertexArrayBuffer;
    };

}