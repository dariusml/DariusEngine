#pragma once


#include <memory>
#include "Thread.h"
#include "Component.h"

namespace DariusEngine
{
	class System
	{
	public:

	public:
		virtual Task* getTask() = 0;
	};
}
