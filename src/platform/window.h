#pragma once

namespace Platform
{
	class Window 
	{
		public :
			virtual ~Window() = default;
			virtual void OnUpdate() = 0;
			virtual void* GetNativeHandle() const = 0;
			static Window* Create(const int width, const int height, const char* title);
	};
}
