#pragma once

#include "Texture.h"

namespace Platform
{
    class OpenglTexture final : public Renderer::Texture
    {
    public:
        OpenglTexture(const char *path);
        ~OpenglTexture();

    public:
        void Bind() override final;
        void Unbind() override final;

    private:
        unsigned int m_id;
        int m_nrChannels;
    };
}