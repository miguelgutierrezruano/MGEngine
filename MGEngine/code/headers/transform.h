#pragma once

#include <component.h>

namespace MGEngine
{
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
			scale = vec3(1, 1, 1);
		}

		void reset()
		{
			position = vec3(0, 0, 0);
			rotation = vec3(0, 0, 0);
			scale = vec3(1, 1, 1);
		}

		vec3 get_position() { return position; }
		vec3 get_rotation() { return rotation; }
		vec3 get_scale() { return    scale; }

		void set_position(vec3 new_pos) { position = new_pos; }
		void set_rotation(vec3 new_rot) { rotation = new_rot; }
		void set_scale(vec3 new_scale) { scale = new_scale; }
	};
}
