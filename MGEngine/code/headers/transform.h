/*
 * @file Transform
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

#include <component.h>
#include <glm.hpp>
#include <gtc/quaternion.hpp>

using namespace glm;

namespace MGEngine
{
	/// <summary>
	/// Transform component of entities
	/// </summary>
	class transform : public component
	{
		vec3 position;
		vec3 rotation;
		vec3 scale;

	public:

		/// <summary>
		/// Constructor of transform
		/// </summary>
		transform()
		{
			position = vec3(0, 0, 0);
			rotation = vec3(0, 0, 0);
			scale = vec3(1, 1, 1);
		}

		/// <summary>
		/// Reset transform
		/// </summary>
		void reset()
		{
			position = vec3(0, 0, 0);
			rotation = vec3(0, 0, 0);
			scale = vec3(1, 1, 1);
		}

		const vec3 get_position() const { return position; }

		/// Get position
		vec3 get_position() { return position; }
		/// Get rotation
		vec3 get_rotation() { return rotation; }
		/// Get scale
		vec3 get_scale() { return    scale; }

		/// Set position
		void set_position(vec3 new_pos) { position = new_pos; }
		/// Set rotation
		void set_rotation(vec3 new_rot) { rotation = new_rot; }
		/// Set scale
		void set_scale(vec3 new_scale) { scale = new_scale; }
	};
}
