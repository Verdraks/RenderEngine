#pragma once
#include "RendererContext.h"

struct GLFWwindow;

namespace Platform
{

	class OpenglContext : public Core::RendererContext
	{
	public:
		OpenglContext();
		~OpenglContext();

	public:
		void Init(void *nativeHandle) override;
		void Clear() override;
		void SwapBuffers() override;

	private:
		static void UpdateContext(GLFWwindow *window, int width, int height);

	private:
		GLFWwindow *m_windowHandle = nullptr;
	};
}
