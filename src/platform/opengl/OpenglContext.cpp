#include "glad/glad.h"
#include "OpenglContext.h"

Platform::OpenglContext::OpenglContext(GLFWwindow* windowHandle) : m_windowHandle(windowHandle)
{
	this->Init();
}

void Platform::OpenglContext::Init() const
{
	glfwMakeContextCurrent(m_windowHandle);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

void Platform::OpenglContext::SwapBuffer() const
{
	glfwSwapBuffers(m_windowHandle);
}


