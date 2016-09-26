#include "FooBar.h"

namespace CLIWrapper {
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

	int FooBar::GetFooValue()
	{
		if (NULL != proc_GetFoo)
		{
			return proc_GetFoo(fInternalFooBar);
		}
		else
		{
			return -1;
		}
	}

	void FooBar::Initialize()
	{
		libHandle = LoadLibrary(TEXT("DelphiDLL.dll"));

		if (NULL != libHandle)
		{
			proc_Create = (CreateFooBar)GetProcAddress(libHandle, "CreateFooBar");
			proc_Destroy = (DestroyFooBar)GetProcAddress(libHandle, "DestroyFooBar");
			proc_GetFoo = (GetFoo)GetProcAddress(libHandle, "GetFoo");
		}
	}

	void FooBar::TearDown()
	{
		if (NULL != libHandle)
		{
			FreeLibrary(libHandle);
		}
	}

}
