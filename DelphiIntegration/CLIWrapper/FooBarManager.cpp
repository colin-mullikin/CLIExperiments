#include "FooBarManager.h"



FooBarManager::FooBarManager()
{
	libHandle = LoadLibrary(TEXT("DelphiDLL.dll"));
}

FooBarManager::~FooBarManager()
{
	if (NULL != libHandle)
	{
		FreeLibrary(libHandle);
	}
}

FooBarManager::!FooBarManager()
{
	if (NULL != libHandle)
	{
		FreeLibrary(libHandle);
	}
}
