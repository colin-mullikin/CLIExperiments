#pragma once

#include <queue>;
#include <Windows.h>;
#include "WorkerTask.h";
#include "CriticalSectionHolder.h";

class Worker
{
public:
	Worker();
	virtual ~Worker();

	void QueueWorkerTask(const WorkerTask& task);
	WorkerTask GetQueuedWorkerTask();
	unsigned int __stdcall WorkerThreadProc(void* pParam);
	void Start();
	void Stop();

private:
	std::queue<WorkerTask> m_waitingTasks;
	std::vector<HANDLE> m_workerThreadsHandles;
	CriticalSectionHolder m_criticalSection;

};

