#include "Shader.h"
#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace Renderer;

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    std::ifstream vertexShaderFile;
    std::ifstream fragmentShaderFile;

    std::string vertexFileContent;
    std::string fragmentFileContent;

    vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        vertexShaderFile.open(vertexPath);
        vertexFileContent = std::string((std::istreambuf_iterator<char>(vertexShaderFile)), std::istreambuf_iterator<char>());
        vertexShaderFile.close();

        fragmentShaderFile.open(fragmentPath);
        fragmentFileContent = std::string((std::istreambuf_iterator<char>(fragmentShaderFile)), std::istreambuf_iterator<char>());
        fragmentShaderFile.close();
    }
    catch (const std::exception &exception)
    {
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << exception.what() << std::endl;
    }

    const char *vertexShaderCode = vertexFileContent.c_str();
    const char *fragmentShaderCode = fragmentFileContent.c_str();

    unsigned int vertexShader, fragmentShader;

    CompileShader(vertexShader, vertexShaderCode, GL_VERTEX_SHADER);
    CompileShader(fragmentShader, fragmentShaderCode, GL_FRAGMENT_SHADER);

    std::vector<unsigned int> shadersId = {vertexShader, fragmentShader};

    CompileShaderProgram(shadersId);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
    glDeleteProgram(m_id);
}

void Shader::Bind() const
{
    glUseProgram(m_id);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

void Shader::CompileShader(unsigned int &shaderId, const char *shaderCode, const GLuint &shaderType) const
{
    shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &shaderCode, nullptr);
    glCompileShader(shaderId);

    int success;
    char infoLog[512];
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shaderId, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n"
                  << infoLog << '\n';
    }
}

void Shader::CompileShaderProgram(const std::vector<unsigned int> &shadersId)
{
    m_id = glCreateProgram();

    for (auto shader : shadersId)
    {
        glAttachShader(m_id, shader);
    }

    glLinkProgram(m_id);

    int success;
    char infoLog[512];

    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(m_id, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << '\n';
    }
}

void Shader::SetBool(const std::string &name, const bool &value) const
{
    if (int location; GetUniformLocation(name, location))
    {
        glUniform1i(location, static_cast<int>(value));
    }
}

void Shader::SetInt(const std::string &name, const int &value) const
{
    if (int location; GetUniformLocation(name, location))
    {
        glUniform1i(location, value);
    }
}

void Shader::SetFloat(const std::string &name, const float &value) const
{
    if (int location; GetUniformLocation(name, location))
    {
        glUniform1f(location, value);
    }
}

void Shader::SetVector(const std::string &name, const std::array<float, 3> &value) const
{
    if (int location; GetUniformLocation(name, location))
    {
        glUniform3fv(location, 1, value.data());
    }
}

void Shader::SetMatrix(const std::string &name, const float *valuePtr) const
{
    if (int location; GetUniformLocation(name, location))
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, valuePtr);
    }
}

bool Shader::GetUniformLocation(const std::string &name, int &location) const
{
    location = glGetUniformLocation(m_id, name.c_str());
    if (location == -1)
    {
        std::cerr << "ERROR::SHADER::UNIFORM_NOT_FOUND: " << name << '\n';
        return false;
    }
    return true;
}
