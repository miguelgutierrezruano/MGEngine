
#include <scene.h>

MGEngine::scene::scene(Window& given_window)
{
	window = &given_window;

	// Create systems. TODO: Use memorypools
	input_sys  = new input_system (this);
	render_sys = new render_system(this);

	// Add default systems tasks
	s_kernel.add_task(input_sys->get_task());
	s_kernel.add_task(render_sys->get_task());

	window->enable_vsync();
	s_kernel.set_fps(144);
}

void MGEngine::scene::load_default_scene()
{
	// Create base scene
	std::string first_name = "First";
	auto first_entity = make_shared< entity >(first_name);

	auto render_comp = render_sys->create_component(first_entity.get());
	first_entity.get()->add_component("mesh", render_comp);
}
