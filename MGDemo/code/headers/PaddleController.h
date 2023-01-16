/*
 * @file PaddleController
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <controller.h>

using namespace MGEngine;

class BallController;

class PaddleController : public controller
{
	entity* ball;
	BallController* ball_controller;

	float speed = 23.f;

public:

	PaddleController(entity* _ball);

	void update(float delta_time) override;
};


