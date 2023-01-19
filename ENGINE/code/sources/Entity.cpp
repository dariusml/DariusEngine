#include "../headers/Entity.h"
#include "../headers/Scene.h"

namespace DariusEngine
{

	std::shared_ptr<Component> Entity::addComponent(const std::string& id, std::shared_ptr<Component> component)
	{
		//Won't create if already exist
		if (components.find(id) != components.end()) 
		{
			return components[id];
		}
		components[id] = component;
		return component;
	}

	std::shared_ptr<MeshComponent> Entity::addMeshComponent()
	{
		std::shared_ptr meshcomp = std::dynamic_pointer_cast<MeshComponent>(addComponent(MeshComponent::name(), std::make_shared<MeshComponent>()));
		Owner->addInRenderTask(meshcomp);
		return meshcomp;
	}

}