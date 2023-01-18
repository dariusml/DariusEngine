#pragma once

#include <map>
#include <string>
#include "Transform_Component.h"


namespace DariusEngine
{
	class Scene;

	class Entity
	{
		Scene* Owner;

		std::map<std::string, Component* > components;

		Transform_Component transform;

	public:

		Entity(Scene* given_Owner) : Owner(given_Owner) {}

		void addComponent(const std::string& id, Component* component);

		Component* getComponent(const std::string& id)
		{
			auto item = components.find(id);

			return item != components.end() ? item->second : nullptr;
		}

		Transform_Component& get_transform()
		{
			return transform;
		}
	};

}
