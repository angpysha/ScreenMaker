
// Launcher.h : main header file for the Launcher application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CLauncherApp:
// See Launcher.cpp for the implementation of this class
//

class CLauncherApp : public CWinApp
{
public:
	CLauncherApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLauncherApp theApp;
