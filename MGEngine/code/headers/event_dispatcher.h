/*
 * @file Event Dispatcher
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <string>
#include <map>
#include <list>
#include <queue>
#include <event.h>

using namespace std;

namespace MGEngine
{
	/// <summary>
	/// 
	/// </summary>
	class event_dispatcher
	{
		map< string, list < event_listener* > > listeners;

		queue < event > saved_events;

	public:

		void register_listener(const string & event_id, event_listener * listener)
		{
			listeners[event_id].push_back(listener);
		}

		void save(const event& _event)
		{
			// Maybe list would be better to filter contained events
			saved_events.push(_event);
		}

		void send_events(float delta);
	};
}
