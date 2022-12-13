#pragma once

#include "ChunkedMemoryPool.h"

template < typename TYPE >
class ObjectPool : protected ChunkedMemoryPool<sizeof(TYPE)>
{

public:

	// Create a chunked memory pool
	ObjectPool(size_t count) : ChunkedMemoryPool<sizeof(TYPE)>(count * sizeof(ChunkedMemoryPool<sizeof(TYPE)>::Node))
	{

	}

	TYPE * allocate()
	{
		return nullptr;
	}

	void free(TYPE* element)
	{
				
	}
};
