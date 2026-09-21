#include "Window.h"
#include <iostream>
#include <stdexcept>

using namespace Core;

Window::Window(const Core::WindowProperties &properties)
{
	if (!glfwInit())
	{
		throw std::runtime_error("Failed to initialize GLFW");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	m_windowHandle = glfwCreateWindow(properties.width, properties.height, properties.title, nullptr, nullptr);

	glfwSetWindowUserPointer(m_windowHandle, this);

	constexpr auto framebufferSizeCallback = [](GLFWwindow *window, int width, int height)
	{
		Core::Window *self = static_cast<Core::Window *>(glfwGetWindowUserPointer(window));
		self->m_onResize(width, height);
	};

	glfwSetFramebufferSizeCallback(m_windowHandle, framebufferSizeCallback);

	if (m_windowHandle == nullptr)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}

	m_context = std::make_unique<Renderer::WindowOpenglContext>();

	m_context->Init(m_windowHandle);
	m_onResize += std::bind(&Renderer::WindowOpenglContext::UpdateContext, m_context.get(), std::placeholders::_1, std::placeholders::_2);
}

Window::~Window()
{
	m_context.release();

	glfwDestroyWindow(m_windowHandle);
	m_windowHandle = nullptr;

	glfwTerminate();
}

void Window::Update()
{
	if (glfwGetKey(m_windowHandle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_windowHandle, true);
	}

	m_context->SwapBuffers();
	m_context->Clear();

	glfwPollEvents();
	m_onUpdate();
}