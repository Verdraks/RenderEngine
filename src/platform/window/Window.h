#pragma once

#include "IWindow.h"
#include "IRenderContext.h"
#include <GLFW/glfw3.h>

namespace Platform
{
	class Window : IWindow
	{

	public:
		void Update() const override;
		void LateUpdate() const override;
		bool IsValid() const override
		{
			return m_windowHandle != nullptr && !glfwWindowShouldClose(this->m_windowHandle);
		}

	public:
		Window(const int width, const int height, const char *title);
		~Window();

		void SetContext(Platform::IRenderContext *const context) { m_context = context; }

		GLFWwindow *GetNativeHandle() const { return m_windowHandle; }
		int GetWidth() const { return m_width; }
		int GetHeight() const { return m_height; }

	private:
		void ProcessInputs() const;

		GLFWwindow *m_windowHandle = nullptr;
		Platform::IRenderContext *m_context = nullptr;
		int m_width = 0;
		int m_height = 0;
	};
}
