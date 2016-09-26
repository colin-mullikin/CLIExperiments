#include "FooBar.h"

FooBar::FooBar()
{
	if (NULL != proc_Create)
	{
		fInternalFooBar = proc_Create();
	}
}

FooBar::~FooBar()
{
	if (NULL != proc_Destroy)
	{
		proc_Destroy(fInternalFooBar);
	}
}

FooBar::!FooBar()
{
	if (NULL != proc_Destroy)
	{
		proc_Destroy(fInternalFooBar);
	}
}

void FooBar::Initialize()
{
	libHandle = LoadLibrary(TEXT("DelphiDLL.dll"));

	if (NULL != libHandle)
	{
		proc_Create = (CreateFooBar)GetProcAddress(libHandle, "CreateFooBar");
		proc_Destroy = (DestroyFooBar)GetProcAddress(libHandle, "DestroyFooBar");
	}
}

void FooBar::TearDown()
{
	if (NULL != libHandle)
	{
		FreeLibrary(libHandle);
	}
}
