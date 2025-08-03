#include "window.h"
#include "glfw/windowglfw.h"

#include <stdexcept>


namespace Platform {
    Window* Window::Create(const int width,const int height, const char* title) {
        if (width <= 0 || height <= 0 || title == nullptr) {
            throw std::invalid_argument("Invalid window parameters");
		}
        return new WindowGlfw(width, height, title);
    }
}