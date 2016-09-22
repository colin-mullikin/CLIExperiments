#include "stdafx.h"
#include "Worker.h"


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
