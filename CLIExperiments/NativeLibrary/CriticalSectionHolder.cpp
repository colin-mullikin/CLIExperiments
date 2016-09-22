#include "stdafx.h"
#include "CriticalSectionHolder.h"


CriticalSectionHolder::CriticalSectionHolder()
{
	::InitializeCriticalSection(&m_criticalSection);
}


CriticalSectionHolder::~CriticalSectionHolder()
{
	::DeleteCriticalSection(&m_criticalSection);
}
