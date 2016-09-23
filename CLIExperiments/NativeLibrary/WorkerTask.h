#pragma once

#include <string>

class WorkerTask
{
public:
	WorkerTask(int outerLoopCount, int innerLoopCount, bool isEndingTask = false);
	WorkerTask(const WorkerTask& src);
	~WorkerTask();

	void Execute();

	bool isEndingTask() const { return m_isEndingTask; }

	std::string GetTaskDescription() const;

private:
	unsigned int m_outerLoopCount;
	unsigned int m_innerLoopCount;
	bool m_isEndingTask;
	double m_executionSeconds;

};

