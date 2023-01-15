
#include <input_system.h>
#include <scene.h>
#include <entity.h>
#include <transform.h>

namespace MGEngine
{
	void input_system::add_input_event_mapping(Keyboard::Key_Code key, std::string& _event_id)
	{
		i_task.add_input_event_mapping(key, _event_id);
	}

	// Give xml node and read event
	std::shared_ptr<component> input_system::create_component()
	{
		auto r_comp = std::make_shared< input_component >();

		current_scene->get_event_dispatcher()->register_listener(
			"MoveLeft", &r_comp.get()->listener);

		return r_comp;
	}

	input_system::input_system(scene * given_scene)
	{
		current_scene = given_scene;
		i_task.set_scene(given_scene);
	}

	void input_system::input_listener::handle(const event& _event)
	{
		if (_event.id == "MoveLeft")
		{
			vec3 last = owner->get_owner()->get_transform()->get_position();

			last.x--;

			owner->get_owner()->get_transform()->set_position(last);
		}
	}
}