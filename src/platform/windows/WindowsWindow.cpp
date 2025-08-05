#include "WindowsWindow.h"
#include <stdexcept>

Platform::WindowsWindow::WindowsWindow(const int width, const int height, const char* title)
{
	if (!glfwInit())
	{
		throw std::runtime_error("Failed to initialize GLFW");
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	this->m_windowHandle = glfwCreateWindow(width, height, title, nullptr, nullptr);


	this->m_width = width;
	this->m_height = height;

	if (!this->m_windowHandle)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}

	glfwMakeContextCurrent(this->m_windowHandle);
}

Platform::WindowsWindow::~WindowsWindow()
{
	if (this->m_windowHandle != nullptr)
	{
		glfwDestroyWindow(this->m_windowHandle);
		this->m_windowHandle = nullptr;
	}
	glfwTerminate();
}

void Platform::WindowsWindow::OnUpdate() const
{
	glfwPollEvents();
	glfwSwapBuffers(this->m_windowHandle);
}

GLFWwindow* Platform::WindowsWindow::GetNativeHandle() const
{
	return this->m_windowHandle;
}

int Platform::WindowsWindow::GetWidth() const
{
	return this->m_width;
}

int Platform::WindowsWindow::GetHeight() const
{
	return this->m_height;
}
