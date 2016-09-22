#include <process.h>
#include "stdafx.h"
#include "Worker.h"
#include "CriticalSectionLocker.h"
#include <process.h>

#define WORKER_THREADS_NUM 4

Worker::Worker()
	:m_isWorking(false)
{
}

Worker::~Worker()
{
}

void Worker::QueueWorkerTask(const WorkerTask & task)
{
	CriticalSectionLocker locker(m_criticalSection.GetCriticalSection());
	m_waitingTasks.push(task);
}

WorkerTask Worker::GetQueuedWorkerTask()
{
	bool isTaskFound = false;

	WorkerTask res(0, 0);

	while (!isTaskFound)
	{
		CriticalSectionLocker locker(m_criticalSection.GetCriticalSection());
		if (!m_waitingTasks.empty())
		{
			res = m_waitingTasks.front();
			m_waitingTasks.pop();
			isTaskFound = true;
		}
	}

	return res;
}

unsigned int __stdcall Worker::WorkerThreadProc(void * pParam)
{
	Worker* theWorker = reinterpret_cast<Worker*>(pParam);

	while (true)
	{
		WorkerTask task = theWorker->GetQueuedWorkerTask();

		if (task.isEndingTask())
		{
			break;
		}

		task.Execute();
	}

	return 0;
}

void Worker::Start()
{
	m_startClocks = clock();
	unsigned int threadID = 0;

	for (int threadInx = 0; threadInx < WORKER_THREADS_NUM; threadInx++)
	{
		m_workerThreadsHandles[threadInx] = (HANDLE)::_beginthreadex(0, 0, WorkerThreadProc, (void*)this, 0, &threadID);
	}

	m_isWorking = true;
}

void Worker::Stop()
{
	for (int endingTaskInx = 0; endingTaskInx < WORKER_THREADS_NUM; endingTaskInx++)
	{
		QueueWorkerTask(WorkerTask(0, 0, true));
	}

	for (int threadInx = 0; threadInx < WORKER_THREADS_NUM; threadInx++)
	{
		HANDLE currHandle = m_workerThreadsHandles[threadInx];

		if (0 == currHandle)
		{
			continue;
		}

		::WaitForSingleObject(currHandle, INFINITE);

		::CloseHandle(currHandle);
		m_workerThreadsHandles[threadInx] = 0;
	}

	m_isWorking = false;
	m_stopClocks = clock();
}

double Worker::GetWorkingSeconds() const
{
	return (double)((m_isWorking ? clock() : m_stopClocks) - m_startClocks) / CLOCKS_PER_SEC;
}
