#pragma once

#include <iostream>
#include <memory>
#include "component.h"

namespace MGEngine
{
	// Factory of components, tells scene to run tasks of the system
	class system
	{
	public:

		virtual component* create_component() = 0;
		virtual task* get_task() { return nullptr; }
	};

	class dummy_system : public system
	{
	public:

		// Task of system should search for all components of the scene and procceed
		class dummy_task : public task
		{
			void lots_of_multiplications()
			{
				int x;

				for (int i = 0; i < 1000; i++)
				{
					x = 7 * i;
				}
			}

		protected:

			void run(float delta_time) override
			{
				for (size_t i = 0; i < 10; i++)
				{
					lots_of_multiplications();
				}

				std::cout << "Task finished!" << std::endl;
			}
		};

	public:

		class dummy_component : public component
		{
			
		};

		component* create_component() override
		{
			dummy_component * dummy_comp = new dummy_component;
			return dummy_comp;
		}

		dummy_task dummytask;

		task* get_task() override
		{
			return &dummytask;
		}
	};
}

