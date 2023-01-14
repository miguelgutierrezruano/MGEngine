/*
 * @file Input system
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <system.h>
#include <input_task.h>

namespace MGEngine
{
	class scene;

	class input_system : public system
	{

		input_task i_task;

		class input_component : public component
		{
			// Add listener
		};

	public:

		std::shared_ptr< component > create_component(entity* _entity) override
		{
			auto r_comp = std::make_shared< component >();
			return r_comp;
		}

		input_system(scene*);

		task* get_task()
		{
			return &i_task;
		}
	};
}

