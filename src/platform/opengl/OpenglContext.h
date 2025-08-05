#pragma once
#include "WindowsWindow.h"

namespace Platform
{
	class OpenglContext
	{
		public:
			static void InitContext(const WindowsWindow* windowsWindow);
			static void UpdateContext(GLFWwindow* window, int width, int height);
	};
}
