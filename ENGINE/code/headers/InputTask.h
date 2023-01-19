#pragma once

#include "Thread.h"

namespace DariusEngine
{

	class InputTask : public Task
	{
	public:
		void Run() override;
	};

}