#pragma once

#include "System.h"

namespace DariusEngine
{
	class ScriptingSystem : public System
	{
		class ScriptRunnerTask : public Task
		{
			ScriptingSystem& system;

		public:

			ScriptRunnerTask(ScriptingSystem& system);


			void Run() override
			{
				//for (auto& component : system.components)
				//{
				//	//ESTO NO SSE HACE ASI
				//	system->interpreter.run_Script(component.script);
				//}
			}
		};
		//std::vector<std::shared_ptr< ScriptComponent > >components;
	};
}
