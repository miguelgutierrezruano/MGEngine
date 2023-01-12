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
#include <system.h> // Remove when dummy system makes no sense
#include <render_system.h>
#include <input_system.h>

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

		map< string, shared_ptr< entity* > > entities;
		map< string, system* > systems;

		// Default systems
		render_system * render_sys;
		input_system  * input_sys;
		dummy_system  * dum_system;
		

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
	};
}
