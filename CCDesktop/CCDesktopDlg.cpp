// CCDesktopDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CCDesktop.h"
#include "CCDesktopDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCCDesktopDlg �Ի���




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


// CCCDesktopDlg ��Ϣ�������

BOOL CCCDesktopDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	initFlashStage();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCCDesktopDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCCDesktopDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCCDesktopDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

////////////////////////////////////////////
//////////���������ǵĴ���//////////////////
////////////////////////////////////////////


////��ʼ������flash����
////091116 created by ���ĵ�
////091116 updated by ���ĵ�
void CCCDesktopDlg::initFlashStage()
{
	//���ô���͸���� 
	BYTE m_bgR = 236;
	BYTE m_bgG = 233;
	BYTE m_bgB = 216;

	long formstyle = GetWindowLong(m_hWnd, GWL_EXSTYLE);
	SetWindowLong(m_hWnd,GWL_EXSTYLE, formstyle | WS_EX_LAYERED);
	SetLayeredWindowAttributes(/*GetSysColor( COLOR_3DFACE )*/RGB(m_bgR,m_bgG,m_bgB), 255, LWA_COLORKEY | LWA_ALPHA);
	ModifyStyleEx(WS_EX_APPWINDOW,WS_EX_TOOLWINDOW, SWP_DRAWFRAME);
	
	m_Flash.put_BackgroundColor(RGB(m_bgR,m_bgG,m_bgB));

	//��ȡflash�ļ�
	CString strFlashFile; 
     GetCurrentDirectory(MAX_PATH,strFlashFile.GetBuffer(MAX_PATH)); 
     strFlashFile.ReleaseBuffer(); 
	 strFlashFile += "\\res\\try2.swf";
	


	//��ȡflash�ļ�����ʼ����
	m_Flash.LoadMovie(0,strFlashFile);
	m_Flash.Play();

	//����ϵͳ����ͼ��
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
	//���ô���λ��
	SetWindowPos(&CWnd::wndTopMost, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);

}