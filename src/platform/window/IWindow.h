#pragma once

namespace Platform
{
    class IWindow
    {
    public:
        virtual void Update() const = 0;
        virtual void LateUpdate() const = 0;
        virtual bool IsValid() const = 0;
        virtual ~IWindow() = default;
    };
}
