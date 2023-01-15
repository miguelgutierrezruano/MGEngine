
#include <entity.h>
#include <scene.h>

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

	void entity::add_listener(std::string event_id, std::shared_ptr<event_listener> listener)
	{
		listeners.push_back(listener);

		// Register listener in scene
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