#pragma once
#include <array>
#include <glad/glad.h>
#include <string>
#include <vector>

namespace Renderer
{
	class Shader final
	{
	public:
		Shader(const char *vertexPath, const char *fragmentPath);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void SetBool(const std::string &name, const bool &value) const;
		void SetInt(const std::string &name, const int &value) const;
		void SetFloat(const std::string &name, const float &value) const;
		void SetVector(const std::string &name, const std::array<float, 3> &value) const;
		void SetMatrix(const std::string &name, const float *valuePtr) const;

	private:
		bool GetUniformLocation(const std::string &name, int &location) const;
		void CompileShader(unsigned int &shaderId, const char *shaderCode, const GLuint &shaderType) const;
		void CompileShaderProgram(const std::vector<unsigned int> &shadersId);

	private:
		unsigned int m_id;
	};
}