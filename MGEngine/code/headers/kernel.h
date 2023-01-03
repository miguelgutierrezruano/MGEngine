#pragma once

#include <chrono>
#include <list>
#include <queue>
#include <thread>
#include "task.h"

using namespace std::chrono;

namespace MGEngine
{

	class kernel
	{
		// TODO: Thread pool to manage tasks multithread

		// Queue of tasks to do
		std::priority_queue< task* > task_queue;

		// List of non consumable task to add back to queue
		std::list< task* > non_consumable_tasks;

		float fps;

		high_resolution_clock chrono;
		float frame_duration;
		float delta_time;

	public:

		// Set default values
		kernel()
		{
			fps = 60;
			frame_duration = 1.f / fps;
			delta_time = frame_duration;
		}

		// Give task to thread pool
		void add_task(task* given_task)
		{
			if (not given_task->is_consumable())
				non_consumable_tasks.push_back(given_task);

			task_queue.push(given_task);
		}

		void set_fps(float new_fps)
		{
			fps = new_fps;
			frame_duration = 1.f / fps;
		}

		void execute_frame()
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
				task_queue.push(n_c_task);
			}
		}
	};
}
