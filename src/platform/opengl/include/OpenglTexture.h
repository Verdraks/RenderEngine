#pragma once

#include "Texture.h"

namespace Platform
{
    class OpenglTexture : public Renderer::Texture
    {
    public:
        OpenglTexture(const char *path);
        ~OpenglTexture();

    public:
        void Bind() override;
        void Unbind() override;

    private:
        unsigned int m_id;
        int m_nrChannels;
    };
}