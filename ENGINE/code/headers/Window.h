#pragma once

#include <string>

namespace Darius
{

	class Window
	{

	public:
		Window(const std::string title, unsigned width, unsigned height, bool fullScreen);

		~Window();

		void show();
		void hide();

		void setFullScreen();
		void setWindowed();

		void swapBuffers();
	};
}