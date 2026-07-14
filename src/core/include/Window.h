#pragma once

#include "RendererContext.h"
#include <memory>

namespace Core
{
    struct WindowProperties
    {
        const int width = 0;
        const int height = 0;
        const char *title = nullptr;
    };

    class Window
    {
    public:
        Window(const WindowProperties &properties, std::unique_ptr<Core::RendererContext> context);
        virtual ~Window() = 0;

        virtual void Update() const = 0;
        virtual bool IsValid() const = 0;

    public:
        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }

    protected:
        int m_width = 0;
        int m_height = 0;
        std::unique_ptr<Core::RendererContext> m_context = nullptr;
    };
    inline Window::~Window() {}
    inline Window::Window(const WindowProperties &properties, std::unique_ptr<Core::RendererContext> context)
        : m_width(properties.width), m_height(properties.height), m_context(std::move(context))
    {
    }
}