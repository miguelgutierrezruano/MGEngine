/*
 * @file Movement listener
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <event.h>
#include <entity.h>

using namespace MGEngine;

class MovementListener : public event_listener
{
	float speed = 60.f;

	float vertical_limit = 18.f;

protected:
	virtual void handle(const event& _event, float delta_time) override;
};
