#pragma once

namespace Renderer
{
    class Texture
    {
    public:
        Texture(const char *path) {}
        virtual ~Texture() = default;

        virtual void Bind() = 0;
        virtual void Unbind() = 0;

    public:
        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }

    protected:
        int m_width, m_height;
    };
}