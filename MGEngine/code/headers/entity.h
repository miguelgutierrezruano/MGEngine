/*
 * @file Entity
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

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

		/// <summary>
		/// Constructor of entity
		/// </summary>
		/// <param name="_name">Name of the new entity</param>
		/// <param name="_owner">Scene owner of the entity</param>
		entity(std::string& _name, scene * _owner);

		/// <summary>
		/// Add component to entity
		/// </summary>
		/// <param name="id">ID of given component</param>
		/// <param name="given_component">Component to be added</param>
		void add_component(const std::string& id, std::shared_ptr< component > given_component);

		/// <summary>
		/// Add controller to entity. Gives scene information to update given controller
		/// </summary>
		/// <param name="given_controller">Controller to be added</param>
		void add_controller(std::shared_ptr< controller > given_controller);

		/// <summary>
		/// Add listener to entity. Makes scene send events to this entity
		/// </summary>
		/// <param name="event_id">ID of the event</param>
		/// <param name="listener">Listener to be added</param>
		void add_listener(std::string event_id, std::shared_ptr < event_listener > listener);

		/// <summary>
		/// Getter of component filtering by a given ID
		/// </summary>
		/// <returns>Pointer to component if found</returns>
		component* get_component(const std::string& id);

		/// <summary>
		/// Getter of entity transform
		/// </summary>
		/// <returns>Entity transform</returns>
		transform * get_transform()
		{
			return &e_transform;
		}
	};
}

