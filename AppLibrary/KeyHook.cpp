#include "stdafx.h"
#include "KeyHook.h"
#include <algorithm>
KeyHook *KeyHook::instanse;
KeyHook::KeyHook()
{
	//this->instanse = this;
	//proc = hookproc;
}
KeyHook* KeyHook::getInstance()
{
	if (!instanse)
		instanse=new KeyHook();
	return instanse;
}

void KeyHook::setOptionsEventHendler(std::function<void()> &func)
{
	try
	{
		this->openParams = func;
	} catch(std::exception)
	{
		return;
	}
	//this->openParams
}

void KeyHook::callOpenParams()
{
	if (this->openParams)
		this->openParams();
}

void KeyHook::setExitOptionEventHandler(function<void()>& func)
{
	try
	{
		this->exitOption = func;
	} catch(std::exception e)
	{
		return;
	}
}

void KeyHook::callExitApplication()
{
	if (this->exitOption)
		this->exitOption();
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
	return instanse->hookproc(vCode, wparam, lparam);
	//return CallNextHookEx(hhook, vCode, wparam, lparam);
	return LRESULT();
}

LRESULT KeyHook::hookproc(int vCode, WPARAM wparam, LPARAM lparam)
{
	if (vCode >=0)
	{
		switch (wparam)
		{
		case (WM_KEYDOWN):
			{
				auto p = reinterpret_cast<PKBDLLHOOKSTRUCT>(lparam);
				for (auto z : this->keys)
				{
					//vector<bool> tmp;
					if (std::find(z.second.begin() + 1, z.second.end(), p->vkCode)!=z.second.end())
						//tmp.push_back(true);
					{
						trig[z.first].push_back(true);
					}
					//if (std::all_of(tmp.begin()+1,tmp.end(),TRUE))
				}

				for (auto kk : this->trig)
				{
					if (kk.second.size() == this->keys[kk.first].size())
					{
						switch (kk.first)
						{
						case (Action::Exit):
							{
							this->callExitApplication();
						}; break;
						case (Action::Options):
							{
							this->callOpenParams();
							//Maybe reload settings if changed
						}; break;
						case (Action::Screen):
							{
								
						};break;
						default:break;
						}
					}
				}
		}; break;
		case (WM_KEYUP):
			{
			auto p = reinterpret_cast<PKBDLLHOOKSTRUCT>(lparam);
		}; break;
		}
	}
	return CallNextHookEx(hhook, vCode, wparam, lparam);
	return LRESULT();
}

void KeyHook::setHook()
{
	HINSTANCE hinstance = LoadLibrary(L"User32");
	hhook = ::SetWindowsHookEx(WH_KEYBOARD_LL, hookproc_s,hinstance, 0);
}


