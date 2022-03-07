
// TestMFCAppDlg.h: plik nag³ówkowy
//

#pragma once


// okno dialogowe CTestMFCAppDlg
class CTestMFCAppDlg : public CDialogEx
{
// Konstrukcja
public:
	CTestMFCAppDlg(CWnd* pParent = nullptr);	// konstruktor standardowy

// Dane okna dialogowego
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTMFCAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// obs³uga DDX/DDV


// Implementacja
protected:
	HICON m_hIcon;

	// Wygenerowano funkcje mapy komunikatów
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
