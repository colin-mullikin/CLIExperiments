#pragma once

#include "..\NativeLibrary\Worker.h"

ref class CppCliWorker
{
public:
	CppCliWorker();
	~CppCliWorker();
	!CppCliWorker();

	void Start();
	void Stop();
	void QueueDemoWorkerTasks();
	void QueueWorkerTask(unsigned int outerLoopCount, unsigned int innerLoopCount);
	void ExecuteWorkerTask(unsigned int outerLoopCount, unsigned int innerLoopCount);

	void PrintStatistics();
	double GetWorkingSeconds();

private:
	Worker* m_actualWorker;
};

