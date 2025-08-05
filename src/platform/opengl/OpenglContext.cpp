#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "OpenglContext.h"
#include "WindowsWindow.h"

void Platform::OpenglContext::InitContext(const WindowsWindow* windowsWindow)
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return;
	glfwSetFramebufferSizeCallback(windowsWindow->GetNativeHandle(),UpdateContext);
}

void Platform::OpenglContext::UpdateContext(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
