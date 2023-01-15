
#include <event_dispatcher.h>

namespace MGEngine
{
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

			saved_events.pop();
		}
	}
}