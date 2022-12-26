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
			INPUT_PRIORITY = 300,
			UPDATE_PRIORITY = 200,
			RENDER_PRIORITY = 100
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
			priority = UPDATE_PRIORITY;

			consumable = false;
		}

		task(Priority given_priority, bool is_consumable)
		{
			status = WAITING;
			priority = given_priority;

			consumable = is_consumable;
		}

		Status get_status() { return status; }

		bool is_consumable() const { return consumable; }

		// Handle tasks
		void start(float delta)
		{
			// Add events to avoid checking status on loop
			status = RUNNING;

			if (status != CANCELLED)
				run(delta);

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
		virtual void run(float ) = 0;
	};
}
