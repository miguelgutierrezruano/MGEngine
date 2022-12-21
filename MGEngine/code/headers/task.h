#pragma once

namespace MGEngine
{
	class task
	{

	public:

		// Status of the task
		enum Status
		{
			WAITING,
			RUNNING,
			CANCELLED,
			FINISHED
		};

		enum Priority
		{
			LOW_PRIORITY = -100,
			DEFAULT_PRIORITY = 0,
			HIGH_PRIORITY = 100
		};

	protected:

		Status status;
		
		Priority priority;

		// True if task should be executed every frame
		bool consumable;

	public:

		task()
		{
			status   = WAITING;
			priority = DEFAULT_PRIORITY;

			consumable = false;
		}

		task(Priority given_priority, bool is_consumable)
		{
			status = WAITING;
			priority = given_priority;

			consumable = is_consumable;
		}

		Status get_status() const { return status; }

		// Handle tasks
		void start()
		{
			// Add events to avoid checking status on loop
			status = RUNNING;

			if (status != CANCELLED)
				run();

			status = FINISHED;
		}

		// Overload of < operator
		bool operator < (const task& other)
		{
			return this->priority < other.priority;
		}

		void cancel() { status = CANCELLED; }

	protected:

		// Pure virtual method
		virtual void run() = 0;
	};

	//TODO: task_group
}
