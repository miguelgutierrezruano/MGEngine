#pragma once

#include <chrono>
#include "thread_pool.h"

namespace MGEngine
{
	class kernel
	{
		// Thread pool to manage tasks multithread
		thread_pool k_thread_pool;

		float fps;

	public:

		// Set default values
		kernel() { fps = 60; }

		// Give task to thread pool
		void add_task(task * given_task)
		{
			k_thread_pool.add_task(given_task);
		}

		void stop() { k_thread_pool.stop(); }

		void set_fps(float new_fps) { fps = new_fps; }

		void execute()
		{
			//auto chrono = std::chrono::high_resolution_clock();


		}


	};
}
