#pragma once

#include "RendererContext.h"
#include "Window.h"
#include <GLFW/glfw3.h>

namespace Platform
{
	class GlfwWindow : public Core::Window
	{

	public:
		inline bool IsValid() const override
		{
			return m_windowHandle != nullptr && !glfwWindowShouldClose(this->m_windowHandle);
		}

		void Update() const override;

	public:
		GlfwWindow(const Core::WindowProperties &properties, std::unique_ptr<Core::RendererContext> context);
		~GlfwWindow();

		GLFWwindow *GetNativeHandle() const { return m_windowHandle; }

	private:
		GLFWwindow *m_windowHandle = nullptr;
	};
}