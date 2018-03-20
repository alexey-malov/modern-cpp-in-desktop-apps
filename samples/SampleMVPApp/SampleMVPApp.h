
//  : main header file for the SampleMVPApp application
//
#pragma once

#ifndef __AFXWIN_H__
#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h" // main symbols

// SampleApp:
// See  for the implementation of this class
//

class SampleApp : public CWinApp
{
public:
	SampleApp();

	// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern SampleApp theApp;
