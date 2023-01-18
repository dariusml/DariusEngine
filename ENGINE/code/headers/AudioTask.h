#pragma once

#include "Thread.h"

namespace DariusEngine
{

	class AudioTask : public Task
	{
	public:
		void Run() override;
	};

}
