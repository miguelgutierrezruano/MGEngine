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

		list < event > saved_events;

	public:

		void register_listener(const string & event_id, event_listener * listener)
		{
			listeners[event_id].push_back(listener);
		}

		void save(const event& _event);

		void send_events(float delta);
	};
}
