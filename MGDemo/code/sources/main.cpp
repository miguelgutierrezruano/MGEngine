
#include <window.h>
#include <iostream>
#include "scene.h"
#include "task.h"

using namespace MGEngine;

class test_class
{
private:
	int a;
	int b;

public:
	test_class() { a = 2; b = 200; }
	test_class(int _a, int _b) { a = _a; b = _b; }
};

int main()
{
	// Create window
	Window window("MGDemo", 800, 600);
	window.enable_vsync();

	// Create scene
	scene first_scene;
	first_scene.load_default_scene();

	bool exit = false;

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