
// setup_mfc.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Csetup_mfcApp: 
// �йش����ʵ�֣������ setup_mfc.cpp
//

class Csetup_mfcApp : public CWinApp
{
public:
	Csetup_mfcApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Csetup_mfcApp theApp;