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

		component * get_component(const std::string & id)
		{
			auto map_it = components.find(id);

			if (map_it != components.end())
				return map_it->second;
			else
				return nullptr;
		}

		transform & get_transform()
		{
			return e_transform;
		}
	};
}

