#include "../headers/Window.h"
#include <SDL.h>

namespace Darius
{
	Window::Window(const std::string title, unsigned width, unsigned height, bool fullScreen)
	{
		int window_flag = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;

		if (fullScreen) window_flag != SDL_WINDOW_FULLSCREEN;

		SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)width, (int)height, window_flag);
	}
	Window::~Window()
	{
	}
	void Window::show()
	{
	}
	void Window::hide()
	{
	}
	void Window::setFullScreen()
	{
	}
	void Window::setWindowed()
	{
	}
	void Window::swapBuffers()
	{
	}
}