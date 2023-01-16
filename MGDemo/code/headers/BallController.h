
#pragma once

#include <controller.h>
#include <vector>

using namespace MGEngine;

class BallController : public controller
{
	std::vector< entity* > paddles;

	float speed_y = 30.f;
	float speed_x = 30.f;

	float vertical_bound = 21.f;
	float horizontal_bound = 38.f;

public:

	// Add references to paddles
	BallController();

	void update(float delta_time) override;
};
