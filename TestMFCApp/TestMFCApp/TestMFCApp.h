
// TestMFCApp.h: g³ówny plik nag³ówkowy aplikacji PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "do³¹cz nag³ówek „pch.h” przed do³¹czeniem tego pliku na potrzeby optymalizacji PCH"
#endif

#include "resource.h"		// g³ówne symbole


// CTestMFCAppApp:
// Aby uzyskaæ implementacjê klasy, zobacz TestMFCApp.cpp
//

class CTestMFCAppApp : public CWinApp
{
public:
	CTestMFCAppApp();

// Przes³ania
public:
	virtual BOOL InitInstance();

// Implementacja

	DECLARE_MESSAGE_MAP()
};

extern CTestMFCAppApp theApp;
