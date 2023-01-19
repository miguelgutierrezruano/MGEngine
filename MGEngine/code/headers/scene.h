/*
 * @file Scene
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <map>
#include <string>
#include <kernel.h>
#include <entity.h>
#include <Window.hpp>
#include <input_system.h>
#include <update_task.h>
#include <render_system.h>
#include <event_dispatcher.h>

using namespace std;

namespace MGEngine
{
	/// <summary>
	/// ECS container of entities and systems
	/// </summary>
	class scene
	{
		kernel s_kernel;

		Window * window;

		event_dispatcher ev_dispatcher;

		map< string, shared_ptr< entity > > entities;


		input_system  * input_sys;
		render_system * render_sys;
		update_task * update_t;

	public:
		/// <summary>
		/// Constructor of scene
		/// </summary>
		/// <param name="given_window">Window where to render the scene</param>
		scene(Window& given_window);

		/// <summary>
		/// Load scene from XML file
		/// </summary>
		/// <param name="xml_path">Path to XML file</param>
		void load_scene(const char* xml_path);

		/// <summary>
		/// Add event to throw when a given key is pressed
		/// </summary>
		/// <param name="key">Key to throw event</param>
		/// <param name="_event_id">Event ID to be throwed</param>
		void add_input_event_mapping(Keyboard::Key_Code key, const std::string& _event_id);

		/// <summary>
		/// Add controller to be updated every frame
		/// </summary>
		/// <param name="given_controller">Controller to be added</param>
		void add_controller(std::shared_ptr< controller > given_controller);

		/// <summary>
		/// Execution loop of the scene
		/// </summary>
		void run()
		{
			s_kernel.execute();
		}

		/// <summary>
		/// Stop scene execution
		/// </summary>
		void stop()
		{
			s_kernel.stop_exec();
		}

		/// <summary>
		/// Getter of window
		/// </summary>
		/// <returns>Window where scene is being rendered</returns>
		Window * get_window()
		{
			return window;
		}

		/// <summary>
		/// Getter of event dispatcher
		/// </summary>
		/// <returns>Pointer to scene's event dispatcher</returns>
		event_dispatcher* get_event_dispatcher()
		{
			return &ev_dispatcher;
		}

		/// <summary>
		/// Get entities of scene by name
		/// </summary>
		/// <param name="_name">Name of the wanted entity</param>
		/// <returns>Pointer to entity if found</returns>
		entity* get_entity(std::string& _name);
	};
}
