#pragma once

#include <queue>
#include <Windows.h>
#include <time.h>
#include <list>
#include "WorkerTask.h"
#include "CriticalSectionHolder.h"

class Worker
{
public:
	Worker();
	virtual ~Worker();

	void QueueWorkerTask(const WorkerTask& task);
	WorkerTask GetQueuedWorkerTask();
	
	void Start();
	void Stop();
	double GetWorkingSeconds() const;
	void AddExecutedTask(const WorkerTask& task);
	void PrintStatistics();

	void QueueWorkerTask(unsigned int outerLoopCount, unsigned int innerLoopCount);
	void QueueDemoWorkerTasks();
	void ExecuteWorkerTask(unsigned int outerLoopCount, unsigned int innerLoopCount);

private:
	std::queue<WorkerTask> m_waitingTasks;
	std::vector<HANDLE> m_workerThreadsHandles;
	CriticalSectionHolder m_criticalSection;

	clock_t m_startClocks;
	clock_t m_stopClocks;

	bool m_isWorking;

	std::list<WorkerTask> m_executedTasks;


	static unsigned int __stdcall WorkerThreadProc(void* pParam);

};

