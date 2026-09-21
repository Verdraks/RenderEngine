#include "WindowOpenglContext.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

using namespace Renderer;

void Renderer::WindowOpenglContext::Init(void *nativeHandle)
{
	m_windowHandle = static_cast<GLFWwindow *>(nativeHandle);
	// TODO:Call window hint before creating the window, not after. Init should be called after the window is created, not before. Move the window hint calls to the context constructor.
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwMakeContextCurrent(m_windowHandle);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::runtime_error("Failed to initialize GLAD");
	}

	glEnable(GL_DEPTH_TEST);
}

Renderer::WindowOpenglContext::WindowOpenglContext()
{
}

Renderer::WindowOpenglContext::~WindowOpenglContext()
{
	glfwMakeContextCurrent(nullptr);
	glfwSetFramebufferSizeCallback(m_windowHandle, nullptr);
}

void Renderer::WindowOpenglContext::UpdateContext(int width, int height)
{
	glViewport(0, 0, width, height);
}

void Renderer::WindowOpenglContext::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
}

void Renderer::WindowOpenglContext::SwapBuffers()
{
	glfwSwapBuffers(m_windowHandle);
}