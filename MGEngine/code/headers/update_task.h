/*
 * @file Update Task
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <queue>
#include <list>
#include <task.h>
#include <controller.h>
#include <event_dispatcher.h>

namespace MGEngine
{
	/// <summary>
	/// Task to update controllers and send events
	/// </summary>
	class update_task : public task
	{
		// Change for scene pointer
		event_dispatcher* ev_dispatcher;

		std::list < std::shared_ptr< controller > > controllers;

	public:

		/// <summary>
		/// Constructor of update task
		/// </summary>
		/// <param name="given_dispatcher">Dispatcher to handle events</param>
		update_task(event_dispatcher* given_dispatcher);

	protected:

		/// <summary>
		/// Execution of the task
		/// </summary>
		/// <param name="delta_time">Time between frames</param>
		virtual void run(float) override;

	public:

		void add_controller(std::shared_ptr< controller >);

	};
}
