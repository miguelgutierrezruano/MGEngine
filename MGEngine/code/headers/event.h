/*
 * @file Event
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <string>
#include <component.h>

namespace MGEngine
{
	/// <summary>
	/// Event to be sended and recieved
	/// </summary>
	struct event
	{
		std::string id;

		inline bool operator==(const event& other)
		{
			return this->id == other.id;
		}
	};

	/// <summary>
	/// Event listener added to entities
	/// </summary>
	struct event_listener : component
	{
		/// <summary>
		/// Pure virtual method to handle events
		/// </summary>
		/// <param name="_event">Recieved event</param>
		/// <param name="delta_time">Time between frames</param>
		virtual void handle(const event & _event, float delta_time) = 0;
	};
}


