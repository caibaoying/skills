#pragma once


// New_Form �Ի���

class New_Form : public CDialogEx
{
	DECLARE_DYNAMIC(New_Form)

public:
	New_Form(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~New_Form();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
