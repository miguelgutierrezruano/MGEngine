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
	class controller : public component
	{
	public:
		// Method to execute every frame
		virtual void update(float delta_time) { }
	};
}
