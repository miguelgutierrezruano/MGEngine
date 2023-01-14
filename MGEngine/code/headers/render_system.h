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

namespace MGEngine
{
	class scene;

	// Mesh component
	class mesh_component : public component
	{
		// OpenGLT attributes
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
