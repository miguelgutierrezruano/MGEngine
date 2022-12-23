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
		std::list< std::shared_ptr< std::thread > > threads;
		// Queue of tasks to do
		std::priority_queue< task* > task_queue;

		// Mutex to limit threads access to queue
		std::mutex task_queue_mutex;

		bool running;

		float delta_time;

	public:

		thread_pool()
		{
			running = false;

			threads.resize(std::thread::hardware_concurrency());

			// Add usable threads to list
			for (unsigned int i = 0; i < std::thread::hardware_concurrency(); ++i)
			{
				// Add thread function to each thread
				threads.push_back(std::make_shared<std::thread>(thread_function, this));
			}

			running = true;
			delta_time = 0;
		}

		~thread_pool()
		{
			stop();
		}

		void add_task(task * _task)
		{
			// Lock mutex to use task queue
			std::lock_guard<std::mutex> lock(task_queue_mutex);

			task_queue.push(_task);
		}

		void stop()
		{
			if (running)
			{
				running = false;

				while (not task_queue.empty())
				{
					// Cancel task
					task_queue.top()->cancel();
					// Remove task
					task_queue.pop();
				}

				for (auto& thread : threads)
				{
					// Join each thread
					thread.get()->join();
				}
			}
		}

	private:

		// Function to execute on every thread
		static void thread_function(thread_pool* thread_pool)
		{
			while (thread_pool->running)
			{
				task* task;

				// Lock task queue
				{
					std::lock_guard<std::mutex> lock(thread_pool->task_queue_mutex);

					// Search for waiting task
					do
					{
						task = nullptr;

						if (not thread_pool->task_queue.empty())
						{
							// Save and pop task
							task = thread_pool->task_queue.top();
							thread_pool->task_queue.pop();
						}
					} while (task == nullptr && not thread_pool->task_queue.empty());
				}

				// Execute task
				if (task)
				{
					task->start(thread_pool->delta_time);
				}

				// Sleep if task queue is empty. Then add non consumable task to task queue again
			}
		}

	};
	
}


