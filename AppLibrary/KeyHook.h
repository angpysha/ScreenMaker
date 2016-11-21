#pragma once
#include <functional>
#include "types.h"
#include <Windows.h>

class KeyHook
{
public:
	KeyHook();
	~KeyHook();
	BOOL setOpenOptionsEventHandler(std::function<void(std::string)>& func);
	static LRESULT CALLBACK hookproc_s(int vCode, WPARAM wparam, LPARAM lparam);
	LRESULT CALLBACK hookproc(int vCode, WPARAM wparam, LPARAM lparam);
	static KeyHook *getInstance();
	void setHook();
protected:
	std::function<void(std::string)> OpenOptions;
	HOOKPROC proc;
	 HHOOK hhook;
	 static KeyHook *instanse;
 };

