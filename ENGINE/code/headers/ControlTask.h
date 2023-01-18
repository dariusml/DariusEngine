#pragma once

#include "Thread.h"

class ControlSystem;

namespace DariusEngine
{
	class ControlTask : public Task
	{
		ControlTask& system;

	public:

		ControlTask(ControlSystem& system);


		void Run() override
		{
			//for (auto& component : system.components)
			//{
			//	//ESTO NO SSE HACE ASI
			//	component->controller->update(frameDuration, *component->entity, *compoienet->entity->scene);
			//}
		}
	};
}
