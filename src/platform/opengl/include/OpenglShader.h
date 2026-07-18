#pragma once

#include "Shader.h"
#include <glad/glad.h>
#include <vector>

namespace Platform
{
    class OpenglShader final : public Renderer::Shader
    {
    public:
        OpenglShader(const char *vertexPath, const char *fragmentPath);
        ~OpenglShader();

    public:
        void Bind() const override final;
        void Unbind() const override final;
        void SetBool(const std::string &name, const bool &value) const override final;
        void SetInt(const std::string &name, const int &value) const override final;
        void SetFloat(const std::string &name, const float &value) const override final;
        void SetVector(const std::string &name, const std::array<float, 3> &value) const override final;
        void SetMatrix(const std::string &name, const float *valuePtr) const override final;

    private:
        bool GetUniformLocation(const std::string &name, int &location) const;
        void CompileShader(unsigned int &shaderId, const char *shaderCode, const GLuint &shaderType) const;
        void CompileShaderProgram(const std::vector<unsigned int> &shadersId);

    private:
        unsigned int m_id;
    };
}