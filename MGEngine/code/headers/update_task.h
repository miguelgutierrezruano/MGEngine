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
	class update_task : public task
	{
		// Change for scene pointer
		event_dispatcher* ev_dispatcher;

		std::list < std::shared_ptr< controller > > controllers;

	public:

		update_task(event_dispatcher*);

	protected:
		virtual void run(float) override;

	public:

		void add_controller(std::shared_ptr< controller >);

	};
}
