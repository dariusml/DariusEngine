#pragma once

#include <map>
#include <string>
#include <memory>
#include "Transform_Component.h"
#include "MeshComponent.h"


namespace DariusEngine
{
	class Scene;

	class Entity
	{
		Scene* Owner;

		std::map<std::string, std::shared_ptr<Component> > components;

		Transform_Component transform;

	public:

		Entity(Scene* given_Owner) : Owner(given_Owner) {}

		//Component adders
	public:
		std::shared_ptr<Component> addComponent(const std::string& id, std::shared_ptr<Component> component);

		std::shared_ptr<MeshComponent> addMeshComponent();

	public:

		std::shared_ptr<Component> getComponent(const std::string& id)
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
