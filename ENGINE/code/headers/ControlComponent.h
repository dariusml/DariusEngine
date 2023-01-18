#pragma once
#include "Component.h"
#include "Controller.h"

namespace DariusEngine
{
	class ControlComponenet : public Component
	{
		Controller* controller;
	};
}
