
#include <MovementListener.h>

void MovementListener::handle(const event& _event, float delta_time)
{
	if (_event.id == "MoveLeft")
	{
		vec3 last = owner->get_transform()->get_position();

		last.x -= speed * delta_time;

		owner->get_transform()->set_position(last);
	}
	else if (_event.id == "MoveRight")
	{
		vec3 last = owner->get_transform()->get_position();

		last.x += speed * delta_time;

		owner->get_transform()->set_position(last);
	}
}
