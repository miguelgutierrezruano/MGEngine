
#include <input_task.h>
#include <scene.h>
#include <Keyboard.hpp>

namespace MGEngine
{
	input_task::input_task()
	{
		current_scene = nullptr;

		status = WAITING;
		priority = INPUT_PRIORITY;

		consumable = false;
	}	

	void input_task::add_input_event_mapping(Keyboard::Key_Code key, std::string& _event_id)
	{
		// TODO: Add parameter to key released
		Keyboard::Key_Pressed_Event event;
		event.key_code = key;

		Input_Event_Mapping new_input_event_mapping;
		new_input_event_mapping.keyboard_event = event;
		new_input_event_mapping.event_id = _event_id;

		input_event_mappings.push_back(new_input_event_mapping);
	}

	void input_task::run(float delta_time)
	{
		check_window_events();
	}

	void input_task::check_window_events()
	{
		Window::Event w_event;

		while (current_scene->get_window()->poll(w_event))
		{
			switch (w_event.type)
			{
				// Close window if close button is pressed
				case Window::Event::CLOSE:
				{
					current_scene->stop();
					break;
				}

				// Switch on key pressed
				case w_event.KEY_PRESSED:
				{
					// Foreach mapping search for key pressed
					for (auto& mapping : input_event_mappings)
					{
						if (mapping.keyboard_event.key_code == w_event.data.keyboard.key_code)
						{
							// Call event by mapping id
							event map_event;
							map_event.id = mapping.event_id;

							current_scene->get_event_dispatcher()->save(map_event);
						}
					}

					if (w_event.data.keyboard.key_code == Keyboard::KEY_ESCAPE)
					{
						current_scene->stop();
					}

					break;
				}
			}
		}
	}
}