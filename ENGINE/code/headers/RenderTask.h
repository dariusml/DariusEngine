#pragma once

#include "Thread.h"
#include <memory>
#include "MeshComponent.h"

namespace DariusEngine
{

	class RenderTask : public Task
	{
	private:
		std::list< std::shared_ptr<MeshComponent> > meshes;

	public:
		void Run() override;

	public:
		void addMeshComponent(std::shared_ptr<MeshComponent> meshComp)
		{
			meshes.push_back(meshComp);
		}

	private:
		void renderMesh(std::shared_ptr<MeshComponent> mesh);
	};

}
