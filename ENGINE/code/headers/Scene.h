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
		//RenderSystem rs;
		//AudioSystem as;

	public:

		Scene(const std::string& sceneDataFilePath)
		{
			//kernel.addTask(is.getTask());
			//kernel.addTask(ss.getTask());
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

			entities["tree-1"] = tree;
		}

	};
}
