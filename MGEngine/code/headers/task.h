/*
 * @file Task
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <component.h>

namespace MGEngine
{
	/// Class to execute tasks on kernel
	class task
	{

	public:

		/// Status of task
		enum Status
		{
			WAITING,
			RUNNING,
			CANCELLED,
			FINISHED
		};

		/// Priority to establish execution order
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

		/// Handle task 
		/// @delta expected time between current frame and next one
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

		/// Virtual method to add components to task's sytem
		virtual void add_component(std::shared_ptr< component >) { }

	protected:

		/// Method to invoke when task is being executed
		virtual void run(float ) = 0;
	};

	class Task_Priority_Less
	{
	public:
		/// Overload operator that compares to pointers of type task
		bool operator () (const task* a, const task* b)
		{
			return a->get_priority() < b->get_priority();
		}
	};
}
