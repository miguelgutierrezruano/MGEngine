
#include <BallController.h>
#include <entity.h>

BallController::BallController(entity * paddle1, entity * paddle2)
{
	paddles.reserve(2);

	paddles.push_back(paddle1);
	paddles.push_back(paddle2);
}

void BallController::update(float delta_time)
{
	vec3 position = owner->get_transform()->get_position();

	// Vertical
	if (speed_y > 0)
	{
		// Surpassed top bound
		if (position.y > vertical_bound)
			speed_y = -speed_y;
	}
	else
	{
		// Surpassed bottom bound
		if (position.y < -vertical_bound)
			speed_y = -speed_y;
	}
	// Horizontal
	if (speed_x > 0)
	{
		// Surpassed top bound
		if (position.x > horizontal_bound)
			speed_x = -speed_x;
	}
	else
	{
		// Surpassed bottom bound
		if (position.x < -horizontal_bound)
			speed_x = -speed_x;
	}
	
	position.x += speed_x * delta_time;
	position.y += speed_y * delta_time;
	owner->get_transform()->set_position(position);
}

void BallController::paddle_collision()
{
	for (auto& paddle : paddles)
	{
		
	}
}
