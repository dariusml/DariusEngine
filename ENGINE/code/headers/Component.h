#pragma once
#include <string>

namespace DariusEngine
{
	class Entity;

	class Component
	{
	protected:
		Entity* owner = nullptr;

	public:
		virtual Entity* getOwner() { return owner; }

		static std::string name() { return ""; };
	};
}
