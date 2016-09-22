#pragma once

#include <Windows.h>;

class CriticalSectionLocker
{
public:
	CriticalSectionLocker(LPCRITICAL_SECTION pCriticalSection);
	virtual ~CriticalSectionLocker();

private:
	LPCRITICAL_SECTION m_pCriticalSection;
};

