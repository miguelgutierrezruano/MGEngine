
#include <input_system.h>
#include <scene.h>

namespace MGEngine
{
	input_system::input_system(Window* given_window, scene * given_scene)
	{
		i_task.set_window(given_window);
		i_task.set_scene(given_scene);
	}

	input_system::input_task::input_task()
	{
		window = nullptr;
		current_scene = nullptr;

		status = WAITING;
		priority = INPUT_PRIORITY;

		consumable = false;
	}

	void input_system::input_task::run(float delta_time)
	{
		check_window_events();
	}

	void input_system::input_task::check_window_events()
	{
		Window::Event event;

		while (window->poll(event))
		{
			switch (event.type)
			{
				// Close window if close button is pressed
				case Window::Event::CLOSE:
				{
					current_scene->stop();
					break;
				}

				// Close window if esc key is pressed
				case Window::Event::KEY_PRESSED:
				{
					if (event.data.keyboard.key_code == Keyboard::KEY_ESCAPE)
					{
						current_scene->stop();
					}

					break;
				}
			}
		}
	}


}