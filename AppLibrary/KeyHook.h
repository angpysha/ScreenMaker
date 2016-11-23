#pragma once
#include <functional>
#include "types.h"
#include <Windows.h>
#include "KeyCodeWrapper.h"
using namespace std;
class KeyHook
{
public:
	BOOL setOpenOptionsEventHandler(std::function<void(std::string)>& func);
	static LRESULT CALLBACK hookproc_s(int vCode, WPARAM wparam, LPARAM lparam);
	LRESULT CALLBACK hookproc(int vCode, WPARAM wparam, LPARAM lparam);
	static KeyHook *getInstance();
	void setOptionsEventHendler(std::function<void()> &func);
	void callOpenParams();
	void setExitOptionEventHandler(function<void()> &func);
	void callExitApplication();
	void setHook();
protected:
	std::function<void(std::string)> OpenOptions;
	static KeyHook* instanse;
	map<Action, vector<uint>> keys;
	map<Action, vector<bool>> trig;
	function<void()> openParams;
	function<void()> exitOption;
	HOOKPROC proc;
	 HHOOK hhook;
	 KeyHook();
	 virtual ~KeyHook();
 };

