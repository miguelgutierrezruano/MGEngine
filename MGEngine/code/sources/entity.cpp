
#include <entity.h>
#include <scene.h>
#include <controller.h>

namespace MGEngine
{
	entity::entity(std::string& _name, scene * _owner)
	{
		name  = _name;
		owner = _owner;
		e_transform.reset();
	}

	void entity::add_component(const std::string& id, std::shared_ptr<component> given_component)
	{
		components.emplace(id, given_component);
		given_component.get()->set_owner(this);
	}

	void entity::add_controller(std::shared_ptr<controller> given_controller)
	{
		// Restrict one controller per entity
		components.emplace("Controller", given_controller);
		given_controller.get()->set_owner(this);

		// Add controller to update task
		owner->add_controller(given_controller);
	}

	void entity::add_listener(std::string event_id, std::shared_ptr<event_listener> listener)
	{
		// Restrict one listener per entity
		components.emplace("EventListener", listener);
		listener.get()->set_owner(this);

		// Register listener in event dispatcher
		owner->get_event_dispatcher()->register_listener(event_id, listener.get());
	}

	component* entity::get_component(const std::string& id)
	{
		auto map_it = components.find(id);

		if (map_it != components.end())
			return map_it->second.get();
		else
			return nullptr;
	}
}