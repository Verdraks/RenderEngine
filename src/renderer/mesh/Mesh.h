#pragma once
#include <string>
#include "glad/glad.h"

class Mesh
{
public:
    Mesh(GLuint usage);
    ~Mesh();
    void BindVertices(const float vertices[], const size_t verticesCount);
    void BindIndices(const unsigned int indices[], const size_t indicesCount);
    void SetVertexAttributePos(const size_t &stride);
    void SetVertextAttributeColor(const size_t &stride);
    void SetVertexAttributeTexCoord(const size_t &stride);
    void Draw();

    unsigned int GetVao() const { return m_vao; }
    unsigned int GetVbo() const { return m_vbo; }
    unsigned int GetEbo() const { return m_ebo; }

private:
    void SetVertexAttribute(const int location, const int size, const GLuint type, const size_t &stride, const void *const ptrAttribute);

    unsigned int m_vbo, m_vao, m_ebo;

    unsigned int m_vertexCount;
    unsigned int m_indicesCount;

    GLuint m_usage;
};