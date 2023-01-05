/*
 * @file Input system
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <system.h>
#include <task.h>
#include <window.h>

namespace MGEngine
{
	class scene;

	class input_system : public system
	{
		
		class input_task : public task
		{
			Window* window;
			scene * current_scene;

		public:

			input_task();

			void set_window(Window* given) { window = given; }
			void set_scene (scene * given) { current_scene = given; }

		protected:

			void run(float delta_time) override;

		private:

			void check_window_events();
		};

		input_task i_task;

		class input_component : public component
		{
			// Not neccesary
		};

	public:

		std::shared_ptr< component > create_component() override
		{
			auto r_comp = std::make_shared< component >();
			return r_comp;
		}

		input_system(Window*, scene*);

		task* get_task()
		{
			return &i_task;
		}
	};
}

