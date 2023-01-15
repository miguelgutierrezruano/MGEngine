#pragma once

#include <iostream>
#include <memory>
#include <list>
#include <component.h>
#include <task.h>

namespace MGEngine
{
	// Factory of components, tells scene to run tasks of the system
	class system
	{
	public:

		// Give variadic arguments to component if needed
		virtual std::shared_ptr< component > create_component(std::string & name) = 0;
		virtual task* get_task() { return nullptr; }
	};
}

