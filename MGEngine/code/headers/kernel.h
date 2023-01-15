#pragma once

#include <chrono>
#include <list>
#include <vector>
#include <queue>
#include <thread>
#include <Window.hpp>
#include <task.h>
#include <event.h>

using namespace std::chrono;

namespace MGEngine
{
	using ptr_priority_queue = std::priority_queue< task*, std::vector< task* >, Task_Priority_Less >;

	class kernel
	{
		// Queue of tasks to do
		ptr_priority_queue task_queue;

		// List of non consumable task to add back to queue
		std::list< task* > non_consumable_tasks;

		std::queue< event* > event_queue;

		float fps;
		bool stop;

	public:

		// Set default values
		kernel();

		// Give task to thread pool
		void add_task(task* given_task);

		void stop_exec()
		{
			stop = true;
		}

		void set_fps(float new_fps)
		{
			fps = new_fps;
		}

		void execute();

	private:

		void clear_tasks();
	};
}
