#pragma once
#include "System.h"
#include "ScriptComponent.h"

namespace DariusEngine
{
	class ControlSystem : public System
	{
		std::vector<std::shared_ptr< ScriptComponent > >components;
	};
}