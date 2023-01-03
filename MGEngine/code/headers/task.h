#pragma once

#include "component.h"

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

		Status get_status() { return status; }
		Priority get_priority() const { return priority; }

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

		// Virtual method to add components to tasks sytem
		virtual void add_component(std::shared_ptr< component >) = 0;

	protected:

		// Pure virtual method
		virtual void run(float ) = 0;
	};

	class Task_Priority_Less
	{
	public:
		// Sobrecarga del operador de llamada a función:
		bool operator () (const task* a, const task* b)
		{
			return a->get_priority() < b->get_priority();
		}
	};
}
