#pragma once

#include "chunked_memory_pool.h"

// Chunked memory pool with count size for type elements
template < typename TYPE >
class object_pool : protected chunked_memory_pool<sizeof(TYPE)>
{

public:

	object_pool(size_t count) : chunked_memory_pool<sizeof(TYPE)>(count * sizeof(chunked_memory_pool<sizeof(TYPE)>::Node))
	{

	}

	TYPE * allocate()
	{
		return new (chunked_memory_pool<sizeof(TYPE)>::allocate()) TYPE();
	}

	void free(TYPE* element)
	{
		chunked_memory_pool<sizeof(TYPE)>::free(element);
	}
};
