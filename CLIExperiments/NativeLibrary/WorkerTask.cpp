#include "stdafx.h"
#include "WorkerTask.h"


WorkerTask::WorkerTask(int outerLoopCount, int innerLoopCount, bool isEndingTask)
	:m_outerLoopCount(outerLoopCount),m_innerLoopCount(innerLoopCount),m_isEndingTask(isEndingTask)
{
}

WorkerTask::WorkerTask(const WorkerTask & src)
	: WorkerTask(src.m_outerLoopCount, src.m_innerLoopCount, src.m_isEndingTask)
{

}

WorkerTask::~WorkerTask()
{
}

void WorkerTask::Execute()
{
	for (unsigned int outerCount = 0; outerCount < m_outerLoopCount; outerCount++)
	{
		int* pi = new int[m_innerLoopCount];

		for (unsigned int innerCount = 0; innerCount < m_innerLoopCount; innerCount++)
		{
			pi[innerCount] = innerCount * outerCount;
		}

		delete[] pi;
	}
}
