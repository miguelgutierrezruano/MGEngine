
// This is free code released into the public domain.
// Drafted by Ángel in January 2019.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

#include <SDL.h>
#include <cstdlib>

namespace MGEngine
{

    extern void finalize ();

    // Method to initialize SDL subsystems
    bool initialize (int subsystem)
    {
        // At exit of main call finalize

        static bool finalize_is_not_set = true;

        if (finalize_is_not_set)
        {
            finalize_is_not_set = false;

            std::atexit (finalize);
        }

        // Initialize system if it wasn't already

        if (!SDL_WasInit (subsystem))
        {
             return SDL_Init (subsystem) == 0;
        }

        return true;
    }

}
