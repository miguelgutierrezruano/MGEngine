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

		map< string, shared_ptr< entity* > > entities;
		//map< string, system* > systems; TODO: Add map of systems

		// Default systems
		input_system  * input_sys;
		render_system * render_sys;

	public:
		/// <summary>
		/// Constructor of scene
		/// </summary>
		/// <param name="given_window"> Window where to render the scene </param>
		scene(Window& given_window);

		void load_default_scene();

		/// Run one frame of the scene
		void run()
		{
			s_kernel.execute();
		}

		/// Stop scene execution
		void stop()
		{
			s_kernel.stop_exec();
		}

		Window * get_window()
		{
			return window;
		}

		event_dispatcher* get_event_dispatcher()
		{
			return &ev_dispatcher;
		}
	};
}
