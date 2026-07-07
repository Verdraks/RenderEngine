#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>

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

	std::vector<unsigned int> shaders = {vertexShader, fragmentShader};

	CompileShaderProgram(shaders);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::CompileShaderProgram(const std::vector<unsigned int> &shaders)
{
	m_id = glCreateProgram();

	for (auto shader : shaders)
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

void Shader::CompileShader(unsigned int &shader, const char *shaderCode, GLuint shaderType)
{
	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderCode, nullptr);
	glCompileShader(shader);

	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n"
				  << infoLog << '\n';
	}
}

void Shader::Use() const
{
	glUseProgram(m_id);
}

void Shader::SetBool(const std::string &name, bool value) const
{
	int location = glGetUniformLocation(m_id, name.c_str());
	if (location == -1)
	{
		std::cerr << "ERROR::SHADER::UNIFORM_NOT_FOUND: " << name << '\n';
		return;
	}
	glUniform1i(location, static_cast<int>(value));
}

void Shader::SetInt(const std::string &name, int value) const
{
	int location = glGetUniformLocation(m_id, name.c_str());
	if (location == -1)
	{
		std::cerr << "ERROR::SHADER::UNIFORM_NOT_FOUND: " << name << '\n';
		return;
	}
	glUniform1i(location, value);
}

void Shader::SetFloat(const std::string &name, float value) const
{
	int location = glGetUniformLocation(m_id, name.c_str());
	if (location == -1)
	{
		std::cerr << "ERROR::SHADER::UNIFORM_NOT_FOUND: " << name << '\n';
		return;
	}
	glUniform1f(location, value);
}

void Shader::SetVector(const std::string &name, const std::array<float, 3> &value) const
{
	int location = glGetUniformLocation(m_id, name.c_str());
	if (location == -1)
	{
		std::cerr << "ERROR::SHADER::UNIFORM_NOT_FOUND: " << name << '\n';
		return;
	}
	glUniform3fv(location, 1, value.data());
}