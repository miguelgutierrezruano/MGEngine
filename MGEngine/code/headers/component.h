#pragma once

#include <glm.hpp>
#include <gtc/quaternion.hpp>

using namespace glm;

namespace MGEngine
{
	class entity;

	class component
	{
		// System can affect entities that have their component
	public:
		entity * owner;

	public:

		void set_owner(entity* _owner)
		{
			owner = _owner;
		}

		entity * get_owner()
		{
			return owner;
		}
	};

	class transform : public component
	{
		vec3 position;
		vec3 rotation;
		vec3 scale;

	public:

		transform()
		{
			position = vec3(0, 0, 0);
			rotation = vec3(0, 0, 0);
			scale    = vec3(1, 1, 1);
		}

		void reset()
		{
			position = vec3(0, 0, 0);
			rotation = vec3(0, 0, 0);
			scale = vec3(1, 1, 1);
		}

		vec3 get_position() { return position; }
		vec3 get_rotation() { return rotation; }
		vec3 get_scale()    { return    scale; }

		void set_position(vec3 new_pos) { position = new_pos; }
		void set_rotation(vec3 new_rot) { rotation = new_rot; }
		void set_scale (vec3 new_scale) { scale  = new_scale; }
	};
}

