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
	/// Event manager
	/// </summary>
	class event_dispatcher
	{
		// Map with event IDs and list of listeners subscribed to the event
		map< string, list < event_listener* > > listeners;

		list < event > saved_events;

	public:

		/// <summary>
		/// Bind listener to an event
		/// </summary>
		/// <param name="event_id">Event to bind</param>
		/// <param name="listener">Listener to bind</param>
		void register_listener(const string & event_id, event_listener * listener)
		{
			listeners[event_id].push_back(listener);
		}

		/// <summary>
		/// Save event in a frame
		/// </summary>
		/// <param name="_event">Event to execute next frame</param>
		void save(const event& _event);

		/// <summary>
		/// Release saved events
		/// </summary>
		/// <param name="delta">Time between frames</param>
		void send_events(float delta);
	};
}
