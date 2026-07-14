#pragma once
#include <string>
#include <vector>
#include "glad/glad.h"
#include "glm/matrix.hpp"

class Shader
{
public:
	Shader(const char *vertexPath, const char *fragmentPath);

	void Use() const;

	void SetBool(const std::string &name, bool value) const;
	void SetInt(const std::string &name, int value) const;
	void SetFloat(const std::string &name, float value) const;
	void SetVector(const std::string &name, const std::array<float, 3> &value) const;
	void SetMatrix(const std::string &name, const float *valuePtr) const;

	unsigned int GetId() const { return m_id; }

private:
	unsigned int m_id;
	void CompileShader(unsigned int &shader, const char *shaderCode, const GLuint shaderType);
	void CompileShaderProgram(const std::vector<unsigned int> &shaders);
};