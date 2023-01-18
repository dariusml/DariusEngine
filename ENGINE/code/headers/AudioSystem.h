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
		std::shared_ptr<Component> createComponent(std::string)
		{
			auto audioComponent = std::make_shared<AudioComponent>();
			//cargar el archivo de audio
			//audioComponent->sound = ...;
			return audioComponent;
		}
		Task* get_task()
		{
			return &audioTask;
		}
	};
}
