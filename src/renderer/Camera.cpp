#include "Camera.h"

Renderer::Camera::Camera()
    : m_position(0.0f, 0.0f, 0.0f),
      m_right(1.0f, 0.0f, 0.0f),
      m_up(0.0f, 1.0f, 0.0f),
      m_forward(0.0f, 0.0f, -1.0f),
      m_viewMatrix(1.0f),
      m_projectionMatrix(1.0f)
{
    // Initialize the view matrix
    m_viewMatrix = glm::lookAt(m_position, m_position + m_forward, m_up);

    // Initialize the projection matrix (perspective projection)
    float fov = glm::radians(45.0f);     // Field of view in radians
    float aspectRatio = 800.0f / 600.0f; // Aspect ratio (width / height)
    float nearPlane = 0.1f;              // Near clipping plane
    float farPlane = 100.0f;             // Far clipping plane
    m_projectionMatrix = glm::perspective(fov, aspectRatio, nearPlane, farPlane);
}