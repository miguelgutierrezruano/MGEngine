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

	public:

		scene()
		{
			// Add default systems
		}

		void load_default_scene()
		{
			// Create base scene
			auto first_entity = make_shared< entity >();

			component my_component;

			first_entity.get()->add_component("aaa", &my_component);
		}

		void run()
		{
			s_kernel.execute();
		}

	};
}
