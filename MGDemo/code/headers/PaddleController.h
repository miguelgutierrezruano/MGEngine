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

class PaddleController : public controller
{
	entity* ball;

	float speed = 20.f;

public:

	PaddleController(entity* _ball);

	void update(float delta_time) override;
};


