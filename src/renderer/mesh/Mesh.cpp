#include "Mesh.h"
#include <iostream>
Mesh::Mesh(GLuint usage)
{
    m_usage = usage;

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

void Mesh::SetVertexAttribute(const int location, const int size, const GLuint type, const size_t &stride, const void *const ptrAttribute)
{
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glVertexAttribPointer(location, size, type, GL_FALSE, stride, ptrAttribute);
    glEnableVertexAttribArray(location);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::Draw()
{
    if (m_indicesCount == 0)
    {
        glBindVertexArray(m_vao);
        glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
        glBindVertexArray(0);
    }
    else
    {
        glBindVertexArray(m_vao);
        glDrawElements(GL_TRIANGLES, m_indicesCount, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
}
