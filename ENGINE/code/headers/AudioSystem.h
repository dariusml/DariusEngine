#pragma once

#include "System.h"
#include "AudioComponent.h"
#include "AudioTask.h"

namespace DariusEngine
{
	class AudioSystem : public System
	{
		AudioTask audioTask;

	public:

		Task* getTask() override
		{
			return &audioTask;
		}
	};
}
