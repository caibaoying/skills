
// nxlog_managerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// Cnxlog_managerDlg 对话框
class Cnxlog_managerDlg : public CDialogEx
{
// 构造
public:
	Cnxlog_managerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NXLOG_MANAGER_DIALOG };
#endif

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
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox System_list;
	CComboBox Log_Type;
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnEnChangeEdit1();
	CEdit Dir_Edit;
	CButton Add_Other_Type;
	afx_msg void OnBnClickedButton1();
	CComboBox Log_Type2;
	CEdit Edit_Log2;
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
	CButton Open_File1;
	afx_msg void OnBnClickedButton4();
	CButton Open_File2;
	CComboBox Log_Type3;
	CComboBox Log_Type4;
	CComboBox Log_Type5;
	CComboBox Log_Type6;
	CButton Open_File3;
	CButton Open_File4;
	CButton Open_File5;
	CButton Open_File6;
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnCbnSelchangeCombo5();
	afx_msg void OnCbnSelchangeCombo6();
	afx_msg void OnCbnSelchangeCombo7();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	CEdit Edit_Log3;
	CEdit Edit_Log4;
	CEdit Edit_Log5;
	CEdit Edit_Log6;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnCbnSelchangeCombo8();
	CComboBox Server_Ip;
	afx_msg void OnCbnSelchangeCombo9();
	CComboBox System_Info;
};
