
#include <update_task.h>

namespace MGEngine
{
	update_task::update_task(event_dispatcher* given_dispatcher)
	{
		ev_dispatcher = given_dispatcher;

		status = WAITING;
		priority = UPDATE_PRIORITY;

		consumable = false;
	}

	void update_task::run(float delta_time)
	{
		// Send events saved in last frame
		ev_dispatcher->send_events(delta_time);

		// Entity updates
		for (auto controller : controllers)
		{
			controller.get()->update(delta_time);
		}
	}

	void update_task::add_controller(std::shared_ptr< controller > given_controller)
	{
		controllers.push_back(given_controller);
	}
}