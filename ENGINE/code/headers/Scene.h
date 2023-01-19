#pragma once

#include "Kernel.h"

namespace DariusEngine
{
	class Scene
	{

		std::map<std::string, std::shared_ptr<Entity>> entities;
		std::map<std::string, System*> systems;
		//std::map<std::string, Controller*> controllers;

		Kernel kernel;

		//InputSystem is;
		//ScriptingSystem ss;
		RenderSystem rs;
		AudioSystem as;

	public:

		Scene(const std::string& sceneDataFilePath)
		{
			//kernel.addTask(is.getTask());
			//kernel.addTask(ss.getTask());
			kernel.addTask(rs.getTask());

			kernel.setfps(60.0f);

			loadScene(sceneDataFilePath);
		}

		//void addController(std::string id, Controller* controller);

		void run()
		{
			kernel.execute();
		}

	private:

		void loadScene(const std::string& sceneDataFilePath)
		{
			auto tree = std::make_shared<Entity>(this);

			//EJEMPLO
			Transform_Component tr = tree->get_transform();
			tr.position = glm::vec3(100, 0, 250.0f);

			tree->addMeshComponent();

			auto tree2 = std::make_shared<Entity>(this);
			tree2->addMeshComponent();
			std::shared_ptr<MeshComponent> meshComponent = std::dynamic_pointer_cast<MeshComponent>(tree2->getComponent(MeshComponent::name()));
			meshComponent->texto = "experimento2";

			entities["tree-1"] = tree;
		}

	public:

		void addInRenderTask(std::shared_ptr<MeshComponent> meshComp)
		{
			rs.getTask()->addMeshComponent(meshComp);
		}

	};
}
