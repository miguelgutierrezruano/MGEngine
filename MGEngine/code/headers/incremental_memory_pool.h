#pragma once

#include <vector>
#include <cstddef>
#include <cassert>

namespace MGEngine
{
	class incremental_memory_pool
	{
	private:
		// Vector to handle memory
		std::vector<std::vector<std::byte>> pools;
		// Size of allocated memory
		size_t allocated;
	public:
		size_t vector_index;
		size_t vector_size;

	public:
		incremental_memory_pool(size_t pool_size)
		{
			allocated = 0;
			vector_index = 0;
			vector_size = pool_size;

			pools.push_back(std::vector<std::byte>(pool_size));
		}


		template < typename TYPE, typename... Args >
		TYPE* allocate(Args... args)
		{
			auto object = reinterpret_cast<TYPE*>(allocate(sizeof(TYPE)));

			return new (object) TYPE(args...);
		}

		template < typename TYPE >
		void free(TYPE* object)
		{
			// Call destructor of class
			object->~TYPE();
		}

	private:
		// Allocate memory in vector or return nullptr
		void* allocate(size_t chunk_size)
		{
			if (allocated - (vector_index * vector_size) + chunk_size < pools[vector_index].size())
			{
				void* chunk = pools[vector_index].data() + allocated - (vector_index * vector_size);
				allocated += chunk_size;
				return chunk;
			}
			else
			{
				// Create new pool
				pools.push_back(std::vector<std::byte>(vector_size));
				++vector_index;

				// Set allocated to new pool
				allocated = vector_index * vector_size;

				void* chunk = pools[vector_index].data();
				allocated += chunk_size;
				return chunk;
			}
		}
	};
}
