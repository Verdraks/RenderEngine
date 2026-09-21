#pragma once

struct GLFWwindow;

namespace Renderer
{
	class WindowOpenglContext final
	{
	public:
		WindowOpenglContext();
		~WindowOpenglContext();

	public:
		void Init(void *nativeHandle);
		void Clear();
		void SwapBuffers();
		void UpdateContext(int width, int height);

	private:
		GLFWwindow *m_windowHandle = nullptr;
	};
}
