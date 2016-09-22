#pragma once
#include <queue>;
#include "WorkerTask.h";

class Worker
{
public:
	Worker();
	virtual ~Worker();

	void QueueWorkerTask(const WorkerTask& task);
	WorkerTask GetQueuedWorkerTask();

private:
	std::queue<WorkerTask> m_waitingTasks;
};

