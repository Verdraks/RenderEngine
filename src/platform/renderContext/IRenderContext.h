#pragma once

namespace Platform
{
    class IRenderContext
    {
    public:
        virtual void Clear() = 0;
        virtual void Flush() = 0;
        virtual void SwapBuffers() = 0;
        virtual ~IRenderContext() = default;
    };
}