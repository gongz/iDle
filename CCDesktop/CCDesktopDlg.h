// CCDesktopDlg.h : ͷ�ļ�
//

#pragma once
#include "shockwaveflash1.h"


// CCCDesktopDlg �Ի���
class CCCDesktopDlg : public CDialog
{
// ����
public:
	CCCDesktopDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CCDESKTOP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	// ����flash�ؼ�
	CShockwaveflash1 m_Flash;
	//��С��ͼ�����
	NOTIFYICONDATA m_ni;
	
	//��ʼ������flash����
	void initFlashStage();
};
