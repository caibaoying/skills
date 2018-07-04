// New_Form.cpp : 实现文件
//

#include "stdafx.h"
#include "add_passwd.h"
#include "New_Form.h"
#include "afxdialogex.h"


// New_Form 对话框

IMPLEMENT_DYNAMIC(New_Form, CDialogEx)

New_Form::New_Form(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

New_Form::~New_Form()
{
}

void New_Form::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(New_Form, CDialogEx)
END_MESSAGE_MAP()


// New_Form 消息处理程序
