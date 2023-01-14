
#include <render_task.h>
#include <Render_Node.hpp>
#include <scene.h>

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

	void render_task::add_component(std::shared_ptr<component> given)
	{
		renderer_components.push_back(given);
	}

	void render_task::run(float delta_time)
	{
		GLsizei width = GLsizei(current_scene->get_window()->get_width());
		GLsizei height = GLsizei(current_scene->get_window()->get_height());

		renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);

		auto cube = renderer->get("cube");

		cube->rotate_around_x(0.01f);
		cube->rotate_around_y(0.02f);
		cube->rotate_around_z(0.03f);

		current_scene->get_window()->clear();

		renderer->render();

		current_scene->get_window()->swap_buffers();
	}


}