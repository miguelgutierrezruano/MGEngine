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

	class render_task : public task
	{
		std::list< std::shared_ptr < mesh_component > > renderer_components;

		scene * current_scene;

		std::unique_ptr < glt::Render_Node > renderer;

	public:

		render_task();

		void add_component(std::shared_ptr < mesh_component > given);

		void set_scene(scene* given_scene) { current_scene = given_scene; }

		glt::Render_Node* get_renderer()   { return renderer.get(); }

	protected:

		void run(float delta_time) override;

	};
}
