/*
 * @file Kernel
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

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

	/// <summary>
	/// Engine kernel
	/// </summary>
	class kernel
	{
		// Queue of tasks to do
		ptr_priority_queue task_queue;

		// List of non consumable task to add back to queue
		std::list< task* > non_consumable_tasks;

		float fps;
		bool stop;

	public:

		/// <summary>
		/// Constructor of kernel
		/// </summary>
		kernel();

		/// <summary>
		/// Give task for kernel to execute
		/// </summary>
		/// <param name="given_task">Task to be executed</param>
		void add_task(task* given_task);

		/// <summary>
		/// Stops engine execution
		/// </summary>
		void stop_exec()
		{
			stop = true;
		}

		/// <summary>
		/// Set target frames per second
		/// </summary>
		/// <param name="new_fps">New frame rate</param>
		void set_fps(float new_fps)
		{
			fps = new_fps;
		}

		/// <summary>
		/// Initiate engine loop
		/// </summary>
		void execute();

	private:

		void clear_tasks();
	};
}
