#include "FooBarManager.h"

FooBarManager::FooBarManager()
{
	libHandle = LoadLibrary(TEXT("DelphiDLL.dll"));

	if (NULL != libHandle)
	{
		proc_createFooBar = (CreateFooBar)GetProcAddress(libHandle, "CreateFooBar");
		proc_destroyFooBar = (DestroyFooBar)GetProcAddress(libHandle, "DestroyFooBar");
	}
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

void * FooBarManager::CreateNewFooBar()
{
	return proc_createFooBar();
}
