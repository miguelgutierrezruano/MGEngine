/*
 * @file Update Task
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <task.h>
#include <queue>
#include <event_dispatcher.h>

namespace MGEngine
{
	class update_task : public task
	{
		event_dispatcher* ev_dispatcher;

	public:

		update_task(event_dispatcher*);

	};
}
