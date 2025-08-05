#pragma once

#include <GLFW/glfw3.h>

namespace Platform
{
	class WindowsWindow
	{
		public:
			WindowsWindow(const int width, const int height, const char* title);
			~WindowsWindow();
			void OnUpdate() const;
			GLFWwindow* GetNativeHandle() const;

			int GetWidth() const;
			int GetHeight() const;

		private:
			GLFWwindow* m_windowHandle = nullptr;
			int m_width = 0;
			int m_height = 0;
	};
}