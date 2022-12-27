#pragma once

#include <map>
#include <string>
#include "component.h"

namespace MGEngine
{
	class entity
	{
		transform e_transform;

		// Each component of the entity and its id
		std::map< std::string, component* > components;

	public:

		void add_component(const std::string & id, component * given_component)
		{
			components.emplace(id, given_component);
			given_component->set_owner(this);
		}

		transform & get_transform()
		{
			return e_transform;
		}
	};
}

