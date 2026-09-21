#pragma once

namespace Renderer
{
    class Texture final
    {
    public:
        Texture(const char *path);
        ~Texture();

        void Bind();
        void Unbind();

    public:
        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }

    protected:
        int m_width, m_height;
        unsigned int m_id;
        int m_nrChannels;
    };
}