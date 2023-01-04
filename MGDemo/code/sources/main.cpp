
#include <window.h>
#include <iostream>
#include <scene.h>

using namespace MGEngine;

int main()
{
	// Create window
	Window window("MGDemo", 1280, 720);
	window.disable_vsync();

	// Create scene
	scene first_scene(window);
	first_scene.load_default_scene();

	bool exit = false;

	// TODO: Reorder detecting window events in input task
	while (!exit)
	{
		Window::Event event;

		while (window.poll(event))
		{
			switch (event.type)
			{
				// Close window if close button is pressed
				case Window::Event::CLOSE:
				{
					exit = true;
					break;
				}

				// Close window if esc key is pressed
				case Window::Event::KEY_PRESSED:
				{
					if (event.data.keyboard.key_code == Keyboard::KEY_ESCAPE)
					{
						exit = true;
					}

					break;
				}
			}
		}

		// Engine main loop
		first_scene.run_frame();
	}

	return 0;
}