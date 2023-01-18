#pragma once

#include "Entity.h"
#include "Scene.h"

namespace DariusEngine
{
	class Controller
	{
	public:
		virtual void update(float t, Entity& entity, Scene& scene) = 0;
	};
}