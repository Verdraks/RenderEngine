#include "OpenglBuffer.h"
#include "glad/glad.h"

#include <iostream>

using namespace Platform;

#pragma region Vertex Buffer
OpenglVertexBuffer::OpenglVertexBuffer(const float *data, unsigned int count, unsigned int usage) : Renderer::VertexBuffer(data, count, usage)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, usage);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

OpenglVertexBuffer::~OpenglVertexBuffer()
{
    glDeleteBuffers(1, &m_id);
}
void OpenglVertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void OpenglVertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
#pragma endregion Vertex Buffer

#pragma region Index Buffer
OpenglIndexBuffer::OpenglIndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage) : Renderer::IndexBuffer(data, count, usage)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, usage);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

OpenglIndexBuffer::~OpenglIndexBuffer()
{
    glDeleteBuffers(1, &m_id);
}
void OpenglIndexBuffer::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}
void OpenglIndexBuffer::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
#pragma endregion Index Buffer

#pragma region Vertex Array Buffer
OpenglVertexArrayBuffer::OpenglVertexArrayBuffer() : Renderer::VertexArrayBuffer()
{
    glGenVertexArrays(1, &m_id);
}

OpenglVertexArrayBuffer::~OpenglVertexArrayBuffer()
{
    glDeleteVertexArrays(1, &m_id);
}
void OpenglVertexArrayBuffer::Bind()
{
    glBindVertexArray(m_id);
}
void OpenglVertexArrayBuffer::Unbind()
{
    glBindVertexArray(0);
}
#pragma endregion Vertex Array Buffer