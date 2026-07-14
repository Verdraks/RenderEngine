#pragma once

/// @brief Forward declaration of classes used in the RendererFactory interface.
class Shader;
/// @brief Forward declaration of classes used in the RendererFactory interface.
class VertexBuffer;
/// @brief Forward declaration of classes used in the RendererFactory interface.
class IndexBuffer;
/// @brief Forward declaration of classes used in the RendererFactory interface.
class VertexArrayBuffer;

namespace Core
{
    class RendererFactory
    {
    public:
        virtual ~RendererFactory() = default;

        virtual Shader *CreateShader(const char *vertexSource, const char *fragmentSource) = 0;
        virtual VertexBuffer *CreateVertexBuffer(const void *data, unsigned int size, unsigned int usage) = 0;
        virtual IndexBuffer *CreateIndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage) = 0;
        virtual VertexArrayBuffer *CreateVertexArrayBuffer() = 0;
    };
}