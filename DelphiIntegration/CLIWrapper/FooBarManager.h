#pragma once

#include <Windows.h>

ref class FooBarManager
{
public:
	FooBarManager();
	~FooBarManager();
	!FooBarManager();

private:
	HINSTANCE libHandle;
};

