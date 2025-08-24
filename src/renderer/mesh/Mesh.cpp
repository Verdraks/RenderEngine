#include "Mesh.h"
#include "glad/glad.h"

Mesh::Mesh()
{
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
}

Mesh::~Mesh()
{
    glDeleteBuffers(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
}

void Mesh::BindVertices(const float vertices[], const size_t verticesCount, GLuint usage)
{
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, verticesCount, vertices, usage);
    glBindVertexArray(0);
}

void Mesh::SetVertexAttributePos(const size_t &stride)
{
    SetVertexAttribute(stride, (void *)(0));
    glEnableVertexArrayAttrib(0);
}

void Mesh::SetVertextAttributeColor(const size_t &stride)
{
    SetVertexAttribute(stride, (void *)(3 * sizeof(float)));
}

void Mesh::SetVertexAttribute(const size_t &stride, const void *const ptrAttribute)
{

    glBindVertexArray(m_vao);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, ptrAttribute);
}

void Mesh::Draw()
{
    glBindVertexArray(m_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
