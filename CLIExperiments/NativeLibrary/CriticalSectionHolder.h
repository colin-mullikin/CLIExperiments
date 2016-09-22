#pragma once

#include <Windows.h>

class CriticalSectionHolder
{
public:
	CriticalSectionHolder();
	virtual ~CriticalSectionHolder();

	LPCRITICAL_SECTION GetCriticalSection() { return &m_criticalSection; }

private:
	CRITICAL_SECTION m_criticalSection;
};

