#include "Mesh.h"

Mesh::Mesh(GLuint usage)
{
    m_usage = usage;
    m_vertexCount = 0;
    m_indicesCount = 0;

    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
    glDeleteBuffers(1, &m_ebo);
}

void Mesh::BindVertices(const float vertices[], const size_t verticesCount)
{
    m_vertexCount = verticesCount;

    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, verticesCount * sizeof(float), vertices, m_usage);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::BindIndices(const unsigned int indices[], const size_t indicesCount)
{
    m_indicesCount = indicesCount;

    glBindVertexArray(m_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesCount * sizeof(unsigned int), indices, m_usage);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::SetVertexAttributePos(const size_t &stride)
{
    SetVertexAttribute(0, 3, GL_FLOAT, stride, (void *)(0));
}

void Mesh::SetVertextAttributeColor(const size_t &stride)
{
    SetVertexAttribute(1, 3, GL_FLOAT, stride, (void *)(3 * sizeof(float)));
}

void Mesh::SetVertexAttribute(const int location, const int size, const GLuint type, const size_t &stride, const void *const ptrAttribute)
{
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glVertexAttribPointer(location, size, type, GL_FALSE, stride, ptrAttribute);
    glEnableVertexAttribArray(location);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Mesh::Draw()
{
    glBindVertexArray(m_vao);
    glDrawElements(GL_TRIANGLES, m_indicesCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
