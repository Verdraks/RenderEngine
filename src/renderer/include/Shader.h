#pragma once
#include <array>
#include <string>

namespace Renderer
{
	class Shader
	{
	public:
		Shader(const char *vertexPath, const char *fragmentPath) {};
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetBool(const std::string &name, const bool &value) const = 0;
		virtual void SetInt(const std::string &name, const int &value) const = 0;
		virtual void SetFloat(const std::string &name, const float &value) const = 0;
		virtual void SetVector(const std::string &name, const std::array<float, 3> &value) const = 0;
		virtual void SetMatrix(const std::string &name, const float *valuePtr) const = 0;
	};
}