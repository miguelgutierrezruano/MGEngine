#pragma once

#include <task.h>

namespace MGEngine
{
	class scene;

	class input_task : public task
	{
		scene * current_scene;

		// List of components

	public:

		input_task();

		void set_scene(scene * given)
		{
			current_scene = given;
		}

	protected:

		void run(float delta_time) override;

	private:

		void check_window_events();
	};
}
