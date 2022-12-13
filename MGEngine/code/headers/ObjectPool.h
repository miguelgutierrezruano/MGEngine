#pragma once

#include "ChunkedMemoryPool.h"

template < typename TYPE >
class ObjectPool : protected ChunkedMemoryPool<sizeof(TYPE)>
{

public:

	ObjectPool(size_t count) : ChunkedMemoryPool<sizeof(TYPE)>(count * sizeof(Node))
	{

	}

	TYPE * allocate()
	{
		return nullptr;
	}

	void free(TYPE* element)
	{
		ChunkedMemoryPool::free(element);			
	}
};
