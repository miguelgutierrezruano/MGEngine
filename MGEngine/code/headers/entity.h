#pragma once

#include <map>
#include <string>
#include <component.h>
#include <string>
#include <memory>

namespace MGEngine
{
	// TODO: Entity cpp
	class entity
	{
		std::string name;

		transform e_transform;

		// Map of each component of the entity and its id
		std::map< std::string, std::shared_ptr< component > > components;

	public:

		entity(std::string & _name) 
		{
			name = _name;
			e_transform.reset();
		}

		// Method to add components to entity
		void add_component(const std::string & id, std::shared_ptr< component > given_component)
		{
			components.emplace(id, given_component);
			//given_component.get()->set_owner(this);
		}

		// Prolly make this sharedptr
		component * get_component(const std::string & id)
		{
			auto map_it = components.find(id);

			if (map_it != components.end())
				return map_it->second.get();
			else
				return nullptr;
		}

		transform * get_transform()
		{
			return &e_transform;
		}
	};
}

