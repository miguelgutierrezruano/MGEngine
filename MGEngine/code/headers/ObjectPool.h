#pragma once

#include "ChunkedMemoryPool.h"

// Chunked memory pool with count size for type elements
template < typename TYPE >
class ObjectPool : protected ChunkedMemoryPool<sizeof(TYPE)>
{

public:

	ObjectPool(size_t count) : ChunkedMemoryPool<sizeof(TYPE)>(count * sizeof(ChunkedMemoryPool<sizeof(TYPE)>::Node))
	{

	}

	TYPE * allocate()
	{
		return new (ChunkedMemoryPool<sizeof(TYPE)>::allocate()) TYPE();
	}

	void free(TYPE* element)
	{
		ChunkedMemoryPool<sizeof(TYPE)>::free(element);
	}
};
