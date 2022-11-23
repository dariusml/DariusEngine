#pragma once
#include <vector>

class MemoryAllocator
{
private:
	std::vector<char> allocation;

	unsigned int allocated;

public:
	MemoryAllocator(unsigned int bytesAllocated) : allocation(bytesAllocated){ allocated = 0; };
	
private:
	void* bytesAllocation(unsigned bytes) 
	{
		if (allocated + bytes > allocation.size()) return nullptr;

		void* chunk = allocation.data() + allocated;
		allocated += bytes;
		return chunk;
	}

public:
	template<typename TYPE, typename... Args>
	TYPE* allocate(Args... args)
	{
		TYPE* returner = static_cast<TYPE*>( bytesAllocation(sizeof(TYPE)) );
		returner = new(returner) TYPE(args...);

		return returner;
	}

};