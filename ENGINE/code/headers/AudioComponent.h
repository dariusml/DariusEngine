#pragma once
#include "Component.h"
#include "Sound.h"

namespace DariusEngine
{
	class AudioComponent : public Component
	{
	public:

		Sound* sound;
	};
}
