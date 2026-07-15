#pragma once

#include "Shader.h"

namespace Platform
{
    class OpenglShader : public Renderer::Shader
    {
    private:
        /* data */
    public:
        OpenglShader(const char *vertexPath, const char *fragmentPath);

        ~OpenglShader();
    };

    OpenglShader::OpenglShader(const char *vertexPath, const char *fragmentPath) : Shader(vertexPath, fragmentPath)
    {
    }

    OpenglShader::~OpenglShader()
    {
    }
}