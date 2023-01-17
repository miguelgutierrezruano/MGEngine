
#include <input_system.h>
#include <scene.h>
#include <entity.h>
#include <transform.h>

namespace MGEngine
{
	void input_system::add_input_event_mapping(Keyboard::Key_Code key, const std::string& _event_id)
	{
		i_task.add_input_event_mapping(key, _event_id);
	}

	std::shared_ptr<component> input_system::create_component(std::string& name)
	{
		auto r_comp = std::make_shared< component >();
		return r_comp;
	}

	input_system::input_system(scene * given_scene)
	{
		current_scene = given_scene;
		i_task.set_scene(given_scene);
	}
}