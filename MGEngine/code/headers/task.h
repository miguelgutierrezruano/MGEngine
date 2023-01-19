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
#include <memory>

namespace MGEngine
{
	/// <summary>
	/// Base class of kernel tasks
	/// </summary>
	class task
	{

	public:

		/// <summary>
		/// Possible states of task
		/// </summary>
		enum Status
		{
			WAITING,
			RUNNING,
			CANCELLED,
			FINISHED
		};

		/// <summary>
		/// Set execution order
		/// </summary>
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

		/// <summary>
		/// Default constructor of task
		/// </summary>
		task()
		{
			status   = WAITING;
			priority = UPDATE_PRIORITY;

			consumable = false;
		}

		Status get_status() { return status; }

		Priority get_priority() const { return priority; }

		bool is_consumable() const { return consumable; }

		/// <summary>
		/// Handle task
		/// </summary>
		/// <param name="delta">Time between frames</param>
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

		void cancel()  { status = CANCELLED; }
		void restart() { status =   WAITING; }

	protected:

		/// <summary>
		/// Pure virtual method to invoke when task is being executed
		/// </summary>
		/// <param name=""></param>
		virtual void run(float ) = 0;
	};

	/// <summary>
	/// Class to order pointer to task class by its priority
	/// </summary>
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
