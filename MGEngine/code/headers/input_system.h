/*
 * @file Input system
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <system.h>
#include <input_task.h>
#include <event.h>

namespace MGEngine
{
	class scene;

	/// <summary>
	/// System to detect and proccess user's input
	/// </summary>
	class input_system : public system
	{
		scene* current_scene;

		input_task i_task;

	public:

		/// <summary>
		/// Bind a key to an event
		/// </summary>
		/// <param name="key">Keyboard key</param>
		/// <param name="_event_id">ID of event</param>
		void add_input_event_mapping(Keyboard::Key_Code key, const std::string& _event_id);
		
		/// <summary>
		/// Create input component
		/// </summary>
		/// <param name="name">Name of owner entity</param>
		/// <returns>New input component</returns>
		std::shared_ptr< component > create_component(std::string& name) override;

		/// <summary>
		/// Initialize input system
		/// </summary>
		/// <param name="given_scene">Scene to get input events</param>
		input_system(scene* given_scene);

		/// <summary>
		/// Getter of task
		/// </summary>
		/// <returns>Pointer to task</returns>
		task* get_task()
		{
			return &i_task;
		}
	};
}

