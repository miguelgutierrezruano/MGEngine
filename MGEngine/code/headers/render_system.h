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

	/// <summary>
	/// OpenGL Toolkit component to be rendered
	/// </summary>
	class mesh_component : public component
	{
		// ID for renderer
		std::string id;
		std::shared_ptr< Model > mesh;

	public:

		/// <summary>
		/// Constructor of mesh component
		/// </summary>
		/// <param name="_id">Name for node renderer</param>
		/// <param name="_mesh">Entity mesh</param>
		mesh_component(std::string & _id, Mesh * _mesh)
		{
			id = _id;

			mesh.reset(new Model);
			mesh->add(std::shared_ptr< Drawable >(_mesh), Material::default_material());
		}

		/// <summary>
		/// Getter of mesh
		/// </summary>
		/// <returns>Shared ptr to model</returns>
		std::shared_ptr< Model > get_mesh()
		{
			return mesh;
		}

		/// <summary>
		/// Getter of id
		/// </summary>
		/// <returns>String of id</returns>
		const std::string & get_id()
		{
			return id; 
		}
	};

	/// <summary>
	/// System to render entities in window
	/// </summary>
	class render_system : public system
	{
		render_task r_task;

	public:

		/// <summary>
		/// Constructor of render system
		/// </summary>
		/// <param name="given_scene">Scene to be rendered</param>
		render_system(scene * given_scene);

		/// <summary>
		/// Create render component
		/// </summary>
		std::shared_ptr< component > create_component(std::string& name) override;

		/// <summary>
		/// Getter of task
		/// </summary>
		/// <returns>Pointer to task</returns>
		task* get_task() override
		{
			return &r_task;
		}
	};
}
