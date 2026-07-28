#pragma once

#include "Mesh.h"
#include "OpenglBuffer.h"
#include <memory>

namespace Platform
{

    class OpenglMesh final : public Renderer::Mesh
    {
    public:
        OpenglMesh(const float vertices[], const unsigned int verticesCount);
        OpenglMesh(const float vertices[], const unsigned int verticesCount, const unsigned int indices[], const unsigned int indicesCount);
        ~OpenglMesh();

        void SetVertexAttribute(const int location, const int size, const GLuint type, const size_t &stride, const void *const ptrAttribute) override final;
        void MarkDynamic() override final;
        void MarkStatic() override final;
        void Draw() const override final;

    private:
        std::unique_ptr<OpenglVertexBuffer> m_vertexBuffer;
        std::unique_ptr<OpenglIndexBuffer> m_indexBuffer;
        std::unique_ptr<OpenglVertexArrayBuffer> m_vertexArrayBuffer;
    };

}
