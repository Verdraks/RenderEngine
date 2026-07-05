#pragma once
#include <string>
#include "glad/glad.h"

class Mesh
{
public:
    Mesh();
    ~Mesh();
    void BindVertices(const float vertices[], const size_t verticesCount, GLuint usage);
    void SetVertexAttributePos(const size_t &stride);
    void SetVertextAttributeColor(const size_t &stride);
    void Draw();

    unsigned int GetVao() const { return m_vao; }
    unsigned int GetVbo() const { return m_vbo; }
    unsigned int GetEbo() const { return m_ebo; }

private:
    void SetVertexAttribute(const size_t &stride, const void *const ptrAttribute);

    unsigned int m_vbo, m_vao, m_ebo;
};