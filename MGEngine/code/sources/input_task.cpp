
#include <input_task.h>
#include <scene.h>

namespace MGEngine
{
	input_task::input_task()
	{
		current_scene = nullptr;

		status = WAITING;
		priority = INPUT_PRIORITY;

		consumable = false;
	}

	void input_task::set_scene(scene* given)
	{
		current_scene = given;
	}

	void input_task::run(float delta_time)
	{
		check_window_events();
	}

	void input_task::check_window_events()
	{
		Window::Event event;

		while (current_scene->get_window()->poll(event))
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