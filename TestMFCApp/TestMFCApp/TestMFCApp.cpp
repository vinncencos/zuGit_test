
// TestMFCApp.cpp: definiuje zachowania klasy dla aplikacji.
//

#include "pch.h"
#include "framework.h"
#include "TestMFCApp.h"
#include "TestMFCAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMFCAppApp

BEGIN_MESSAGE_MAP(CTestMFCAppApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Konstrukcja klasy CTestMFCAppApp

CTestMFCAppApp::CTestMFCAppApp()
{
	// obs³uga mened¿era ponownego uruchamiania
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: W tym miejscu dodaj kod konstruktora,
	// Umieœæ wszystkie znacz¹ce inicjacje w InitInstance
}


// Jedyny obiekt CTestMFCAppApp

CTestMFCAppApp theApp;


// Inicjowanie klasy CTestMFCAppApp

BOOL CTestMFCAppApp::InitInstance()
{
	// Funkcja InitCommonControlsEx() jest wymagana w systemie Windows XP, jeœli aplikacja
	// manifest okreœla u¿ycie pliku ComCtl32.dll w wersji 6 lub nowszej, który ma zostaæ u¿yty
	// style wizualne. W przeciwnym razie utworzenie jakiegokolwiek okna nie powiedzie siê.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Ustaw ten element tak, aby uwzglêdnia³ wszystkie typowe klasy kontrolek, których chcesz u¿yæ
	// w aplikacji.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Utwórz mened¿era pow³oki, jeœli okno dialogowe zawiera
	// dowolne kontrolki widoku drzewa pow³oki lub widoku listy pow³oki.
	CShellManager *pShellManager = new CShellManager;

	// Aktywuj natywnego mened¿era obiektów wizualnych systemu Windows, aby w³¹czyæ kompozycje dla kontrolek MFC
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Inicjowanie standardowe
	// Jeœli nie u¿ywasz tych funkcji i chcesz zmniejszyæ rozmiar
	// koñcowego pliku wykonywalnego, usuñ poni¿ej
	// okreœlone procedury inicjowania, które nie s¹ potrzebne
	// Zmieñ klucz rejestru, w którym s¹ przechowywane ustawienia
	// TODO: zmodyfikuj ten ci¹g, aby by³ poprawny
	// takie jak nazwa firmy lub organizacji
	SetRegistryKey(_T("Aplikacje lokalne wygenerowane przez kreatora aplikacji"));

	CTestMFCAppDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: umieœæ tutaj kod, który ma byæ obs³ugiwany, gdy okno dialogowe
		//  odrzucone za pomoc¹ pozycji OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: umieœæ tutaj kod, który ma byæ obs³ugiwany, gdy okno dialogowe
		//  odrzucone za pomoc¹ polecenia Anuluj
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Ostrze¿enie: tworzenie okna dialogowego nie powiod³o siê, wiêc praca aplikacji zosta³a nieoczekiwanie przerwana.\n");
		TRACE(traceAppMsg, 0, "Ostrze¿enie: jeœli u¿ywasz kontrolek MFC w oknie dialogowym, nie mo¿esz u¿yæ instrukcji #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Usuñ mened¿era pow³oki utworzonego powy¿ej.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Poniewa¿ okno dialogowe zosta³o zamkniête, zwróæ wartoœæ FALSE, aby zakoñczyæ
	//  aplikacjê zamiast uruchomiæ pompê komunikatów aplikacji.
	return FALSE;
}

