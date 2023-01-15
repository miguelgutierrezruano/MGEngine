
#include <event_dispatcher.h>
#include <algorithm>

namespace MGEngine
{
	void event_dispatcher::save(const event& _event)
	{
		// Filter list
		bool found = (std::find(saved_events.begin(), saved_events.end(), _event) != saved_events.end());

		if(not found)
			saved_events.push_back(_event);
	}

	void event_dispatcher::send_events(float delta)
	{
		while (not saved_events.empty())
		{
			// Get single event
			auto _event = saved_events.front();

			// Get listeners
			auto it = listeners.find(_event.id);

			if (it != listeners.end())
			{
				// Send event to every listener
				for (auto listener : it->second)
				{
					listener->handle(_event, delta);
				}
			}

			saved_events.pop_front();
		}
	}
}