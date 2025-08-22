#pragma once
#include "GLFW/glfw3.h"

namespace Platform
{
	class OpenglContext
	{
		public:
			OpenglContext(GLFWwindow* windowHandle);
			void SwapBuffer() const;
		private:
			static void UpdateContext(GLFWwindow* window, int width, int height);
			GLFWwindow* m_windowHandle = nullptr;
	};
}
