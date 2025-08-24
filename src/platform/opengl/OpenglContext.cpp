#include "glad/glad.h"
#include "OpenglContext.h"

Platform::OpenglContext::OpenglContext(GLFWwindow *windowHandle) : m_windowHandle(windowHandle)
{
	glfwMakeContextCurrent(m_windowHandle);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
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