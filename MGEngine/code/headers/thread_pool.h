#pragma once

#include <list>
#include <thread>
#include <queue>
#include <mutex>
#include "task.h"

namespace MGEngine
{
	class thread_pool
	{
		// List of user threads
		std::list< std::shared_ptr<std::thread> > threads;

		// Queue of tasks to do
		std::priority_queue< task* > task_queue;

		// Mutex to limit threads access to queue
		std::mutex task_queue_mutex;

		bool running;

	public:

		thread_pool()
		{
			running = false;

			// Add usable threads to list
			for (unsigned int i = 0; i < std::thread::hardware_concurrency(); ++i)
			{
				// TODO: Add thread function
				threads.push_back(std::make_shared<std::thread>());
			}

			running = true;
		}

	};
}


