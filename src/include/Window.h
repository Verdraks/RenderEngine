#pragma once

#include "Action.hpp"
#include "WindowOpenglContext.h"
#include <GLFW/glfw3.h>
#include <memory>

namespace Core
{

    struct WindowProperties
    {
        const int width = 0;
        const int height = 0;
        const char *title = nullptr;
    };

    class Window final
    {
    public:
        Window(const WindowProperties &properties);
        ~Window();

        void Update();
        bool IsValid() const { return m_windowHandle != nullptr && !glfwWindowShouldClose(this->m_windowHandle); }

    public:
        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }
        Action<> &GetOnUpdateAction() { return m_onUpdate; }
        Action<int, int> &GetOnResizeAction() { return m_onResize; }

        GLFWwindow *GetNativeHandle() const { return m_windowHandle; }

    private:
        int m_width = 0;
        int m_height = 0;
        Action<int, int> m_onResize;
        Action<> m_onUpdate;

        std::unique_ptr<Renderer::WindowOpenglContext> m_context;
        GLFWwindow *m_windowHandle = nullptr;
    };
}