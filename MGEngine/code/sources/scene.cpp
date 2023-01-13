
#include <scene.h>

MGEngine::scene::scene(Window& given_window)
{
	window = &given_window;

	// Create systems. TODO: Use memorypools
	input_sys  = new input_system(this);
	dum_system = new dummy_system();

	s_kernel.set_window(given_window);

	// Add default systems tasks
	//s_kernel.add_task(dum_system->get_task());
	s_kernel.add_task(input_sys->get_task());

	window->enable_vsync();
	s_kernel.set_fps(144);
}

void MGEngine::scene::load_default_scene()
{
	// Create base scene
	auto first_entity = make_shared< entity >();

	first_entity.get()->add_component("dummy", dum_system->create_component().get());

	auto second = make_shared< entity >();

	second.get()->add_component("dummy", dum_system->create_component().get());
}
