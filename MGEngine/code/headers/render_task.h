/*
 * @file Render task
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <task.h>
#include <list>
#include <declarations.hpp>

namespace MGEngine
{
	class mesh_component;
	class scene;

	/// <summary>
	/// Task that render objects in window
	/// </summary>
	class render_task : public task
	{
		std::list< std::shared_ptr < mesh_component > > renderer_components;

		scene * current_scene;

		std::unique_ptr < glt::Render_Node > renderer;

	public:

		/// <summary>
		/// Constructor of render task
		/// </summary>
		render_task();

		/// <summary>
		/// Add render component to renderer list
		/// </summary>
		/// <param name="given">Mesh component to be rendered</param>
		void add_component(std::shared_ptr < mesh_component > given);

		/// <summary>
		/// Setter of scene
		/// </summary>
		/// <param name="given_scene">Scene to be rendered</param>
		void set_scene(scene* given_scene) { current_scene = given_scene; }

		/// <summary>
		/// Getter of renderer
		/// </summary>
		/// <returns>OpenGL Toolkit renderer</returns>
		glt::Render_Node* get_renderer()   { return renderer.get(); }

	protected:

		/// <summary>
		/// Execution of the task
		/// </summary>
		/// <param name="delta_time">Time between frames</param>
		void run(float delta_time) override;

	};
}
