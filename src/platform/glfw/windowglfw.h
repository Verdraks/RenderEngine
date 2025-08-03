#pragma once

#include "../window.h"
#include <GLFW/glfw3.h>

namespace Platform
{
	class WindowGlfw : public Window 
	{
		public:
			WindowGlfw(const int width, const int height, const char* title);
			~WindowGlfw() override;
			void OnUpdate() override;
			void* GetNativeHandle() const override;

		private:
			GLFWwindow* m_WindowHandle;
	};
}