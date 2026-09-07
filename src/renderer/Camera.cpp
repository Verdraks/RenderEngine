#include "Camera.h"

Renderer::Camera::Camera()
    : m_position(0.0f, 0.0f, 0.0f),
      m_right(1.0f, 0.0f, 0.0f),
      m_up(0.0f, 1.0f, 0.0f),
      m_forward(0.0f, 0.0f, -1.0f),
      m_viewMatrix(1.0f),
      m_projectionMatrix(1.0f),
      m_fov(glm::radians(45.0f)),
      m_aspectRatio(800.0f / 600.0f),
      m_clippingPlane(0.1, 100)
{
    UpdateViewMatrix();
    UpdateProjectionMatrix();
}

void Renderer::Camera::SetPosition(const glm::vec3 &position)
{
    m_position = position;
    UpdateViewMatrix();
}

void Renderer::Camera::SetRotation(const glm::vec4 &rotation)
{
    UpdateViewMatrix();
}

void Renderer::Camera::SetFov(const float &fov)
{
    m_fov = fov;
    UpdateProjectionMatrix();
}

void Renderer::Camera::SetNearPlane(const float &nearPlane)
{
    m_clippingPlane.x = nearPlane;
    UpdateProjectionMatrix();
}

void Renderer::Camera::SetFarPlane(const float &farPlane)
{
    m_clippingPlane.y = farPlane;
    UpdateProjectionMatrix();
}

void Renderer::Camera::SetAspectRatio(const glm::vec2 &screenSize)
{
    m_aspectRatio = screenSize.x / screenSize.y;
    UpdateProjectionMatrix();
}

void Renderer::Camera::UpdateViewMatrix()
{
    m_viewMatrix = glm::lookAt(m_position, m_position + m_forward, m_up);
}

void Renderer::Camera::UpdateProjectionMatrix()
{
    m_projectionMatrix = glm::perspective(m_fov, m_aspectRatio, m_clippingPlane.x, m_clippingPlane.y);
}