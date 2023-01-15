
#include <kernel.h>

namespace MGEngine
{
	kernel::kernel()
	{
		fps = 60;
		stop = true;
	}

	void kernel::add_task(task* given_task)
	{
		if (not given_task->is_consumable())
			non_consumable_tasks.push_back(given_task);

		task_queue.push(given_task);
	}

	void kernel::execute()
	{
		stop = false;

		auto chrono = high_resolution_clock();
		float frame_duration = 1.f / fps;
		float delta_time = frame_duration;

		do
		{
			// Get time where frame started
			high_resolution_clock::time_point start = chrono.now();

			// Execute all tasks
			while (not task_queue.empty())
			{
				task_queue.top()->start(delta_time);
				task_queue.pop();
			}

			// Calculate and apply delay if needed
			duration<float> delay = duration<float>(frame_duration) - duration<float>(chrono.now() - start);
			if (delay.count() > 0.f)
				std::this_thread::sleep_for(delay);

			// Set delta time for next frame
			delta_time = duration<float>(chrono.now() - start).count();

			// Add non consumable tasks back to queue
			for (task* n_c_task : non_consumable_tasks)
			{
				n_c_task->restart();
				task_queue.push(n_c_task);
			}
		} while (not stop);

		clear_tasks();
	}

	void kernel::clear_tasks()
	{
		while (not task_queue.empty())
		{
			// Cancel task
			task_queue.top()->cancel();
			// Remove task
			task_queue.pop();
		}
	}
}
