#pragma once

#include <task.h>

namespace MGEngine
{
	class scene;

	class input_task : public task
	{
		scene* current_scene;

	public:

		input_task();

		void set_scene(scene* given);

	protected:

		void run(float delta_time) override;

	private:

		void check_window_events();
	};
}
