#pragma once

#include <glm/gtc/matrix_transform.hpp>

namespace Renderer
{
    class Camera final
    {
    public:
        Camera();
        virtual ~Camera() = default;

        void SetPosition(const glm::vec3 &position);
        void SetRotation(const glm::vec4 &rotation);

        void SetFov(const float &fov);
        void SetNearPlane(const float &nearPlane);
        void SetFarPlane(const float &farPlane);
        void SetAspectRatio(const glm::vec2 &screenSize);

        inline const glm::vec3 &GetPosition() const { return m_position; }
        inline const glm::vec3 &GetRight() const { return m_right; }
        inline const glm::vec3 &GetUp() const { return m_up; }
        inline const glm::vec3 &GetForward() const { return m_forward; }
        inline const glm::mat4 &GetViewMatrix() const { return m_viewMatrix; }
        inline const glm::mat4 &GetProjectionMatrix() const { return m_projectionMatrix; }

    private:
        void UpdateViewMatrix();
        void UpdateProjectionMatrix();

    private:
        float m_fov;
        float m_aspectRatio;
        glm::vec2 m_clippingPlane;

        glm::vec3 m_position;

        glm::vec3 m_right;
        glm::vec3 m_up;
        glm::vec3 m_forward;

        glm::mat4 m_viewMatrix;
        glm::mat4 m_projectionMatrix;
    };
}