#pragma once
#include <queue>
#include <list>
#include "Thread.h"
#include <map>
#include <string>
#include <memory>
#include "glm/gtc/matrix_transform.hpp"

namespace DariusEngine
{
	class Kernel
	{
		std::list<Task*> tasks;

		bool exit;
		float fps;

	public:

		void addTask(Task* task)
		{

		}

		void setfps(float newFPS)
		{
			fps = newFPS;
		}

		void stop()
		{
			exit = true;
		}

		void execute()
		{
			exit = false;
			Timer timer;
			float frameDuration = 1.f / fps;
			float delta = frameDuration;
			do
			{
				timer.reset();
				for (Task* task : tasks)
				{
					task->Start(delta);

					float delay = frameDuration - timer.getElapsedSeconds();

					if (delay > 0.f)
					{
						std::this_thread::sleep_for(delay);
					}

					delta = timer.getElapsedSeconds;
				}
			} while (not exit);
		}
	};





	class Entity
	{
		Scene* Owner;

		std::map<std::string, Component* > components;

		Transform_Component transform;

	public:

		Entity(Scene* given_Owner) : Owner(given_Owner){}

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


	class Component
	{
		Entity* owner;
	};
	class Transform_Component : public Component
	{
	public:
		glm::vec3 position = glm::vec3(0,0,0);
		glm::vec3 rotation = glm::vec3(0, 0, 0);
		glm::vec3 scale = glm::vec3(1, 1, 1);
	};
	class AudioComponent : public Component
	{
		Sound* sound;
	};

	class Controller
	{
	public:
		virtual void update(float t, Entity& entity, Scene& scene) = 0;
	};

	class ControlComponenet
	{
		Controller* controller;
	};
	class ScriptComponent
	{
		std::string script;
	};






	class System
	{
	public:
		virtual std::shared_ptr<Component> createComponent(?) = 0; // hay que hacerlo en las hijas si o si
		virtual Task* getTask() { return nullptr; }
	};

	class ControlSystem
	{
		class ControlTask : public Task
		{
			ControlTask& system;

		public:

			ControlTask(ControlSystem & system);


			void Run(float frameDuration) override
			{
				for (auto& component : system.components)
				{
					//ESTO NO SSE HACE ASI
					component->controller->update(frameDuration, *component->entity, *compoienet->entity->scene);
				}
			}
		};
		std::vector<std::shared_ptr< ScriptComponent > >components;
	};

	class ScriptingSystem
	{
		class ScriptRunnerTask : public Task
		{
			ScriptingSystem& system;

		public:

			ScriptRunnerTask(ScriptingSystem& system);


			void Run(float frameDuration) override
			{
				for (auto& component : system.components)
				{
					//ESTO NO SSE HACE ASI
					system->interpreter.run_Script(component.script);
				}
			}
		};
		std::vector<std::shared_ptr< ScriptComponent > >components;
	};


	class Sound
	{

	};
	class AudioSystem : public System
	{
		class AudioTask : public Task
		{
		public:
			void run(float) override;
		};
		AudioTask audioTask;

	public:
		std::shared_ptr<Component> createComponent(xml_node<>*)
		{
			auto audioComponent = std::make_shared<AudioComponent>();
			//cargar el archivo de audio
			audioComponent->sound = ...;
			return audioComponent;
		}
		Task* get_task()
		{
			return &audioTask;
		}
	};
	class RenderSystem : public System
	{
		class RenderTask : public Task
		{
		public:
			void run(float) override;
		};
		RenderTask renderTask;

	public:

		Task* get_task()
		{
			return &renderTask;
		}
	};

	class Scene
	{

		std::map<std::string, std::shared_ptr<Entity>> entities;
		std::map<std::string, System*> systems;
		std::map<std::string, Controller*> controllers;

		Kernel kernel;

		InputSystem is;
		ScriptingSystem ss;
		RenderSystem rs;
		AudioSystem as;

	public:

		Scene(const std::string& sceneDataFilePath)
		{
			kernel.add_task(is.getTask());
			kernel.add_task(ss.getTask());
		}

		void addController(std::string id, Controller* controller);

		void run()
		{
			kernel.execute();
		}

	private:

		void loadScene(const std::string& sceneDataFilePath)
		{
			auto tree = std::make_shared<Entity>();

			//EJEMPLO
			Transform_Component tr = tree->get_transform();
			tr.position = glm::vec3(100, 0, 250.0f);




			entities["tree-1"] = tree;
		}

	};
}