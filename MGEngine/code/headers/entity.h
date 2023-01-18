#pragma once

#include <map>
#include <list>
#include <string>
#include <transform.h>
#include <string>
#include <memory>
#include <event.h>

namespace MGEngine
{
	class scene;
	class controller;

	class entity
	{
		scene* owner;

		std::string name;

		transform e_transform;

		// Map of each component of the entity and its id
		std::map< std::string, std::shared_ptr< component > > components;

	public:

		entity(std::string& _name, scene * _owner);

		// Method to add components to entity
		void add_component(const std::string& id, std::shared_ptr< component > given_component);

		// Could be in add component filtering by given_component type
		void add_controller(std::shared_ptr< controller > given_controller);

		void add_listener(std::string event_id, std::shared_ptr < event_listener >);

		// Prolly make this sharedptr
		component* get_component(const std::string& id);

		transform * get_transform()
		{
			return &e_transform;
		}
	};
}

