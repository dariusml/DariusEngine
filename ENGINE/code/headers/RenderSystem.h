#pragma once
#include "System.h"
#include "RenderTask.h"

namespace DariusEngine
{
	class RenderSystem : public System
	{
		RenderTask renderTask;

	public:

		Task* get_task()
		{
			return &renderTask;
		}
	};
}
