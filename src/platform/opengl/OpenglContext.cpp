#include "glad/glad.h"
#include "OpenglContext.h"
#include <stdexcept>

Platform::OpenglContext::OpenglContext(GLFWwindow *windowHandle) : m_windowHandle(windowHandle)
{
	glfwMakeContextCurrent(m_windowHandle);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::runtime_error("Failed to initialize GLAD");
	}

	glfwSetFramebufferSizeCallback(m_windowHandle, UpdateContext);
}

void Platform::OpenglContext::SwapBuffer() const
{
	glfwSwapBuffers(m_windowHandle);
}

void Platform::OpenglContext::UpdateContext(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Platform::OpenglContext::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
}