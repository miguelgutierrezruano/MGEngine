
#include <scene.h>

MGEngine::scene::scene(Window& given_window)
{
	// Create systems. TODO: Use memorypools
	render_sys = new render_system(given_window);
	dum_system = new dummy_system();

	// Add default systems tasks
	s_kernel.add_task(dum_system->get_task());
	s_kernel.add_task(render_sys->get_task());

	//s_kernel.set_fps(1);
}

void MGEngine::scene::load_default_scene()
{
	// Create base scene
	auto first_entity = make_shared< entity >();

	first_entity.get()->add_component("dummy", dum_system->create_component().get());

	auto second = make_shared< entity >();

	second.get()->add_component("dummy", dum_system->create_component().get());
}
