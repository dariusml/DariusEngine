#include "../headers/RenderTask.h"

#include <iostream>

namespace DariusEngine
{

	void RenderTask::Run()
	{
		for (std::shared_ptr<MeshComponent> meshComponent : meshes)
		{
			renderMesh(meshComponent);
		}
	}

	void RenderTask::renderMesh(std::shared_ptr<MeshComponent> mesh)
	{
		std::cout << mesh->texto << std::endl;
	}
}