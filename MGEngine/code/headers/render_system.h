/*
 * @file Render system
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <system.h>
#include <render_task.h>
#include <memory>
#include <Model.hpp>
#include <Mesh.hpp>

using namespace glt;

namespace MGEngine
{
	class scene;

	// Mesh component
	class mesh_component : public component
	{
		// ID for renderer
		std::string id;
		std::shared_ptr< Model > mesh;

	public:

		// Create mesh component with given mesh
		mesh_component(std::string & _id, Mesh * _mesh)
		{
			id = _id;

			mesh.reset(new Model);
			mesh->add(std::shared_ptr< Drawable >(_mesh), Material::default_material());
		}

		std::shared_ptr< Model > get_mesh()
		{
			return mesh;
		}

		const std::string & get_id()
		{
			return id; 
		}
	};

	class render_system : public system
	{
		render_task r_task;

	public:

		render_system(scene * given_scene);

		std::shared_ptr< component > create_component() override;

		task* get_task() override
		{
			return &r_task;
		}
	};
}
