/*
 * @file Ball listener
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <entity.h>
#include <event.h>

using namespace MGEngine;

class BallController;

class BallListener : public event_listener
{
	BallController* ball_controller;

	virtual void handle(const event& _event, float delta_time) override;

public:

	void set_ball_controller(BallController* _owner) { ball_controller = _owner; }
};
