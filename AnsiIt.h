// AnsiIt.h : main header file for the ANSIIT application
//

#if !defined(AFX_ANSIIT_H__175734A5_C380_4CCE_8DAE_B40FEC9DC0B6__INCLUDED_)
#define AFX_ANSIIT_H__175734A5_C380_4CCE_8DAE_B40FEC9DC0B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAnsiItApp:
// See AnsiIt.cpp for the implementation of this class
//

class CAnsiItApp : public CWinApp
{
public:
	CAnsiItApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnsiItApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAnsiItApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANSIIT_H__175734A5_C380_4CCE_8DAE_B40FEC9DC0B6__INCLUDED_)
