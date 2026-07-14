#include "OpenglContext.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

Platform::OpenglContext::OpenglContext(GLFWwindow *windowHandle)
	: m_windowHandle(windowHandle)
{
}

void Platform::OpenglContext::Init()
{
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwMakeContextCurrent(m_windowHandle);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::runtime_error("Failed to initialize GLAD");
	}

	glfwSetFramebufferSizeCallback(m_windowHandle, UpdateContext);

	glEnable(GL_DEPTH_TEST);
}

Platform::OpenglContext::~OpenglContext()
{
	glfwMakeContextCurrent(nullptr);
	glfwSetFramebufferSizeCallback(m_windowHandle, nullptr);
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

void Platform::OpenglContext::SwapBuffers()
{
	glfwSwapBuffers(m_windowHandle);
}