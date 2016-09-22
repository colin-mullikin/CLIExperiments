#pragma once
class WorkerTask
{
public:
	WorkerTask(int outerLoopCount, int innerLoopCount, bool isEndingTask = false);
	WorkerTask(const WorkerTask& src);
	~WorkerTask();

	void Execute();

	bool isEndingTask() const { return m_isEndingTask; }

private:
	unsigned int m_outerLoopCount;
	unsigned int m_innerLoopCount;
	bool m_isEndingTask;
};

