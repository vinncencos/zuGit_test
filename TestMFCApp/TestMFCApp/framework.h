#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Wyklucz rzadko u¿ywane rzeczy z nag³ówków systemu Windows
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // niektóre konstruktory CString bêd¹ jawne

// wy³¹cza ukrywanie przez bibliotekê MFC niektórych wspólnych i czêsto bezpiecznie ignorowanych komunikatów ostrzegawczych
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // standardowe i rdzenne sk³adniki MFC
#include <afxext.h>         // Rozszerzenia MFC


#include <afxdisp.h>        // Klasy automatyzacji MFC



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Obs³uga MFC dla Formantów standardowych programu Internet Explorer 4
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Obs³uga MFC dla Formantów standardowych systemu Windows
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // Obs³uga przez bibliotekê MFC wst¹¿ek i pasków sterowania









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


