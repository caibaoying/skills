
// add_passwd.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cadd_passwdApp: 
// �йش����ʵ�֣������ add_passwd.cpp
//

class Cadd_passwdApp : public CWinApp
{
public:
	Cadd_passwdApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cadd_passwdApp theApp;