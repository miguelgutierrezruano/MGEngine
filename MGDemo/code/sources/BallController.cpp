
#include <BallController.h>
#include <entity.h>

BallController::BallController()
{
	paddles.reserve(2);

	// Add paddles
}

void BallController::update(float delta_time)
{
	vec3 last = owner->get_transform()->get_position();

	// Vertical
	if (speed_y > 0)
	{
		// Surpassed top bound
		if (last.y > vertical_bound)
			speed_y = -speed_y;
	}
	else
	{
		// Surpassed bottom bound
		if (last.y < -vertical_bound)
			speed_y = -speed_y;
	}
	// Horizontal
	if (speed_x > 0)
	{
		// Surpassed top bound
		if (last.x > horizontal_bound)
			speed_x = -speed_x;
	}
	else
	{
		// Surpassed bottom bound
		if (last.x < -horizontal_bound)
			speed_x = -speed_x;
	}
	
	last.x += speed_x * delta_time;
	last.y += speed_y * delta_time;
	owner->get_transform()->set_position(last);
}
