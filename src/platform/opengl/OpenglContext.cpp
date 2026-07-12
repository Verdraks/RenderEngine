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

	glEnable(GL_DEPTH_TEST);
}

void Platform::OpenglContext::SwapBuffer() const
{
	glfwSwapBuffers(m_windowHandle);
}

void Platform::OpenglContext::UpdateContext(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Platform::OpenglContext::Clean()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
}

void Platform::OpenglContext::Clear()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glUseProgram(0);
	glTexBuffer(GL_TEXTURE_2D, 0, 0);
}
