#pragma once

#include "OpenglContext.h"
#include <GLFW/glfw3.h>

namespace Platform
{
	class Window
	{
	public:
		Window(const int width, const int height, const char *title);
		~Window();
		void OnPreUpdate() const;
		void OnUpdate() const;
		bool IsOpen() const;

		GLFWwindow *GetNativeHandle() const { return m_windowHandle; }
		int GetWidth() const { return m_width; }
		int GetHeight() const { return m_height; }

	private:
		void ProcessInputs() const;

		GLFWwindow *m_windowHandle = nullptr;
		Platform::OpenglContext *m_context = nullptr;
		int m_width = 0;
		int m_height = 0;
	};
}
