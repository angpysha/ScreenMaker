#pragma once
#include "stdafx.h"
#include "types.h"
#include <functional>

enum Action
{
	Screen,
	Options,
	Exit,
};
using namespace std;
class EXPORT KeyCodeWrapper
{
private:KeyCodeWrapper();
public:
	KeyCodeWrapper(string value);
	~KeyCodeWrapper();
#pragma region Keycodes
	KeyCode codes { 
		{"A",0x41},
	{ "B",0x42 },
	{ "C",0x43 },
	{ "D",0x44 },
	{ "E",0x45 },
	{ "F",0x46 },
	{ "G",0x47 },
	{ "H",0x48 },
	{ "I",0x49 },
	{ "J",0x4A },
	{ "K",0x4B },
	{ "L",0x4C },
	{ "M",0x4D },
	{ "N",0x4E },
	{ "O",0x4F },
	{ "P",0x50 },
	{ "Q",0x51 },
	{ "R",0x52 },
	{ "S",0x53 },
	{ "T",0x54 },
	{ "U",0x55 },
	{ "V",0x56 },
	{ "W",0x57 },
	{ "X",0x58 },
	{ "Y",0x59 },
	{ "Z",0x5A },
	{"LWIN",VK_LWIN},
	{"RWIN",VK_RWIN},
	{"LSHIFT",VK_LSHIFT},
	{"LSHIFT",VK_RSHIFT},
	{"LCTRL",VK_LCONTROL},
	{"RCTRL",VK_RCONTROL},
	{"RIGHT",VK_RIGHT},
	{"LEFT",VK_LEFT},
	{"DOWN",VK_DOWN},
	{"UP",VK_UP},
	{"TAB",VK_TAB},
	{"F1",VK_F1},
	{ "F2",VK_F2 },
	{ "F3",VK_F3 },
	{ "F4",VK_F4 },
	{ "F5",VK_F5 },
	{ "F6",VK_F6 },
	{ "F7",VK_F7 },
	{ "F8",VK_F8 },
	{ "F9",VK_F9 },
	{ "F10",VK_F10 },
	{ "F11",VK_F11 },
	{ "F12",VK_F12 },
	{"ESC",VK_ESCAPE},
	{"END",VK_END},
	{"HOME",VK_HOME},
	{"PAUSE",VK_PAUSE},
	{"NUMLOCK",VK_NUMLOCK},
	{"INS",VK_INSERT},
	{"DEL",VK_DELETE},
	{"BACKSPACE",VK_BACK},
	{"SPACE",VK_SPACE},
	{"PRTSCR",VK_PRINT},
	{"SCRLCK",VK_SCROLL},
	{"0",0x30},
	{ "1",0x31 },
	{ "2",0x32 },
	{ "3",0x33 },
	{ "4",0x34 },
	{ "5",0x35 },
	{ "6",0x36 },
	{ "7",0x37 },
	{ "8",0x38 },
	{ "9",0x39 },
	{ "NUM0",VK_NUMPAD0 },
	{ "NUM1",VK_NUMPAD1 },
	{ "NUM2",VK_NUMPAD2 },
	{ "NUM3",VK_NUMPAD3 },
	{ "NUM4",VK_NUMPAD4 },
	{ "NUM5",VK_NUMPAD5 },
	{ "NUM6",VK_NUMPAD6 },
	{ "NUM7",VK_NUMPAD7 },
	{ "NUM8",VK_NUMPAD8 },
	{ "NUM9",VK_NUMPAD9 },
	};
#pragma endregion 
	map<Action,vector<uint>> keys;
protected:
	map<string, Action> action {{"Screen",Action::Screen},
	{ "Options",Action::Options},
	{ "Exit",Action::Exit }
	};
};

