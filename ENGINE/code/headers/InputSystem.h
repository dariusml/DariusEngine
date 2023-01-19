#pragma once

#include "System.h"
#include "InputTask.h"

namespace DariusEngine
{
	class InputSystem : public System
	{
		InputTask inputTask;

	public:

		Task* getTask() override
		{
			return &inputTask;
		}
	};
}
