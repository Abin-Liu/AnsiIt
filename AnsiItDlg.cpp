// AnsiItDlg.cpp : implementation file
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
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnsiItDlg dialog

CAnsiItDlg::CAnsiItDlg()
	: CDialog(CAnsiItDlg::IDD, NULL)
{
	//{{AFX_DATA_INIT(CAnsiItDlg)
	m_bStructual = FALSE;
	m_bUnicode = FALSE;
	m_sInput = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnsiItDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnsiItDlg)
	DDX_Control(pDX, IDC_OUTPUT, m_wndOutput);
	DDX_Control(pDX, IDC_INPUT, m_wndInput);
	DDX_Check(pDX, IDC_STRUCTUAL, m_bStructual);
	DDX_Check(pDX, IDC_UNICODE, m_bUnicode);
	DDX_Text(pDX, IDC_INPUT, m_sInput);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAnsiItDlg, CDialog)
	//{{AFX_MSG_MAP(CAnsiItDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CONVERT, OnConvert)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnsiItDlg message handlers

BOOL CAnsiItDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAnsiItDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAnsiItDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

void CAnsiItDlg::OnConvert() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	const int LEN = m_sInput.GetLength();
	CString sText = m_bStructual ? _T("{ ") : _T("_T(\"");
	CString sTemp;
	if (m_bUnicode)
	{		
		// unicode
		LPWORD psz = new WORD[LEN];
		int nResult = ::MultiByteToWideChar(CP_ACP, 0, m_sInput, LEN, (LPWSTR)psz, LEN);
		for (int i = 0; i < nResult; i++)
		{
			sTemp.Format(m_bStructual ? _T("0x%04x, ") : _T("\\x%04x"), psz[i]);
			sText += sTemp;
		}
		delete [] psz;
	}
	else
	{
		// mbcs
		for (int i = 0; i < LEN; i++)
		{
			sTemp.Format(m_bStructual ? _T("0x%02x, ") : _T("\\x%02x"), (BYTE)m_sInput[i]);
			sText += sTemp;
		}		
	}

	sText += m_bStructual ? _T("0 }") : _T("\")");	
	m_wndOutput.SetWindowText(sText);
}
