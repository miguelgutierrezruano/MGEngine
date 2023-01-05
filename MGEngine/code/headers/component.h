#pragma once

#include <glm.hpp>
#include <gtc/quaternion.hpp>

using namespace glm;

namespace MGEngine
{
	class entity;

	class component
	{
		// System can affect entities that have any component
		entity* owner;

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
		vec3 position = vec3(0, 0, 0);
		quat rotation = vec3(0, 0, 0);
		vec3 scale    = vec3(1, 1, 1);
	};
}

