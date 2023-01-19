
#include <MovementListener.h>

void MovementListener::handle(const event& _event, float delta_time)
{
	if (_event.id == "MoveUp")
	{
		vec3 position = owner->get_transform()->get_position();

		if(position.y < vertical_limit)
			position.y += speed * delta_time;

		owner->get_transform()->set_position(position);
	}
	else if (_event.id == "MoveDown")
	{
		vec3 position = owner->get_transform()->get_position();

		if (position.y > -vertical_limit)
			position.y -= speed * delta_time;

		owner->get_transform()->set_position(position);
	}
}