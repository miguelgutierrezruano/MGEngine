
#pragma once

#include <system.h>
#include <task.h>
#include <window.h>
#include <Render_Node.hpp>

namespace MGEngine
{
	// System to render the scene in a given window
	class render_system : public system
	{

		// Task given to kernel
		class render_task : public task
		{
			// List of components managed by the system
			std::list < std::shared_ptr< component > > renderer_components;

			Window * task_window;

		public:

			std::unique_ptr< glt::Render_Node > renderer;

		public:

			render_task();
			~render_task();

			// Add component to tasks list
			void add_component(std::shared_ptr< component > given) override
			{
				renderer_components.push_back(given);
			}

			void set_window(Window& given_window) { task_window = &given_window; }

			//void set_renderer(glt::Render_Node * given) { renderer = given; }
			//glt::Render_Node * get_renderer() { return renderer; }

		protected:

			// Execution of the task
			void run(float delta_time) override;
		};

		// Instance of render task
		render_task r_task;

	public:

		render_system(Window& given_window);

	private:

		class render_component : public component
		{
			// OpenGL Toolkit atributes
		};

	public:

		std::shared_ptr< component > create_component() override
		{
			auto r_comp = std::make_shared< component >();
			r_task.add_component(r_comp);
			return r_comp;
		}

		task* get_task() override
		{
			return &r_task;
		}
	};
}

