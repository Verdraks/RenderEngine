#include "GlfwWindow.h"
#include <iostream>
#include <stdexcept>

Platform::GlfwWindow::GlfwWindow(const Core::WindowProperties &properties, std::unique_ptr<Core::RendererContext> context) : Core::Window(properties, std::move(context))
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
		auto *self = static_cast<Platform::GlfwWindow *>(glfwGetWindowUserPointer(window));
		self->m_onResize(width, height);
	};

	glfwSetFramebufferSizeCallback(m_windowHandle, framebufferSizeCallback);

	if (m_windowHandle == nullptr)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}

	if (m_context != nullptr)
	{
		m_context->Init(m_windowHandle);
		m_onResize += std::bind(&Core::RendererContext::UpdateContext, m_context.get(), std::placeholders::_1, std::placeholders::_2);
	}
	else
	{
		std::cerr << "Renderer context is null" << std::endl;
	}
}

Platform::GlfwWindow::~GlfwWindow()
{
	if (m_context != nullptr)
	{
		m_context.release();
	}

	if (m_windowHandle != nullptr)
	{
		glfwDestroyWindow(m_windowHandle);
		m_windowHandle = nullptr;
	}
	glfwTerminate();
}

void Platform::GlfwWindow::Update() const
{
	if (glfwGetKey(m_windowHandle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_windowHandle, true);
	}

	if (m_context != nullptr)
	{
		m_context->SwapBuffers();
		m_context->Clear();
	}

	glfwPollEvents();
	m_onUpdate();
}