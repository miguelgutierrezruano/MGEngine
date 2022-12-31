#pragma once

#include <map>
#include <string>
#include "kernel.h"
#include "entity.h"
#include "system.h"

using namespace std;

namespace MGEngine
{
	class scene
	{
		kernel s_kernel;

		// Default systems

		map< string, shared_ptr< entity* > > entities;
		map< string, system* > systems;

		dummy_system dum_system;

	public:

		scene()
		{
			// Add default systems
			s_kernel.add_task(dum_system.get_task());

			s_kernel.set_fps(1);
		}

		void load_default_scene()
		{
			// Create base scene
			auto first_entity = make_shared< entity >();

			first_entity.get()->add_component("dummy", dum_system.create_component().get());

			auto second = make_shared< entity >();

			second.get()->add_component("dummy", dum_system.create_component().get());
		}

		void run()
		{
			s_kernel.execute();
		}

	};
}
