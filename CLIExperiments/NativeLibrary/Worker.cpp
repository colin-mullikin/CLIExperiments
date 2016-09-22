#include "stdafx.h"
#include "Worker.h"

#define WORKER_THREADS_NUM 4

Worker::Worker()
{
}

Worker::~Worker()
{
}

void Worker::QueueWorkerTask(const WorkerTask & task)
{
	m_waitingTasks.push(task);
}

WorkerTask Worker::GetQueuedWorkerTask()
{
	bool isTaskFound = false;

	WorkerTask res(0, 0);

	while (!isTaskFound)
	{
		if (!m_waitingTasks.empty())
		{
			res = m_waitingTasks.front();
			m_waitingTasks.pop();
			isTaskFound = true;
		}
	}

	return res;
}

unsigned int Worker::WorkerThreadProc(void * pParam)
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
	unsigned int threadID = 0;

	for (int threadInx = 0; threadInx < WORKER_THREADS_NUM; threadInx++)
	{

	}
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
}
