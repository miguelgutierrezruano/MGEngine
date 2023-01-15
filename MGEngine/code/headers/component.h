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

		virtual ~component()
		{

		}
	};
}

