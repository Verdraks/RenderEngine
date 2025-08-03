#include <glad/glad.h>
#include "WindowGlfw.h"
#include <iostream>

Platform::WindowGlfw::WindowGlfw(const int width, const int height, const char* title)
{
	if (!glfwInit())
	{
		throw std::runtime_error("Failed to initialize GLFW");
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	m_WindowHandle = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!m_WindowHandle)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}
	glfwMakeContextCurrent(m_WindowHandle);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwDestroyWindow(m_WindowHandle);
		m_WindowHandle = nullptr;
		glfwTerminate();
		throw std::runtime_error("Failed to initialize GLAD");
	}

	glViewport(0, 0, width, height);

}

Platform::WindowGlfw::~WindowGlfw()
{
	if (m_WindowHandle)
	{
		glfwDestroyWindow(m_WindowHandle);
		m_WindowHandle = nullptr;
	}
	glfwTerminate();
}

void Platform::WindowGlfw::OnUpdate()
{
	glfwPollEvents();
	glfwSwapBuffers(m_WindowHandle);
}

void* Platform::WindowGlfw::GetNativeHandle() const
{
	return m_WindowHandle;
}
