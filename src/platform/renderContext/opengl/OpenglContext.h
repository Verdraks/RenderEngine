#pragma once
#include "IRenderContext.h"
#include "GLFW/glfw3.h"

namespace Platform
{
	class OpenglContext : public IRenderContext
	{
	public:
		void Clear() override;
		void Flush() override;
		void SwapBuffers() override;

	public:
		OpenglContext(GLFWwindow *windowHandle);
		~OpenglContext();

	private:
		static void UpdateContext(GLFWwindow *window, int width, int height);
		GLFWwindow *m_windowHandle = nullptr;
	};
}
