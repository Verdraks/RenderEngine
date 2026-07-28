#include "OpenglRendererFactory.h"

#include "OpenglBuffer.h"
#include "OpenglMesh.h"
#include "OpenglShader.h"
#include "OpenglTexture.h"

using namespace Platform;

OpenglRendererFactory::OpenglRendererFactory()
{
}

OpenglRendererFactory::~OpenglRendererFactory()
{
}

Renderer::Mesh *OpenglRendererFactory::CreateMesh(const float vertices[], const unsigned int verticesCount)
{
    return new OpenglMesh(vertices, verticesCount);
}

Renderer::Mesh *OpenglRendererFactory::CreateMesh(const float vertices[], const unsigned int verticesCount, const unsigned int indices[], const unsigned int indicesCount)
{
    return new OpenglMesh(vertices, verticesCount, indices, indicesCount);
}

Renderer::Shader *OpenglRendererFactory::CreateShader(const char *vertexSource, const char *fragmentSource)
{
    return new OpenglShader(vertexSource, fragmentSource);
}

Renderer::VertexBuffer *OpenglRendererFactory::CreateVertexBuffer(const float *data, unsigned int size, unsigned int usage)
{
    return new OpenglVertexBuffer(data, size, usage);
}

Renderer::IndexBuffer *OpenglRendererFactory::CreateIndexBuffer(const unsigned int *data, unsigned int count, unsigned int usage)
{
    return new OpenglIndexBuffer(data, count, usage);
}

Renderer::VertexArrayBuffer *OpenglRendererFactory::CreateVertexArrayBuffer()
{
    return new OpenglVertexArrayBuffer();
}

Renderer::Texture *OpenglRendererFactory::CreateTexture(const char *filePath)
{
    return new OpenglTexture(filePath);
}
