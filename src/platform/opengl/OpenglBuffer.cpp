#include "OpenglBuffer.h"
#include "glad/glad.h"

#pragma region Vertex Buffer
Platform::OpenglVertexBuffer::OpenglVertexBuffer(const void *data, unsigned int size, unsigned int usage) : Renderer::VertexBuffer(data, size, usage)
{
    glGenBuffers(1, &m_id);
}

Platform::OpenglVertexBuffer::~OpenglVertexBuffer()
{
    glDeleteBuffers(1, &m_id);
}
#pragma endregion Vertex Buffer

#pragma region Index Buffer
Platform::OpenglIndexBuffer::OpenglIndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage) : Renderer::IndexBuffer(data, count, usage)
{
    glGenBuffers(1, &m_id);
}

Platform::OpenglIndexBuffer::~OpenglIndexBuffer()
{
    glDeleteBuffers(1, &m_id);
}
#pragma endregion Index Buffer

#pragma region Vertex Array Buffer
Platform::OpenglVertexArrayBuffer::OpenglVertexArrayBuffer() : Renderer::VertexArrayBuffer()
{
    glGenVertexArrays(1, &m_id);
}

Platform::OpenglVertexArrayBuffer::~OpenglVertexArrayBuffer()
{
    glDeleteVertexArrays(1, &m_id);
}
#pragma endregion Vertex Array Buffer