
#include <cstdlib>
#include <entity.h>
#include <PaddleController.h>
#include <BallController.h>

BallController::BallController(entity * paddle1, entity * paddle2)
{
	state = Idle;

	paddles.reserve(2);
	paddles.push_back(paddle1);
	paddles.push_back(paddle2);
}

void BallController::update(float delta_time)
{
	if (state == Moving)
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
			// Reset ball
			if (position.x > horizontal_bound)
			{
				reset_ball();
				return;
			}
		}
		else
		{
			// Reset ball
			if (position.x < -horizontal_bound)
			{
				reset_ball();
				return;
			}
		}

		paddle_collision();

		position.x += speed_x * delta_time;
		position.y += speed_y * delta_time;
		owner->get_transform()->set_position(position);
	}
}

void BallController::paddle_collision()
{
	vec3 position = owner->get_transform()->get_position();

	for (auto& paddle : paddles)
	{
		// Cant take pointer ?
		vec3 paddle_position = paddle->get_transform()->get_position();

		float x_diff = position.x - paddle_position.x;

		// Filter by x
		if (abs(x_diff) < 1.f)
		{
			// Ball is in paddle range
			if (abs(paddle_position.y - position.y) < 8.f)
			{
				if (x_diff > 0)
					speed_x =  abs(speed_x);
				else
					speed_x = -abs(speed_x);
			}
		}
	}
}

void BallController::reset_ball()
{
	state = Idle;
	owner->get_transform()->set_position(vec3(0, 0, 0));

	// Reset paddles
	for (auto& paddle : paddles)
	{
		PaddleController * paddle_controller = dynamic_cast<PaddleController*>(paddle->get_component("Controller"));

		if (paddle_controller)
			paddle->get_transform()->set_position(vec3(30.f, 0, 0));
		else
			paddle->get_transform()->set_position(vec3(-30.f, 0, 0));
	}
}
