
#include <render_task.h>
#include <Render_Node.hpp>
#include <scene.h>
#include <component.h>

using namespace glt;

namespace MGEngine
{
	render_task::render_task()
	{
		current_scene = nullptr;
		renderer.reset(new Render_Node);

		status = WAITING;
		priority = RENDER_PRIORITY;

		consumable = false;
	}

	void render_task::add_component(std::shared_ptr<mesh_component> given)
	{
		renderer_components.push_back(given);

		// Add mesh component to renderer so it shows
		renderer->add(given.get()->get_id(), given.get()->get_mesh());
	}

	void render_task::run(float delta_time)
	{
		GLsizei width = GLsizei(current_scene->get_window()->get_width());
		GLsizei height = GLsizei(current_scene->get_window()->get_height());

		renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);

		for (auto render_component : renderer_components)
		{
			entity * owner = render_component.get()->get_owner();

			if (owner != nullptr)
			{
				// Apply transform
				auto node = renderer.get()->get(render_component.get()->get_id());

				transform * owner_transform = owner->get_transform();
				node->translate(owner_transform->get_position());
				node->rotate_around_x(owner_transform->get_rotation().x);
				node->rotate_around_y(owner_transform->get_rotation().y);
				node->rotate_around_z(owner_transform->get_rotation().z);
				node->scale(owner->get_transform()->get_scale().x,
							owner->get_transform()->get_scale().y,
							owner->get_transform()->get_scale().z);
			}
		}

		current_scene->get_window()->clear();

		renderer->render();

		current_scene->get_window()->swap_buffers();
	}


}