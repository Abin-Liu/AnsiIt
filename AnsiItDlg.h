// AnsiItDlg.h : header file
//

#if !defined(AFX_ANSIITDLG_H__08E42CD6_AF03_44DE_A959_5C07EBA4B5EA__INCLUDED_)
#define AFX_ANSIITDLG_H__08E42CD6_AF03_44DE_A959_5C07EBA4B5EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EditEx.h"

/////////////////////////////////////////////////////////////////////////////
// CAnsiItDlg dialog

class CAnsiItDlg : public CDialog
{
// Construction
public:
	CAnsiItDlg();	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAnsiItDlg)
	enum { IDD = IDD_ANSIIT_DIALOG };
	CEditEx	m_wndOutput;
	CEditEx	m_wndInput;
	BOOL	m_bStructual;
	BOOL	m_bUnicode;
	CString	m_sInput;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnsiItDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAnsiItDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnConvert();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANSIITDLG_H__08E42CD6_AF03_44DE_A959_5C07EBA4B5EA__INCLUDED_)
