#include "OpenglTexture.h"

#include "glad/glad.h"
#include <iostream>
#include <stb_image.h>

Platform::OpenglTexture::OpenglTexture(const char *path) : Texture(path)
{
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char *data = stbi_load(path, &m_width, &m_height, &m_nrChannels, 0);

    if (data == nullptr)
    {
        std::cerr << "ERROR::TEXTURE::LOADING::FAILED" << '\n';
    }
    else
    {

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

        // TODO: Generate level Mipmap until texture less equals than 1px, not optimized.
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(data);
}

Platform::OpenglTexture::~OpenglTexture()
{
    glDeleteTextures(1, &m_id);
}

void Platform::OpenglTexture::Bind()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_id);
}

void Platform::OpenglTexture::Unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
