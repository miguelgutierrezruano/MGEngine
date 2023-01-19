/*
 * @file Ball Controller
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <controller.h>
#include <event.h>
#include <vector>

using namespace MGEngine;

class BallController : public controller
{
public:
	enum states
	{
		Idle,
		Moving
	};

private:

	states state;

	std::vector< entity* > paddles;

	float speed_y = 30.f;
	float speed_x = 30.f;

	float vertical_bound = 21.f;
	float horizontal_bound = 38.f;

public:

	BallController(entity* paddle1, entity* paddle2);

	void update(float delta_time) override;

	const states & get_state() { return state; }

	void set_moving_state() { state = Moving; }

private:

	// Check collisions with paddles
	void paddle_collision();

	void reset_ball();
};
