#pragma once

#include <string>
#include <Keyboard.hpp>
#include <internal/declarations.hpp>

namespace MGEngine
{
	class Window
	{

	public:

        // Struct of window events and types
        struct Event
        {
            enum Type
            {
                CLOSE,
                KEY_PRESSED,
                KEY_RELEASED
            }
            type;

            union Data
            {
                struct { int key_code; } keyboard;

                struct
                {
                    float x, y;
                    int   buttons;
                }
                mouse;
            }
            data;
        };

    private:

		SDL_Window* window;
        SDL_GLContext gl_context;

	public:

		Window(const std::string& title, unsigned width, unsigned height, bool full_screen = false);
		~Window();

	public:

        // Get width and height
        unsigned get_width() const;
        unsigned get_height() const;

        // Extract event from windows queue
        bool poll(Event& event) const;

        // VSync methods
        void enable_vsync();
        void disable_vsync();

        void clear() const;

		void swap_buffers() const;
	};
}
