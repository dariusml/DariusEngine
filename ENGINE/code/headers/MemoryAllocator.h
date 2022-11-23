#pragma once
#include <vector>

class MemoryAllocator
{
private:
	std::vector<char> allocation;
	unsigned int allocated;

public:
	MemoryAllocator(unsigned int bytesAllocated) : allocation(bytesAllocated) { allocated = 0; };
	
private:
	void* bytesAllocation(unsigned bytes) 
	{
		if (allocated + bytes > allocation.max_size()) return nullptr;

		void* chunk = allocation.data() + allocated;
		allocated += bytes;
		return chunk;
	}

public:
	template<typename TYPE>
	TYPE* allocate()
	{
		TYPE* returner = static_cast<TYPE*>( bytesAllocation(sizeof(TYPE)) );

		return returner;
	}

};