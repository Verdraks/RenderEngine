#pragma once

namespace Core
{
    class RendererContext
    {
    public:
        virtual ~RendererContext() = default;

        virtual void Init(void *nativeHandle) = 0;
        virtual void Clear() = 0;
        virtual void SwapBuffers() = 0;
    };
}