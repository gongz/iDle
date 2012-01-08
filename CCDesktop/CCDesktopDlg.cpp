// CCDesktopDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CCDesktop.h"
#include "CCDesktopDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCCDesktopDlg 对话框




CCCDesktopDlg::CCCDesktopDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCCDesktopDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCCDesktopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOCKWAVEFLASH1, m_Flash);
}

BEGIN_MESSAGE_MAP(CCCDesktopDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CCCDesktopDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCCDesktopDlg 消息处理程序

BOOL CCCDesktopDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	initFlashStage();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCCDesktopDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCCDesktopDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCCDesktopDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCCDesktopDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

////////////////////////////////////////////
//////////以下是我们的代码//////////////////
////////////////////////////////////////////


////初始化主体flash界面
////091116 created by 成文迪
////091116 updated by 成文迪
void CCCDesktopDlg::initFlashStage()
{
	//设置窗口透明度 
	BYTE m_bgR = 236;
	BYTE m_bgG = 233;
	BYTE m_bgB = 216;

	long formstyle = GetWindowLong(m_hWnd, GWL_EXSTYLE);
	SetWindowLong(m_hWnd,GWL_EXSTYLE, formstyle | WS_EX_LAYERED);
	SetLayeredWindowAttributes(/*GetSysColor( COLOR_3DFACE )*/RGB(m_bgR,m_bgG,m_bgB), 255, LWA_COLORKEY | LWA_ALPHA);
	ModifyStyleEx(WS_EX_APPWINDOW,WS_EX_TOOLWINDOW, SWP_DRAWFRAME);
	
	m_Flash.put_BackgroundColor(RGB(m_bgR,m_bgG,m_bgB));

	//读取flash文件
	CString strFlashFile; 
     GetCurrentDirectory(MAX_PATH,strFlashFile.GetBuffer(MAX_PATH)); 
     strFlashFile.ReleaseBuffer(); 
	 strFlashFile += "\\res\\try2.swf";
	


	//读取flash文件并开始播放
	m_Flash.LoadMovie(0,strFlashFile);
	m_Flash.Play();

	//设置系统托盘图标
	m_ni.cbSize = sizeof(NOTIFYICONDATA);
	m_ni.hWnd = GetSafeHwnd();
	m_ni.uFlags = NIF_MESSAGE|NIF_INFO|NIF_ICON;
	
	m_ni.uID = 123;
	m_ni.hIcon = LoadIcon(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDR_MAINFRAME));
	m_ni.dwInfoFlags = NIIF_INFO;
	//strcpy(m_ni.szTip,"HelloFlash"); 
	//_tcscpy(m_ni.szInfoTitle, "I'm Strike1");
	//_tcscpy(m_ni.szInfo, "Welcome!\r\nFlashTest_Beta1 By Strike1 \r\nClick Here For Exit^ ^");
	Shell_NotifyIcon(NIM_ADD, &m_ni);
	//设置窗口位置
	SetWindowPos(&CWnd::wndTopMost, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);

}