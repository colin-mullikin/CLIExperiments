#pragma once

#include <Windows.h>

typedef void* (__stdcall *CreateFooBar)();
typedef void(__stdcall *DestroyFooBar)(void*);

ref class FooBar
{
public:
	FooBar();
	~FooBar();
	!FooBar();

	static void Initialize(); //Must call this before FooBar class can be used!
	static void TearDown(); //Must call this after FooBar class is done being used!

private:
	void* fInternalFooBar;

	static HINSTANCE libHandle;
	static CreateFooBar proc_Create;
	static DestroyFooBar proc_Destroy;
};

