// AnsiIt.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "AnsiIt.h"
#include "AnsiItDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnsiItApp

BEGIN_MESSAGE_MAP(CAnsiItApp, CWinApp)
	//{{AFX_MSG_MAP(CAnsiItApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnsiItApp construction

CAnsiItApp::CAnsiItApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CAnsiItApp object

CAnsiItApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CAnsiItApp initialization

BOOL CAnsiItApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	SetRegistryKey(_T("Abin"));

	CAnsiItDlg dlg;
	dlg.m_bUnicode = GetProfileInt(_T(""), _T("Unicode"), FALSE);
	dlg.m_bStructual = GetProfileInt(_T(""), _T("Structual"), FALSE);
	dlg.m_sInput = GetProfileString(_T(""), _T("Input"));

	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	WriteProfileInt(_T(""), _T("Unicode"), dlg.m_bUnicode);
	WriteProfileInt(_T(""), _T("Structual"), dlg.m_bStructual);
	WriteProfileString(_T(""), _T("Input"), dlg.m_sInput);	
	return FALSE;
}
