
// nxlog_manager.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cnxlog_managerApp: 
// �йش����ʵ�֣������ nxlog_manager.cpp
//

class Cnxlog_managerApp : public CWinApp
{
public:
	Cnxlog_managerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cnxlog_managerApp theApp;