
// This is free code released into the public domain.
// Drafted by Ángel in January 2019.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

#pragma once

#include <string>
#include <declarations.hpp>
#include <Keyboard.hpp>

namespace MGEngine
{

    class Window
    {
    public:

        // Window events
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

        SDL_Window  * window;
        SDL_GLContext gl_context;

    public:

        Window(const std::string & title, int width, int height, bool fullscreen = false);
       ~Window();

    public:

        // Returns window width
        unsigned get_width () const;

        // Returns window height
        unsigned get_height () const;

        // Get an event from window
        bool poll (Event & event) const;

        void enable_vsync ();

        void disable_vsync ();

        // Clear buffer
        void clear () const;

        // Swap shown and hide buffers
        void swap_buffers () const;

    };

}
