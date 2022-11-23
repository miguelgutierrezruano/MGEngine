#pragma once

#include <string>

struct SDL_Window;

namespace MGEngine
{
	class Window
	{

		SDL_Window* window;

	public:

		Window(const std::string& title, unsigned width, unsigned height, bool full_screen);

		~Window();

	public:

		void set_fullscreen();
		void set_windowed();

		void swap_buffers();
	};
}
