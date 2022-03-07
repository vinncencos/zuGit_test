
// TestMFCAppDlg.cpp: plik implementacji
//

#include "pch.h"
#include "framework.h"
#include "TestMFCApp.h"
#include "TestMFCAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Okno dialogowe CAboutDlg u¿ywane na potrzeby informacji o aplikacji

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dane okna dialogowego
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // obs³uga DDX/DDV

// Implementacja
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// okno dialogowe CTestMFCAppDlg



CTestMFCAppDlg::CTestMFCAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTMFCAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMFCAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestMFCAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// Procedury obs³ugi komunikatów CTestMFCAppDlg

BOOL CTestMFCAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Dodaj pozycjê „Informacje...” do menu systemowego.

	// Element IDM_ABOUTBOX musi nale¿eæ do zakresu poleceñ systemowych.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Ustaw ikonê dla tego okna dialogowego. Struktura wykonuje to automatycznie
	//  gdy okno g³ówne aplikacji nie jest oknem dialogowym
	SetIcon(m_hIcon, TRUE);			// Ustaw du¿e ikony
	SetIcon(m_hIcon, FALSE);		// Ustaw ma³e ikony

	// TODO: Dodaj tutaj dodatkowe inicjowanie

	return TRUE;  // zwracaj wartoœæ TRUE, dopóki fokus nie zostanie ustawiony na formant
}

void CTestMFCAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Jeœli dodasz przycisk minimalizacji do okna dialogowego, bêdziesz potrzebowaæ poni¿szego kodu
//  aby narysowaæ ikonê. Dla aplikacji MFC u¿ywaj¹cych modelu dokumentu/widoku
//  to jest wykonywane automatycznie przez strukturê.

void CTestMFCAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // kontekst urz¹dzenia dotycz¹cy malowania

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Wyœrodkuj ikonê w prostok¹cie klienta
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Rysuj ikonê
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// System wywo³uje tê funkcjê, aby uzyskaæ kursor wyœwietlany podczas przeci¹gania przez u¿ytkownika
//  zminimalizowane okno.
HCURSOR CTestMFCAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

