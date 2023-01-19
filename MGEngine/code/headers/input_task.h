/*
 * @file Input task
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <task.h>
#include <Keyboard.hpp>
#include <string>
#include <list>

namespace MGEngine
{
	class scene;

	/// <summary>
	/// Task to proccess user's input in a window
	/// </summary>
	class input_task : public task
	{
		/// <summary>
		/// Struct that pairs a key event to an ID
		/// </summary>
		struct Input_Event_Mapping
		{
			// Keyboard event
			Keyboard::Event keyboard_event;

			// ID of engine event
			std::string event_id;
		};

		std::list < Input_Event_Mapping > input_event_mappings;

		scene * current_scene;

	public:

		/// <summary>
		/// Constructor of input task
		/// </summary>
		input_task();

		/// <summary>
		/// Setter of the scene
		/// </summary>
		/// <param name="given">Scene where to detect events</param>
		void set_scene(scene * given)
		{
			current_scene = given;
		}

		/// <summary>
		/// Add an input event mapping to list
		/// </summary>
		/// <param name="key">Key that invokes event on pressed</param>
		/// <param name="_event_id">ID of event to be invoked</param>
		void add_input_event_mapping(Keyboard::Key_Code key, const std::string& _event_id);

	protected:

		/// <summary>
		/// Execution of the task
		/// </summary>
		/// <param name="delta_time">Time between frames</param>
		void run(float delta_time) override;
	};
}
