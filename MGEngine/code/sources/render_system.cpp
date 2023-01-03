
#include "render_system.h"
#include <iostream>

namespace MGEngine
{
	render_system::render_task::render_task()
	{
		task_window = nullptr;

		status = WAITING;
		priority = RENDER_PRIORITY;

		consumable = false;
	}

	void render_system::render_task::run(float delta_time)
	{
		task_window->clear();

		// Render

		task_window->swap_buffers();

		std::cout << "Render completed!" << std::endl;
	}


}