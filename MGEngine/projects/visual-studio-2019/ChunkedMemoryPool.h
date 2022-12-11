#pragma once

#include <vector>

template< size_t CHUNK_SIZE >
class ChunkedMemoryPool
{

protected:

	// Defines each element in memory
	struct Node
	{
		byte chunk[CHUNK_SIZE];
		Node* prev;
		Node* next;
	};

private:

	std::vector<Node> pool;

	// Pointer to first used node
	Node* used_nodes;
	// Pointer to first free node
	Node* free_nodes;

public:

	// Initialize pool with given byte size
	ChunkedMemoryPool(size_t pool_size) : pool(pool_size / sizeof(Node))
	{
		// Set up first node
		pool[0].prev = nullptr;
		pool[0].next = &pool[1];

		// Set up nodes from second to penultimate
		for (size_t i = 1; i < pool.size() - 1; ++i)
		{
			// Get reference to vector element
			Node& node = pool[i];

			node.prev = &pool[i - 1];
			node.next = &pool[i + 1];
		}

		// Set up last node
		pool[pool.size() - 1].prev = &pool[pool.size() - 2];
		pool[pool.size() - 1].next = nullptr;

		// Initial references
		used_nodes = nullptr;
		free_nodes = &pool[0];
	}

protected:

	void * allocate()
	{
		if (free_nodes) 
		{
			Node* reserved = free_nodes;

			// Remove from free nodes list
			free_nodes = reserved->next;

			if (free_nodes)
				free_nodes->prev = nullptr;

			// Add to start of used nodes list
			if (used_nodes)
				used_nodes->prev = reserved;

			reserved->next = used_nodes;
			reserved->prev = nullptr;
			used_nodes = reserved;

			return reserved;
		}

		return nullptr;
	}
};
