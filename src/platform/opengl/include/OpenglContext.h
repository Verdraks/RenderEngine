#pragma once

#include "RendererContext.h"

struct GLFWwindow;

namespace Platform
{

	class OpenglContext final : public Core::RendererContext
	{
	public:
		OpenglContext();
		~OpenglContext();

	public:
		void Init(void *nativeHandle) override final;
		void Clear() override final;
		void SwapBuffers() override final;

	private:
		static void UpdateContext(GLFWwindow *window, int width, int height);

	private:
		GLFWwindow *m_windowHandle = nullptr;
	};
}
