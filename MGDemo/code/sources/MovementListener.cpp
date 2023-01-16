
#include <MovementListener.h>

void MovementListener::handle(const event& _event, float delta_time)
{
	if (_event.id == "MoveUp")
	{
		vec3 last = owner->get_transform()->get_position();

		if(last.y < vertical_limit)
			last.y += speed * delta_time;

		owner->get_transform()->set_position(last);
	}
	else if (_event.id == "MoveDown")
	{
		vec3 last = owner->get_transform()->get_position();

		if (last.y > -vertical_limit)
			last.y -= speed * delta_time;

		owner->get_transform()->set_position(last);
	}
}