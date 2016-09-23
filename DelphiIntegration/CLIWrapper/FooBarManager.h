#pragma once

#include <Windows.h>

typedef void* (__stdcall *CreateFooBar)();
typedef void (__stdcall *DestroyFooBar)(void*);

ref class FooBarManager
{
public:
	FooBarManager();
	~FooBarManager();
	!FooBarManager();
	void* CreateNewFooBar();

private:
	HINSTANCE libHandle;
	CreateFooBar proc_createFooBar;
	DestroyFooBar proc_destroyFooBar;
};

