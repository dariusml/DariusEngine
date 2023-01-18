#pragma once
#include "Component.h"

#include "glm/gtc/matrix_transform.hpp"

namespace DariusEngine
{
	class Transform_Component : public Component
	{
	public:
		glm::vec3 position = glm::vec3(0, 0, 0);
		glm::vec3 rotation = glm::vec3(0, 0, 0);
		glm::vec3 scale = glm::vec3(1, 1, 1);
	};
}
