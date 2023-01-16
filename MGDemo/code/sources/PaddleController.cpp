
#include <PaddleController.h>
#include <entity.h>

using namespace MGEngine;

PaddleController::PaddleController(entity* _ball)
{
	ball = _ball;
}

void PaddleController::update(float delta_time)
{
	if (ball != nullptr)
	{
		vec3 position = owner->get_transform()->get_position();

		if (position.y > ball->get_transform()->get_position().y)
			position.y -= speed * delta_time;
		else
			position.y += speed * delta_time;

		owner->get_transform()->set_position(position);
	}
}
