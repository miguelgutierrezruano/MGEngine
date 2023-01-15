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
#include <event.h>

namespace MGEngine
{
	class scene;

	class input_system : public system
	{
		scene* current_scene;

		input_task i_task;

		class input_listener : public event_listener
		{
			component* owner;

			virtual void handle(const event& _event) override;

		public:
			
			void set_owner(component* _owner) { owner = _owner; }
		};

		class input_component : public component
		{
		public:
			input_listener listener;

			input_component()
			{
				listener.set_owner(this);
			}
		};

	public:

		void add_input_event_mapping(Keyboard::Key_Code, std::string&);

		std::shared_ptr< component > create_component() override;

		input_system(scene*);

		task* get_task()
		{
			return &i_task;
		}
	};
}

