/*
 * @file System
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <iostream>
#include <memory>
#include <list>
#include <component.h>
#include <task.h>

namespace MGEngine
{
	/// <summary>
	/// Factory of components
	/// </summary>
	class system
	{
	public:

		/// <summary>
		/// Pure virtual method to create components
		/// </summary>
		/// <param name="name">Name of the entity of the added component</param>
		/// <returns>Shared pointer to constructed component</returns>
		virtual std::shared_ptr< component > create_component(std::string & name) = 0;

		/// <summary>
		/// Getter of system's task
		/// </summary>
		/// <returns>Pointer to system's task</returns>
		virtual task* get_task() { return nullptr; }
	};
}

