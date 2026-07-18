#pragma once
#include "glad/glad.h"
#include <string>

namespace Renderer
{
    class Mesh
    {
    public:
        Mesh(const float vertices[], const unsigned int verticesCount) {}
        Mesh(const float vertices[], const unsigned int verticesCount, const unsigned int indices[], const unsigned int indicesCount) {}
        virtual ~Mesh() = default;

        virtual void SetVertexAttribute(const int location, const int size, const GLuint type, const size_t &stride, const void *const ptrAttribute) = 0;
        virtual void MarkDynamic() = 0;
        virtual void MarkStatic() = 0;
        virtual void Draw() const = 0;
    };
}