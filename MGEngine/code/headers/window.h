/*
 * @file Window
 * @author Miguel Gutierrez
 * 
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <string>
#include <Keyboard.hpp>
#include <internal/declarations.hpp>

namespace MGEngine
{
    /// Class to display a window
	class Window
	{

	public:

        /// Struct of window events and it's data
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
        /** Constructor of window
          * @param title Name of the window
          * @param width Desired width of window
          * @param height Desired height of window
          */
		Window(const std::string& title, unsigned width, unsigned height, bool full_screen = false);
		~Window();

	public:

        unsigned get_width() const;
        unsigned get_height() const;

        /// Extract event from windows queue
        /// @param event Event that could happen in window
        /// @return false if there is no event registered
        /// @return true  if there is an event to process
        bool poll(Event& event) const;

        void enable_vsync();
        void disable_vsync();

        /// Clear shown buffer
        void clear() const;

        /// Swap drawn buffer for shown buffer
		void swap_buffers() const;
	};
}
