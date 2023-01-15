#pragma once

#include <task.h>
#include <Keyboard.hpp>
#include <string>
#include <list>

namespace MGEngine
{
	class scene;

	class input_task : public task
	{
		// Only for keyboard now
		struct Input_Event_Mapping
		{
			// Keyboard event
			Keyboard::Event keyboard_event;

			// ID of engine event
			std::string event_id;
		};

		std::list < Input_Event_Mapping > input_event_mappings;

		scene * current_scene;

	public:

		input_task();

		void set_scene(scene * given)
		{
			current_scene = given;
		}

		void add_input_event_mapping(Keyboard::Key_Code, std::string&);

	protected:

		void run(float delta_time) override;

	private:

		void check_window_events();
	};
}
