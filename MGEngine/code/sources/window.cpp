#include "../headers/window.h"
#include <SDL.h>

namespace MGEngine
{
	Window::Window(const std::string& title, unsigned width, unsigned height, bool full_screen = true)
	{
		int window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;

		if (full_screen) window_flags |= SDL_WINDOW_FULLSCREEN;

		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)width, int(height), window_flags);
	}

	Window::~Window()
	{

	}

	void Window::set_fullscreen()
	{
	}

	void Window::set_windowed()
	{

	}

	void Window::swap_buffers()
	{

	}
}


		