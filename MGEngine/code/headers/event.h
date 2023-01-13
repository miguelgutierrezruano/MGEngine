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

namespace MGEngine
{
	/// <summary>
	/// 
	/// </summary>
	struct event
	{
		std::string id;
	};

	/// <summary>
	/// 
	/// </summary>
	struct event_listener
	{
		virtual void handle(const event & _event) = 0;
	};
}


