#pragma once

#include <iostream>
#include <memory>
#include <list>
#include "component.h"
#include "task.h"

namespace MGEngine
{
	// Factory of components, tells scene to run tasks of the system
	class system
	{
	public:

		// Give variadic arguments to component if needed
		virtual std::shared_ptr< component > create_component() = 0;
		virtual task* get_task() { return nullptr; }
	};


	class dummy_system : public system
	{
		// Task of system
		class dummy_task : public task
		{
			// List of components managed by the system
			std::list < std::shared_ptr< component > > dummy_components;

			void lots_of_multiplications()
			{
				int x;

				for (int i = 0; i < 1000; i++)
				{
					x = 7 * i;
				}
			}

		public:

			dummy_task()
			{
				status = WAITING;
				priority = UPDATE_PRIORITY;

				consumable = false;
			}

			// Add component to tasks list
			void add_component(std::shared_ptr< component > given) override
			{
				dummy_components.push_back(given);
			}

		protected:

			// Execution of the task
			void run(float delta_time) override
			{
				int it = 0;

				for (auto d_c : dummy_components)
				{
					for (size_t i = 0; i < 10; i++)
					{
						lots_of_multiplications();
					}

					++it;

					std::cout << "Task finished! " << it << std::endl;
				}					
			}
		};

		dummy_task dummytask;

		// Empty component
		class dummy_component : public component
		{
			
		};

	public:

		std::shared_ptr< component > create_component() override
		{
			auto dummy_comp = std::make_shared< component >();
			dummytask.add_component(dummy_comp);
			return dummy_comp;
		}

		task* get_task() override
		{
			return &dummytask;
		}
	};
}

