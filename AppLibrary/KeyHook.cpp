#include "stdafx.h"
#include "KeyHook.h"

KeyHook* key_hook = new KeyHook;
KeyHook::KeyHook()
{
	//this->instanse = this;
	//proc = hookproc;
}

KeyHook* KeyHook::getInstance()
{
	/*if (instanse)
		return instanse;*/
	return new KeyHook();
}


KeyHook::~KeyHook()
{
}

BOOL KeyHook::setOpenOptionsEventHandler(std::function<void(std::string)> &func)
{
	try {
		this->OpenOptions = func;
		return OpenOptions ? TRUE : FALSE;
	} catch(std::exception)
	{
		return FALSE;
	}
}
LRESULT CALLBACK KeyHook::hookproc_s(int vCode, WPARAM wparam, LPARAM lparam)
{
	return key_hook->hookproc(vCode, wparam, lparam);
	//return CallNextHookEx(hhook, vCode, wparam, lparam);
	return LRESULT();
}

LRESULT KeyHook::hookproc(int vCode, WPARAM wparam, LPARAM lparam)
{
	return CallNextHookEx(hhook, vCode, wparam, lparam);
	return LRESULT();
}

void KeyHook::setHook()
{
	HINSTANCE hinstance = LoadLibrary(L"User32");
	hhook = ::SetWindowsHookEx(WH_KEYBOARD_LL, hookproc_s,hinstance, 0);
}


