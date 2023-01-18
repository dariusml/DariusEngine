#pragma once

#include "Thread.h"

namespace DariusEngine
{

	class RenderTask : public Task
	{
	public:
		RenderTask()
		{

		}

	public:
		void Run() override;
	};

}
