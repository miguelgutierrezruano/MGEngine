
#include <scene.h>

namespace MGEngine
{
	scene::scene(Window& given_window)
	{
		window = &given_window;

		// Create systems. TODO: Use memorypools
		input_sys = new input_system(this);
		render_sys = new render_system(this);

		update_t = new update_task(&ev_dispatcher);

		// Add default systems tasks
		s_kernel.add_task(input_sys->get_task());
		s_kernel.add_task(render_sys->get_task());
		s_kernel.add_task(update_t);

		window->enable_vsync();
		s_kernel.set_fps(144);
	}

	void scene::load_default_scene()
	{
		// Create first entity
		std::string first_name = "First";
		auto first_entity = make_shared< entity >(first_name, this);

		// Add render component
		auto render_comp = render_sys->create_component(first_name);
		first_entity.get()->add_component("RenderComp", render_comp);

		// Save entity
		entities[first_name] = first_entity;

		first_entity.get()->get_transform()->set_position(vec3(30.f, 0, 0));
		first_entity.get()->get_transform()->set_rotation(vec3(0, 0, 0));
		first_entity.get()->get_transform()->set_scale(vec3(1, 7, 1));
	}

	void scene::add_input_event_mapping(Keyboard::Key_Code key, std::string& _event_id)
	{
		input_sys->add_input_event_mapping(key, _event_id);
	}

	entity* MGEngine::scene::get_entity(std::string& _name)
	{
		auto map_it = entities.find(_name);

		if (map_it != entities.end())
			return map_it->second.get();
		else
			return nullptr;
	}
}
