#include "../headers/Kernel.h"
#include "../headers/Timer.h"

#include "Thread"
#include <chrono> 

namespace DariusEngine
{

	void Kernel::execute()
	{
		exit = false;
		Timer timer;
		float frameDuration = 1.f / fps;
		float delta = frameDuration;
		do
		{
			timer.start();
			for (Task* task : tasks)
			{
				task->Start(delta);

				float delay = frameDuration - (float)timer.elapsedSeconds();

				if (delay > 0.f)
				{
					std::this_thread::sleep_for(std::chrono::duration<float>{delay});
				}

				delta = (float)timer.elapsedSeconds();
			}
		} while (not exit);
	}

}