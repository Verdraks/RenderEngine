#pragma once

#include <glm/glm.hpp>

namespace Renderer
{
    class Camera
    {
    public:
        Camera();
        virtual ~Camera() = default;

        void SetPosition(const glm::vec3 &position);
        void SetOrientation(const glm::vec3 &right, const glm::vec3 &up, const glm::vec3 &forward);

        inline const glm::vec3 &GetPosition() const { return m_position; }
        inline const glm::vec3 &GetRight() const { return m_right; }
        inline const glm::vec3 &GetUp() const { return m_up; }
        inline const glm::vec3 &GetForward() const { return m_forward; }
        inline const glm::mat4 &GetViewMatrix() const { return m_viewMatrix; }
        inline const glm::mat4 &GetProjectionMatrix() const { return m_projectionMatrix; }

    private:
        glm::vec3 m_position;
        glm::vec3 m_right;
        glm::vec3 m_up;
        glm::vec3 m_forward;

        glm::mat4 m_viewMatrix;
        glm::mat4 m_projectionMatrix;
    };
}