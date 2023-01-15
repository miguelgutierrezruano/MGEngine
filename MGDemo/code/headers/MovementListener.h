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
	entity* owner;

	virtual void handle(const event& _event) override;

public:

	void set_owner(entity* _owner) { owner = _owner; }
};
