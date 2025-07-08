#pragma once

#include<windows.h>
#include"ChCppWindows/ChCppBaseLibrary/ChBaseLibrary.h"
#include"ChCppWindows/ChCppWinLibrary/ChWindowsLibrary.h"

class ApplicationBase
{
public:

	virtual void Init(HINSTANCE) = 0;

	virtual void Update() = 0;

	virtual void Release() = 0;
};