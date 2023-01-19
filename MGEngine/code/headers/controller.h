/*
 * @file Controller
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <component.h>

namespace MGEngine
{
	/// <summary>
	/// Entity controller. Added as component
	/// </summary>
	class controller : public component
	{
	public:
		
		/// <summary>
		/// Method to be executed every frame
		/// </summary>
		/// <param name="delta_time">Time between frames</param>
		virtual void update(float delta_time) { }
	};
}
