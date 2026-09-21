#include "Buffer.h"
#include "glad/glad.h"

#include <iostream>

using namespace Renderer;

#pragma region Vertex Buffer
VertexBuffer::VertexBuffer(const float *data, unsigned int count, unsigned int usage) : m_count(count)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, usage);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_id);
}
void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
#pragma endregion Vertex Buffer

#pragma region Index Buffer
IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage) : m_count(count)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, usage);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_id);
}
void IndexBuffer::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}
void IndexBuffer::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
#pragma endregion Index Buffer

#pragma region Vertex Array Buffer
VertexArrayBuffer::VertexArrayBuffer()
{
    glGenVertexArrays(1, &m_id);
}

VertexArrayBuffer::~VertexArrayBuffer()
{
    glDeleteVertexArrays(1, &m_id);
}
void VertexArrayBuffer::Bind()
{
    glBindVertexArray(m_id);
}
void VertexArrayBuffer::Unbind()
{
    glBindVertexArray(0);
}
#pragma endregion Vertex Array Buffer