#pragma once


#include <memory>
#include "Thread.h"
#include "Component.h"

namespace DariusEngine
{
	class System
	{
	public:
		System()
		{

		}

	public:
		virtual std::shared_ptr<Component> createComponent(std::string) = 0; // hay que hacerlo en las hijas si o si
		virtual Task* getTask() { return nullptr; }
	};
}
