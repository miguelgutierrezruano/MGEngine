/*
 * @file Component
 * @author Miguel Gutierrez
 *
 * Copyright (c) 2022 miguelguti
 *
 * Distributed under the MIT License
 */

#pragma once

namespace MGEngine
{
	class entity;

	/// <summary>
	/// ECS component. Should be overrided to apply behaviour
	/// </summary>
	class component
	{
		
	protected:
		entity * owner;

	public:

		/// <summary>
		/// Setter of owner
		/// </summary>
		/// <param name="_owner">Entity that owns the component</param>
		void set_owner(entity* _owner)
		{
			owner = _owner;
		}

		/// <summary>
		/// Getter of owner
		/// </summary>
		/// <returns>Pointer to entity that owns the component</returns>
		entity * get_owner()
		{
			return owner;
		}

		virtual ~component()
		{

		}
	};
}

