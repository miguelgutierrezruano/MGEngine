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

	public:

		void register_listener(const string & event_id, event_listener * listener)
		{
			listeners[event_id].push_back(listener);
		}

		void send(const event& _event)
		{
			auto it = listeners.find(_event.id);

			if (it != listeners.end())
			{
				for (auto listener : it->second)
				{
					listener->handle(_event);
				}
			}
		}
	};
}
