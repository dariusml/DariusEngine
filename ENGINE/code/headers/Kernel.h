#pragma once
#include <queue>
#include <list>
#include "Thread.h"
#include <map>
#include <string>
#include <memory>


#include "Entity.h"

#include "Component.h"
#include "Transform_Component.h"

#include "System.h"
#include "ScriptingSystem.h"
#include "RenderSystem.h"
#include "AudioSystem.h"
#include "InputSystem.h"

//#include "Controller.h"

namespace DariusEngine
{
	class Kernel
	{
		std::list<Task*> tasks;

		bool exit = false;
		float fps;

	public:

		void addTask(Task* task)
		{
			tasks.push_back(task);
		}

		void setfps(float newFPS)
		{
			fps = newFPS;
		}

		void stop()
		{
			exit = true;
		}

		void execute();
	};
}