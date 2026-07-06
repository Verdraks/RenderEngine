#include "Window.h"
#include <stdexcept>

Platform::Window::Window(const int width, const int height, const char *title)
{
	if (!glfwInit())
	{
		throw std::runtime_error("Failed to initialize GLFW");
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// TODO_OM: Separte target profile link to renderer and platform.
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	m_windowHandle = glfwCreateWindow(width, height, title, nullptr, nullptr);

	m_width = width;
	m_height = height;

	if (!m_windowHandle)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}
	// TODO_OM: Separte context creation to renderer and platform.
	m_context = new OpenglContext(m_windowHandle);
}

Platform::Window::~Window()
{
	if (m_windowHandle != nullptr)
	{
		glfwDestroyWindow(m_windowHandle);
		m_windowHandle = nullptr;
	}
	glfwTerminate();
}

void Platform::Window::OnPreUpdate() const
{
	ProcessInputs();
}

void Platform::Window::OnUpdate() const
{
	m_context->SwapBuffer();
	glfwPollEvents();
}

void Platform::Window::ProcessInputs() const
{
	if (glfwGetKey(m_windowHandle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_windowHandle, true);
	}
}

bool Platform::Window::IsOpen() const
{
	return !glfwWindowShouldClose(this->m_windowHandle);
}
