#pragma once

#include <list>
#include <queue>
#include <memory>
#include <thread>
#include <mutex> 

namespace DariusEngine
{

	class Task
	{
	public:
		enum Status { WAITING, RUNNING, FINISHED, CANCELLED };
	protected:

		Status status;

	public:

		Task()
		{
			status = WAITING;
		}

		Status getStatus() const {
			return status;
		}

		void Cancel()
		{
			if (status != FINISHED) status = CANCELLED;
		}

		bool IsCancelled() const{
			return status == CANCELLED;
		}
		bool isFinished() const { return status == FINISHED; }

		void Start()
		{
			status = RUNNING;

			if (status != CANCELLED)
			{
				Run();
			}

			status = FINISHED;
		}
	protected:
		virtual void Run() = 0;
	};

	class Thread_Pool
	{
		std::list< std::shared_ptr<std::thread> > threads;

		std::queue< Task* > taskQueue;

		std::mutex task_queue_mutex;

		bool running;

	public:
		Thread_Pool()
		{
			running = false;
			for (int i = 0; i < std::thread::hardware_concurrency(); ++i)
			{
				threads.push_back(std::make_shared<std::thread>(threadFunction, this));
			}
			running = true;
		}

		void stop()
		{
			if (running)
			{
				running = false;
				for (auto& t : threads)
				{
					t->join();
				}
			}
		}

		void addTask(Task* task)
		{
			std::lock_guard<std::mutex> lock(task_queue_mutex);
			taskQueue.push(task);
		}

	private:

		static void threadFunction(Thread_Pool* threadPool)
		{
			while (threadPool->running)
			{
				Task* task;

				{
					std::lock_guard<std::mutex> lock(threadPool->task_queue_mutex);

					do
					{
						task = nullptr;

						if (not threadPool->taskQueue.empty())
						{
							task = threadPool->taskQueue.front();
							threadPool->taskQueue.pop();
						}
					} while (task->IsCancelled());
				}

				if (task)
				{
					task->Start();
				}
			}
		}


	private:
	};


	class TaskGroup : public Task
	{
		std::list<Task*> tasks;

		Thread_Pool& threadPool;

		std::list<Task*>::iterator currentTask;

	public:
		TaskGroup(Thread_Pool & givenThreadPool) : threadPool(givenThreadPool)
		{}

		void AddTask(Task* task) 
		{
			if (status = WAITING)
			{
				tasks.push_back(task);
			}
		}

		void Run() override
		{
			currentTask = tasks.begin();

			while (currentTask != tasks.end())
			{
				while (!(*currentTask)->isFinished())
				{
					std::this_thread::yield();
				}

				++currentTask;
			}
		}

	};


}
