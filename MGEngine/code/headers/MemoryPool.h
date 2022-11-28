#pragma once

#include <vector>
#include <cstddef>

class MemoryPool
{
private:
	// Vector to handle memory
	std::vector<std::byte> pool;
	// Size of allocated memory
	size_t allocated;

public:
	MemoryPool(size_t pool_size) : pool(pool_size)
	{
		allocated = 0;
	}

	// Public allocate
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
	void * allocate(size_t chunk_size)
	{
		if (allocated + chunk_size < pool.size())
		{
			void * chunk = pool.data() + allocated;
			allocated += chunk_size;
			return chunk;
		}

		return nullptr;
	}
};
