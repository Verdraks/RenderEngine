#pragma once
#include "GLFW/glfw3.h"

namespace Platform
{
	class OpenglContext
	{
		public:
			OpenglContext(GLFWwindow* windowHandle);
			void Init() const;
			void SwapBuffer() const;
		private:
			GLFWwindow* m_windowHandle = nullptr;
	};
}
