// CCDesktop.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCCDesktopApp:
// �йش����ʵ�֣������ CCDesktop.cpp
//

class CCCDesktopApp : public CWinApp
{
public:
	CCCDesktopApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCCDesktopApp theApp;