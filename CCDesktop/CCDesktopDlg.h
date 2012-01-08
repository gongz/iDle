// CCDesktopDlg.h : 头文件
//

#pragma once
#include "shockwaveflash1.h"


// CCCDesktopDlg 对话框
class CCCDesktopDlg : public CDialog
{
// 构造
public:
	CCCDesktopDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CCDESKTOP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	// 主体flash控件
	CShockwaveflash1 m_Flash;
	//最小化图标控制
	NOTIFYICONDATA m_ni;
	
	//初始化主体flash界面
	void initFlashStage();
};
