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
	m_windowHandle = glfwCreateWindow(width, height, title, nullptr, nullptr);

	m_width = width;
	m_height = height;

	if (m_windowHandle == nullptr)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}
}

Platform::Window::~Window()
{
	if (m_context != nullptr)
	{
		delete m_context;
		m_context = nullptr;
	}

	if (m_windowHandle != nullptr)
	{
		glfwDestroyWindow(m_windowHandle);
		m_windowHandle = nullptr;
	}
	glfwTerminate();
}

void Platform::Window::Update() const
{
	ProcessInputs();
}

void Platform::Window::LateUpdate() const
{
	if (m_context != nullptr)
	{
		m_context->SwapBuffers();
		m_context->Clear();
		m_context->Flush();
	}
	glfwPollEvents();
}

void Platform::Window::ProcessInputs() const
{
	if (glfwGetKey(m_windowHandle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_windowHandle, true);
	}
}
