#include "Mesh.h"
#include "glad/glad.h"
#include <iostream>
#include <stdexcept>

using namespace Renderer;

Mesh::Mesh(const float vertices[], const unsigned int verticesCount)
{
    this->m_vertexBuffer = std::make_unique<VertexBuffer>(vertices, verticesCount, GL_STATIC_DRAW);
    m_vertexArrayBuffer = std::make_unique<VertexArrayBuffer>();

    // Bind buffers to the vertex array buffer
    m_vertexArrayBuffer->Bind();
    m_vertexBuffer->Bind();
    m_vertexArrayBuffer->Unbind();
    m_vertexBuffer->Unbind();
}

Mesh::Mesh(const float vertices[], const unsigned int verticesCount, const unsigned int indices[], const unsigned int indicesCount)
{
    m_vertexBuffer = std::make_unique<VertexBuffer>(vertices, verticesCount, GL_STATIC_DRAW);
    m_indexBuffer = std::make_unique<IndexBuffer>(indices, indicesCount, GL_STATIC_DRAW);
    m_vertexArrayBuffer = std::make_unique<VertexArrayBuffer>();

    // Bind buffers to the vertex array buffer
    m_vertexArrayBuffer->Bind();
    m_vertexBuffer->Bind();
    m_indexBuffer->Bind();
    m_vertexArrayBuffer->Unbind();
    m_vertexBuffer->Unbind();
    m_indexBuffer->Unbind();
}

Mesh::~Mesh()
{
    m_indexBuffer.reset();
    m_vertexBuffer.reset();
    m_vertexArrayBuffer.reset();
}

void Mesh::SetVertexAttribute(const int location, const int size, const GLuint type, const size_t &stride, const void *const ptrAttribute)
{
    m_vertexArrayBuffer->Bind();
    m_vertexBuffer->Bind();
    glVertexAttribPointer(location, size, type, GL_FALSE, stride, ptrAttribute);
    glEnableVertexAttribArray(location);
    m_vertexArrayBuffer->Unbind();
    m_vertexBuffer->Unbind();
}

void Mesh::MarkDynamic()
{
    throw std::runtime_error(std::string(__func__) + " not implemented yet.");
}

void Mesh::MarkStatic()
{
    throw std::runtime_error(std::string(__func__) + " not implemented yet.");
}

void Mesh::Draw() const
{
    m_vertexArrayBuffer->Bind();
    if (m_indexBuffer != nullptr)
    {
        glDrawElements(GL_TRIANGLES, m_indexBuffer->GetCount(), GL_UNSIGNED_INT, 0);
    }
    else
    {
        glDrawArrays(GL_TRIANGLES, 0, m_vertexBuffer->GetCount());
    }
    m_vertexArrayBuffer->Unbind();
}
