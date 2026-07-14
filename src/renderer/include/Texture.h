#pragma once
#include <stb_image.h>

class Texture
{
public:
    Texture(const char *path);
    ~Texture();

    void Use();

private:
    int m_width, m_height, m_nrChannels;
    unsigned int m_texture;
};