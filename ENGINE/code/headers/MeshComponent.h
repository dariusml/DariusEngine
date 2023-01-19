#pragma once

#include "Component.h"
#include "Mesh.h"

namespace DariusEngine
{
	class MeshComponent : public Component
	{
	public:
		std::string texto = "as";
		Mesh* mesh = nullptr;

	public:

		static std::string name()
		{
			return "MeshRenderer";
		}
	};
}