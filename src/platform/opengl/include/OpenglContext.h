#pragma once
#include "RendererContext.h"

struct GLFWwindow;

namespace Platform
{

	class OpenglContext : public Core::RendererContext
	{
	public:
		OpenglContext(GLFWwindow *windowHandle);
		~OpenglContext();

	public:
		void Init() override;
		void Clear() override;
		void SwapBuffers() override;

	private:
		static void UpdateContext(GLFWwindow *window, int width, int height);

	private:
		GLFWwindow *m_windowHandle = nullptr;
	};
}
