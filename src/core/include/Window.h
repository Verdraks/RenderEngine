#pragma once

#include "Action.hpp"
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
        virtual ~Window() = default;

        virtual void Update() const = 0;
        virtual bool IsValid() const = 0;

    public:
        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }
        Action<> &GetOnUpdateAction() { return m_onUpdate; }
        Action<int, int> &GetOnResizeAction() { return m_onResize; }

    protected:
        int m_width = 0;
        int m_height = 0;
        std::unique_ptr<Core::RendererContext> m_context = nullptr;
        Action<int, int> m_onResize;
        Action<> m_onUpdate;
    };

    inline Window::Window(const WindowProperties &properties, std::unique_ptr<Core::RendererContext> context)
        : m_width(properties.width), m_height(properties.height), m_context(std::move(context))
    {
    }
}