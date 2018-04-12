#pragma execution_character_set("utf-8")
// nxlog_managerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "nxlog_manager.h"
#include "nxlog_managerDlg.h"
#include "afxdialogex.h"
#include "Config.h"
#include "Resource.h"
#include "System_Type.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static int flag = 0;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cnxlog_managerDlg 对话框



Cnxlog_managerDlg::Cnxlog_managerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NXLOG_MANAGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void Cnxlog_managerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, System_list);
	DDX_Control(pDX, IDC_COMBO2, Log_Type);
	DDX_Control(pDX, IDC_EDIT1, Dir_Edit);
	DDX_Control(pDX, IDC_BUTTON1, Add_Other_Type);
	DDX_Control(pDX, IDC_COMBO3, Log_Type2);
	DDX_Control(pDX, IDC_EDIT2, Edit_Log2);
	DDX_Control(pDX, IDC_BUTTON3, Open_File1);
	DDX_Control(pDX, IDC_BUTTON4, Open_File2);
	DDX_Control(pDX, IDC_COMBO4, Log_Type3);
	DDX_Control(pDX, IDC_COMBO5, Log_Type4);
	DDX_Control(pDX, IDC_COMBO6, Log_Type5);
	DDX_Control(pDX, IDC_COMBO7, Log_Type6);
	DDX_Control(pDX, IDC_BUTTON5, Open_File3);
	DDX_Control(pDX, IDC_BUTTON6, Open_File4);
	DDX_Control(pDX, IDC_BUTTON7, Open_File5);
	DDX_Control(pDX, IDC_BUTTON8, Open_File6);
	DDX_Control(pDX, IDC_EDIT4, Edit_Log3);
	DDX_Control(pDX, IDC_EDIT3, Edit_Log4);
	DDX_Control(pDX, IDC_EDIT5, Edit_Log5);
	DDX_Control(pDX, IDC_EDIT6, Edit_Log6);
	DDX_Control(pDX, IDC_COMBO8, Server_Ip);
	DDX_Control(pDX, IDC_COMBO9, System_Info);
}

BEGIN_MESSAGE_MAP(Cnxlog_managerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &Cnxlog_managerDlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Cnxlog_managerDlg::OnCbnSelchangeCombo2)
	ON_EN_CHANGE(IDC_EDIT1, &Cnxlog_managerDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &Cnxlog_managerDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO3, &Cnxlog_managerDlg::OnCbnSelchangeCombo3)
	ON_EN_CHANGE(IDC_EDIT2, &Cnxlog_managerDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &Cnxlog_managerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &Cnxlog_managerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cnxlog_managerDlg::OnBnClickedButton4)
	ON_CBN_SELCHANGE(IDC_COMBO4, &Cnxlog_managerDlg::OnCbnSelchangeCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO5, &Cnxlog_managerDlg::OnCbnSelchangeCombo5)
	ON_CBN_SELCHANGE(IDC_COMBO6, &Cnxlog_managerDlg::OnCbnSelchangeCombo6)
	ON_CBN_SELCHANGE(IDC_COMBO7, &Cnxlog_managerDlg::OnCbnSelchangeCombo7)
	ON_BN_CLICKED(IDC_BUTTON5, &Cnxlog_managerDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Cnxlog_managerDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Cnxlog_managerDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Cnxlog_managerDlg::OnBnClickedButton8)
	ON_EN_CHANGE(IDC_EDIT4, &Cnxlog_managerDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT3, &Cnxlog_managerDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT5, &Cnxlog_managerDlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &Cnxlog_managerDlg::OnEnChangeEdit6)
	ON_CBN_SELCHANGE(IDC_COMBO8, &Cnxlog_managerDlg::OnCbnSelchangeCombo8)
	ON_CBN_SELCHANGE(IDC_COMBO9, &Cnxlog_managerDlg::OnCbnSelchangeCombo9)
END_MESSAGE_MAP()


// Cnxlog_managerDlg 消息处理程序

BOOL Cnxlog_managerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid = true;
		CString strAboutMenu = "";
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	Manage.ANSI_CODE = GetACP();

	//中文简体
	if (Manage.ANSI_CODE == 936 || Manage.ANSI_CODE == 950)
	{
		//添加下拉列表系统主机信息的罗列
		System_list.AddString(_T("自动匹配"));
		System_list.AddString(_T("windows server 2003"));
		System_list.AddString(_T("windows server 2008"));
		System_list.AddString(_T("windows server 2012"));
		//System_list.AddString(_T("windows server 2016"));
		// 默认选择第一项        
		System_list.SetCurSel(0);

		Log_Type.AddString(_T("tomcat"));
		Log_Type.AddString(_T("weblogic"));
		Log_Type.AddString(_T("websphere"));
		Log_Type.AddString(_T("jboss"));
		Log_Type.AddString(_T("apache"));
		Log_Type.SetCurSel(0);
		Manage.Type_Info1 = "apache";
		//
		Log_Type2.AddString(_T("tomcat"));
		Log_Type2.AddString(_T("weblogic"));
		Log_Type2.AddString(_T("websphere"));
		Log_Type2.AddString(_T("jboss"));
		Log_Type2.AddString(_T("apache"));
		Log_Type2.SetCurSel(0);
		Manage.Type_Info2 = "apache";

		Log_Type3.AddString(_T("tomcat"));
		Log_Type3.AddString(_T("weblogic"));
		Log_Type3.AddString(_T("websphere"));
		Log_Type3.AddString(_T("jboss"));
		Log_Type3.AddString(_T("apache"));
		Log_Type3.SetCurSel(0);
		Manage.Type_Info3 = "apache";

		Log_Type4.AddString(_T("tomcat"));
		Log_Type4.AddString(_T("weblogic"));
		Log_Type4.AddString(_T("websphere"));
		Log_Type4.AddString(_T("jboss"));
		Log_Type4.AddString(_T("apache"));
		Log_Type4.SetCurSel(0);
		Manage.Type_Info4 = "apache";

		Log_Type5.AddString(_T("tomcat"));
		Log_Type5.AddString(_T("weblogic"));
		Log_Type5.AddString(_T("websphere"));
		Log_Type5.AddString(_T("jboss"));
		Log_Type5.AddString(_T("apache"));
		Log_Type5.SetCurSel(0);
		Manage.Type_Info5 = "apache";

		Log_Type6.AddString(_T("tomcat"));
		Log_Type6.AddString(_T("weblogic"));
		Log_Type6.AddString(_T("websphere"));
		Log_Type6.AddString(_T("jboss"));
		Log_Type6.AddString(_T("apache"));
		Log_Type6.SetCurSel(0);
		Manage.Type_Info6 = "apache";

		Server_Ip.AddString(_T("默认匹配"));
		Server_Ip.AddString(_T("不发送到接收端"));
		Server_Ip.AddString(_T("请在文本框输入IP地址"));
		Server_Ip.SetCurSel(0);

		System_Info.AddString(_T("是"));
		System_Info.AddString(_T("否"));
		System_Info.SetCurSel(0);
	}
	else {
		//添加下拉列表系统主机信息的罗列
		System_list.AddString(_T("default match"));
		System_list.AddString(_T("windows server 2003"));
		System_list.AddString(_T("windows server 2008"));
		System_list.AddString(_T("windows server 2012"));
		//System_list.AddString(_T("windows server 2016"));
		// 默认选择第一项        
		System_list.SetCurSel(0);

		Log_Type.AddString(_T("tomcat"));
		Log_Type.AddString(_T("weblogic"));
		Log_Type.AddString(_T("websphere"));
		Log_Type.AddString(_T("jboss"));
		Log_Type.AddString(_T("apache"));
		Log_Type.SetCurSel(0);
		Manage.Type_Info1 = "apache";
		//
		Log_Type2.AddString(_T("tomcat"));
		Log_Type2.AddString(_T("weblogic"));
		Log_Type2.AddString(_T("websphere"));
		Log_Type2.AddString(_T("jboss"));
		Log_Type2.AddString(_T("apache"));
		Log_Type2.SetCurSel(0);
		Manage.Type_Info2 = "apache";

		Log_Type3.AddString(_T("tomcat"));
		Log_Type3.AddString(_T("weblogic"));
		Log_Type3.AddString(_T("websphere"));
		Log_Type3.AddString(_T("jboss"));
		Log_Type3.AddString(_T("apache"));
		Log_Type3.SetCurSel(0);
		Manage.Type_Info3 = "apache";

		Log_Type4.AddString(_T("tomcat"));
		Log_Type4.AddString(_T("weblogic"));
		Log_Type4.AddString(_T("websphere"));
		Log_Type4.AddString(_T("jboss"));
		Log_Type4.AddString(_T("apache"));
		Log_Type4.SetCurSel(0);
		Manage.Type_Info4 = "apache";

		Log_Type5.AddString(_T("tomcat"));
		Log_Type5.AddString(_T("weblogic"));
		Log_Type5.AddString(_T("websphere"));
		Log_Type5.AddString(_T("jboss"));
		Log_Type5.AddString(_T("apache"));
		Log_Type5.SetCurSel(0);
		Manage.Type_Info5 = "apache";

		Log_Type6.AddString(_T("tomcat"));
		Log_Type6.AddString(_T("weblogic"));
		Log_Type6.AddString(_T("websphere"));
		Log_Type6.AddString(_T("jboss"));
		Log_Type6.AddString(_T("apache"));
		Log_Type6.SetCurSel(0);
		Manage.Type_Info6 = "apache";

		Server_Ip.AddString(_T("default"));
		Server_Ip.AddString(_T("Not sent to the log receiver"));
		Server_Ip.AddString(_T("Please enter Ip address"));
		Server_Ip.SetCurSel(0);

		System_Info.AddString(_T("YES"));
		System_Info.AddString(_T("NO"));
		System_Info.SetCurSel(0);

		GetDlgItem(IDC_BUTTON3)->SetWindowText("open");
		GetDlgItem(IDC_BUTTON1)->SetWindowText("add log types");
		GetDlgItem(IDC_BUTTON4)->SetWindowText("open");
		GetDlgItem(IDC_BUTTON5)->SetWindowText("open");
		GetDlgItem(IDC_BUTTON6)->SetWindowText("open");
		GetDlgItem(IDC_BUTTON7)->SetWindowText("open");
		GetDlgItem(IDC_BUTTON8)->SetWindowText("open");
		GetDlgItem(IDOK)->SetWindowText("determine");
		GetDlgItem(IDCANCEL)->SetWindowText("cancel");
		GetDlgItem(IDC_STATIC_TEXT1)->SetWindowText("Log_receiver_IP");
		GetDlgItem(IDC_STATIC_TEXT2)->SetWindowText("collect system information");
		GetDlgItem(IDC_STATIC_TEXT3)->SetWindowText("Host system type");
		GetDlgItem(IDC_STATIC_TEXT4)->SetWindowText("Log type");
		GetDlgItem(IDC_STATIC_TEXT5)->SetWindowText("Log path");
		::SetWindowTextA(m_hWnd, (LPCSTR)"nxlog management --axtx");
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cnxlog_managerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cnxlog_managerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);    //获取对话框长宽      
		CDC   dcBmp;             //定义并创建一个内存设备环境
		dcBmp.CreateCompatibleDC(&dc);             //创建兼容性DC
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP1);    //载入资源中图片
		BITMAP   m_bitmap;                         //图片变量               
		bmpBackground.GetBitmap(&m_bitmap);       //将图片载入位图中
												  //将位图选入临时内存设备环境
		CBitmap  *pbmpOld = dcBmp.SelectObject(&bmpBackground);
		//调用函数显示图片StretchBlt显示形状可变
		dc.StretchBlt(0, 0, 249, rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	}
		//CDialogEx::OnPaint();
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cnxlog_managerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//区分操作系统
void Cnxlog_managerDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString textdata;
	int nSel;
	CString selected;
	// 获取组合框控件的列表框中选中项的索引   
	nSel = System_list.GetCurSel();
	// 根据选中项索引获取该项字符串
	System_list.GetLBText(nSel, textdata);
	// 将组合框中选中的字符串显示到IDC_SEL_WEB_EDIT编辑框中   
	SetDlgItemText(IDC_COMBO1, textdata);
	Manage.System_Info = string(textdata);
	Manage.Type1_Is_Select = true;
}

void Cnxlog_managerDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSel;
	CString textdata;
	// 获取组合框控件的列表框中选中项的索引   
	nSel = Log_Type.GetCurSel();
	// 根据选中项索引获取该项字符串   
	Log_Type.GetLBText(nSel, textdata);
	// 将组合框中选中的字符串显示到IDC_SEL_WEB_EDIT编辑框中   
	SetDlgItemText(IDC_COMBO1, textdata);
	
	Manage.Type_Info1 = string(textdata);
}

void Cnxlog_managerDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cnxlog_managerDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	flag++;
	if (flag == 1)
	{
		CRect rect_button, rect_DropDown, rect_Text, rect_Open;
		GetDlgItem(IDC_BUTTON1)->GetWindowRect(&rect_button);//获得空间的绝对坐标
		ScreenToClient(&rect_button);//获得相对于主窗体的坐标
		rect_button.OffsetRect(CSize(0, 40));//这里要是要移动的相对位置
		GetDlgItem(IDC_BUTTON1)->MoveWindow(rect_button);//移动到目标位置

		GetDlgItem(IDC_COMBO3)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -40));
		GetDlgItem(IDC_COMBO3)->MoveWindow(rect_button);

		GetDlgItem(IDC_EDIT2)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -40));
		GetDlgItem(IDC_EDIT2)->MoveWindow(rect_button);

		GetDlgItem(IDC_BUTTON4)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -40));
		GetDlgItem(IDC_BUTTON4)->MoveWindow(rect_button);

		// 将隐藏的组件显示
		GetDlgItem(IDC_COMBO3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_SHOW);
	}
	
	if (flag == 2)
	{
		CRect rect_button, rect_DropDown, rect_Text, rect_Open;
		GetDlgItem(IDC_BUTTON1)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, 50));
		GetDlgItem(IDC_BUTTON1)->MoveWindow(rect_button);

		GetDlgItem(IDC_COMBO4)->GetWindowRect(&rect_button);//获得空间的绝对坐标
		ScreenToClient(&rect_button);//获得相对于主窗体的坐标
		rect_button.OffsetRect(CSize(0, -50));//这里要是要移动的相对位置
		GetDlgItem(IDC_COMBO4)->MoveWindow(rect_button);//移动到目标位置

		GetDlgItem(IDC_EDIT3)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -50));
		GetDlgItem(IDC_EDIT3)->MoveWindow(rect_button);

		GetDlgItem(IDC_BUTTON5)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -50));
		GetDlgItem(IDC_BUTTON5)->MoveWindow(rect_button);

		GetDlgItem(IDC_COMBO4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON5)->ShowWindow(SW_SHOW);
	}
	
	if (flag == 3)
	{
		CRect rect_button, rect_DropDown, rect_Text, rect_Open;
		GetDlgItem(IDC_BUTTON1)->GetWindowRect(&rect_button);//获得空间的绝对坐标
		ScreenToClient(&rect_button);//获得相对于主窗体的坐标
		rect_button.OffsetRect(CSize(0, 50));//这里要是要移动的相对位置
		GetDlgItem(IDC_BUTTON1)->MoveWindow(rect_button);//移动到目标位置

		GetDlgItem(IDC_COMBO5)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -50));
		GetDlgItem(IDC_COMBO5)->MoveWindow(rect_button);

		GetDlgItem(IDC_EDIT4)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -50));
		GetDlgItem(IDC_EDIT4)->MoveWindow(rect_button);

		GetDlgItem(IDC_BUTTON6)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -50));
		GetDlgItem(IDC_BUTTON6)->MoveWindow(rect_button);

		GetDlgItem(IDC_COMBO5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON6)->ShowWindow(SW_SHOW);
	}
	
	if (flag == 4)
	{
		CRect rect_button, rect_DropDown, rect_Text, rect_Open;
		GetDlgItem(IDC_BUTTON1)->GetWindowRect(&rect_button);//获得空间的绝对坐标
		ScreenToClient(&rect_button);//获得相对于主窗体的坐标
		rect_button.OffsetRect(CSize(0, 50));//这里要是要移动的相对位置
		GetDlgItem(IDC_BUTTON1)->MoveWindow(rect_button);//移动到目标位置

		GetDlgItem(IDC_COMBO6)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -50));
		GetDlgItem(IDC_COMBO6)->MoveWindow(rect_button);

		GetDlgItem(IDC_EDIT5)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -50));
		GetDlgItem(IDC_EDIT5)->MoveWindow(rect_button);

		GetDlgItem(IDC_BUTTON7)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -50));
		GetDlgItem(IDC_BUTTON7)->MoveWindow(rect_button);

		GetDlgItem(IDC_COMBO6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON7)->ShowWindow(SW_SHOW);
	}
	
	if (flag == 5)
	{

		CRect rect_button, rect_DropDown, rect_Text, rect_Open;
		GetDlgItem(IDC_BUTTON1)->GetWindowRect(&rect_button);//获得空间的绝对坐标
		ScreenToClient(&rect_button);//获得相对于主窗体的坐标
		rect_button.OffsetRect(CSize(0, 50));//这里要是要移动的相对位置
		GetDlgItem(IDC_BUTTON1)->MoveWindow(rect_button);//移动到目标位置
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);


		GetDlgItem(IDC_COMBO7)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -50));
		GetDlgItem(IDC_COMBO7)->MoveWindow(rect_button);

		GetDlgItem(IDC_EDIT6)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -50));
		GetDlgItem(IDC_EDIT6)->MoveWindow(rect_button);

		GetDlgItem(IDC_BUTTON8)->GetWindowRect(&rect_button);
		ScreenToClient(&rect_button);
		rect_button.OffsetRect(CSize(0, -50));
		GetDlgItem(IDC_BUTTON8)->MoveWindow(rect_button);

		GetDlgItem(IDC_COMBO7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON8)->ShowWindow(SW_SHOW);
	}
	
}


void Cnxlog_managerDlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSel;
	CString textdata;
	// 获取组合框控件的列表框中选中项的索引   
	nSel = Log_Type.GetCurSel();
	// 根据选中项索引获取该项字符串   
	Log_Type.GetLBText(nSel, textdata);
	// 将组合框中选中的字符串显示到IDC_SEL_WEB_EDIT编辑框中   
	SetDlgItemText(IDC_COMBO1, textdata);
	Manage.Type_Info2 = string(textdata);

	Manage.Type2_Is_Select = true;
}


void Cnxlog_managerDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cnxlog_managerDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取配置文件路径
	FILE* fp = NULL;
	string Conf_Path = "";
	Config_Path_Method(Conf_Path);
	// 返回nxlog配置文件路径
	if ("" == Conf_Path)
	{
		printf("nxlog未安装");
	}
	else if ("open file error" == Conf_Path)
	{
		// TODO: 配置文件打开失败，发出警告
		return;
	}
	Manage.Conf_Info = string(Conf_Path);

	CString Text_Str1;
	GetDlgItem(IDC_EDIT1)->GetWindowText(Text_Str1);
	Manage.Dir_Info1 = Text_Str1;

	CString Text_Str2;
	GetDlgItem(IDC_EDIT2)->GetWindowText(Text_Str2);
	Manage.Dir_Info2 = Text_Str2;

	CString Text_Str3;
	GetDlgItem(IDC_EDIT3)->GetWindowText(Text_Str3);
	Manage.Dir_Info3 = Text_Str3;

	CString Text_Str4;
	GetDlgItem(IDC_EDIT4)->GetWindowText(Text_Str4);
	Manage.Dir_Info4 = Text_Str4;

	CString Text_Str5;
	GetDlgItem(IDC_EDIT5)->GetWindowText(Text_Str5);
	Manage.Dir_Info5 = Text_Str5;

	CString Text_Str6;
	GetDlgItem(IDC_EDIT6)->GetWindowText(Text_Str6);
	Manage.Dir_Info6 = Text_Str6;

	CString IP;
	GetDlgItem(IDC_COMBO8)->GetWindowText(IP);
	Manage.IP_Info = IP;

	CString Open_VBS = "";
	GetDlgItem(IDC_COMBO9)->GetWindowText(Open_VBS);
	if (Open_VBS == "是" || Open_VBS == "" || Open_VBS == "YES")
	{
		Manage.Open_VBS = true;
	}
	else
	{
		Manage.Open_VBS = false;
	}

	string Client_IP = "";
	string Client_ID = "";
	Read_File(Client_IP, Client_ID);
	Manage.Client_ID = Client_ID;
	Manage.Client_IP = Client_IP;

	CDialogEx::OnOK();

	// 修改文件
	Write_Config();
	system("net stop nxlog");
	system("net start nxlog");
}


void Cnxlog_managerDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString gReadFilePathName;
	//CFileDialog fileDlg(true, _T("All"), _T("*.log"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("log Files (*.log)|*.log|All File (*.*)|*.*||"), NULL);
	//if (fileDlg.DoModal() == IDOK)    //弹出对话框  
	//{
	//	gReadFilePathName = fileDlg.GetPathName();//得到完整的文件名和目录名拓展名  
	//	GetDlgItem(IDC_EDIT1)->SetWindowText(gReadFilePathName);//将路径显示  
	//	CString filename = fileDlg.GetFileName();
	//}

	char szPath[MAX_PATH];     //存放选择的目录路径   
	CString Dir_Path = "";

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	if (Manage.ANSI_CODE == 936 || Manage.ANSI_CODE == 950)
	{
		bi.lpszTitle = "请选择日志所在目录：";
	}
	else
		bi.lpszTitle = "Please select the directory where the log is located :";

	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//弹出选择目录对话框  
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);

	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		Dir_Path.Format(szPath);
		//AfxMessageBox(Dir_Path);
	}
	/*else
		AfxMessageBox("无效的目录，请重新选择");*/

	GetDlgItem(IDC_EDIT1)->SetWindowText(Dir_Path);//将路径显示  
}

void Cnxlog_managerDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString gReadFilePathName;
	//CFileDialog fileDlg(true, _T("All"), _T("*.log"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("log Files (*.log)|*.log|All File (*.*)|*.*||"), NULL);
	//if (fileDlg.DoModal() == IDOK)    //弹出对话框  
	//{
	//	gReadFilePathName = fileDlg.GetPathName();//得到完整的文件名和目录名拓展名  
	//	GetDlgItem(IDC_EDIT2)->SetWindowText(gReadFilePathName);//将路径显示  
	//	CString filename = fileDlg.GetFileName();
	//}

	char szPath[MAX_PATH];     //存放选择的目录路径   
	CString Dir_Path = "";

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	if (Manage.ANSI_CODE == 936 || Manage.ANSI_CODE == 950)
	{
		bi.lpszTitle = "请选择日志所在目录：";
	}
	else
		bi.lpszTitle = "Please select the directory where the log is located :";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//弹出选择目录对话框  
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);

	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		Dir_Path.Format(szPath);
		//AfxMessageBox(Dir_Path);
	}
	/*else
		AfxMessageBox("无效的目录，请重新选择");*/

	GetDlgItem(IDC_EDIT2)->SetWindowText(Dir_Path);   //将路径显示  
}


void Cnxlog_managerDlg::OnCbnSelchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSel;
	CString textdata = "";
	// 获取组合框控件的列表框中选中项的索引   
	nSel = Log_Type.GetCurSel();
	// 根据选中项索引获取该项字符串   
	Log_Type.GetLBText(nSel, textdata);
	// 将组合框中选中的字符串显示到IDC_SEL_WEB_EDIT编辑框中   
	SetDlgItemText(IDC_COMBO1, textdata);

	Manage.Type_Info3 = string(textdata);
	Manage.Type3_Is_Select = true;
}

void Cnxlog_managerDlg::OnCbnSelchangeCombo5()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSel;
	CString textdata;
	// 获取组合框控件的列表框中选中项的索引   
	nSel = Log_Type.GetCurSel();
	// 根据选中项索引获取该项字符串   
	Log_Type.GetLBText(nSel, textdata);
	// 将组合框中选中的字符串显示到IDC_SEL_WEB_EDIT编辑框中   
	SetDlgItemText(IDC_COMBO1, textdata);

	Manage.Type_Info4 = string(textdata);
	Manage.Type4_Is_Select = true;
}




void Cnxlog_managerDlg::OnCbnSelchangeCombo6()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSel;
	CString textdata = "";
	// 获取组合框控件的列表框中选中项的索引   
	nSel = Log_Type.GetCurSel();
	// 根据选中项索引获取该项字符串   
	Log_Type.GetLBText(nSel, textdata);
	// 将组合框中选中的字符串显示到IDC_SEL_WEB_EDIT编辑框中   
	SetDlgItemText(IDC_COMBO1, textdata);

	Manage.Type_Info5 = string(textdata);
	Manage.Type5_Is_Select = true;
}


void Cnxlog_managerDlg::OnCbnSelchangeCombo7()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSel;
	CString textdata = "";
	// 获取组合框控件的列表框中选中项的索引   
	nSel = Log_Type.GetCurSel();
	// 根据选中项索引获取该项字符串   
	Log_Type.GetLBText(nSel, textdata);
	// 将组合框中选中的字符串显示到IDC_SEL_WEB_EDIT编辑框中   
	SetDlgItemText(IDC_COMBO1, textdata);

	Manage.Type_Info6 = string(textdata);
	Manage.Type6_Is_Select = true;
}


void Cnxlog_managerDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString gReadFilePathName;
	//CFileDialog fileDlg(true, _T("All"), _T("*.log"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("log Files (*.log)|*.log|All File (*.*)|*.*||"), NULL);
	//if (fileDlg.DoModal() == IDOK)    //弹出对话框  
	//{
	//	gReadFilePathName = fileDlg.GetPathName();//得到完整的文件名和目录名拓展名  
	//	GetDlgItem(IDC_EDIT2)->SetWindowText(gReadFilePathName);//将路径显示  
	//	CString filename = fileDlg.GetFileName();
	//}

	char szPath[MAX_PATH];     //存放选择的目录路径   
	CString Dir_Path = "";

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	if (Manage.ANSI_CODE == 936 || Manage.ANSI_CODE == 950)
	{
		bi.lpszTitle = "请选择日志所在目录：";
	}
	else
		bi.lpszTitle = "Please select the directory where the log is located :";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//弹出选择目录对话框  
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);

	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		Dir_Path.Format(szPath);
		//AfxMessageBox(Dir_Path);
	}
	/*else
		AfxMessageBox("无效的目录，请重新选择");*/

	GetDlgItem(IDC_EDIT4)->SetWindowText(Dir_Path);//将路径显示  
}


void Cnxlog_managerDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString gReadFilePathName;
	//CFileDialog fileDlg(true, _T("All"), _T("*.log"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("log Files (*.log)|*.log|All File (*.*)|*.*||"), NULL);
	//if (fileDlg.DoModal() == IDOK)    //弹出对话框  
	//{
	//	gReadFilePathName = fileDlg.GetPathName();//得到完整的文件名和目录名拓展名  
	//	GetDlgItem(IDC_EDIT2)->SetWindowText(gReadFilePathName);//将路径显示  
	//	CString filename = fileDlg.GetFileName();
	//}

	char szPath[MAX_PATH];     //存放选择的目录路径   
	CString Dir_Path = "";

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	if (Manage.ANSI_CODE == 936 || Manage.ANSI_CODE == 950)
	{
		bi.lpszTitle = "请选择日志所在目录：";
	}
	else
		bi.lpszTitle = "Please select the directory where the log is located :";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//弹出选择目录对话框  
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);

	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		Dir_Path.Format(szPath);
		//AfxMessageBox(Dir_Path);
	}
	/*else
		AfxMessageBox("无效的目录，请重新选择");*/

	GetDlgItem(IDC_EDIT3)->SetWindowText(Dir_Path);//将路径显示  
}


void Cnxlog_managerDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString gReadFilePathName;
	//CFileDialog fileDlg(true, _T("All"), _T("*.log"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("log Files (*.log)|*.log|All File (*.*)|*.*||"), NULL);
	//if (fileDlg.DoModal() == IDOK)    //弹出对话框  
	//{
	//	gReadFilePathName = fileDlg.GetPathName();//得到完整的文件名和目录名拓展名  
	//	GetDlgItem(IDC_EDIT2)->SetWindowText(gReadFilePathName);//将路径显示  
	//	CString filename = fileDlg.GetFileName();
	//}

	char szPath[MAX_PATH];     //存放选择的目录路径   
	CString Dir_Path = "";

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	if (Manage.ANSI_CODE == 936 || Manage.ANSI_CODE == 950)
	{
		bi.lpszTitle = "请选择日志所在目录：";
	}
	else
		bi.lpszTitle = "Please select the directory where the log is located :";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//弹出选择目录对话框  
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);

	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		Dir_Path.Format(szPath);
		//AfxMessageBox(Dir_Path);
	}
	/*else
		AfxMessageBox("无效的目录，请重新选择");*/

	GetDlgItem(IDC_EDIT5)->SetWindowText(Dir_Path);//将路径显示  
}


void Cnxlog_managerDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString gReadFilePathName;
	//CFileDialog fileDlg(true, _T("All"), _T("*.log"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("log Files (*.log)|*.log|All File (*.*)|*.*||"), NULL);
	//if (fileDlg.DoModal() == IDOK)    //弹出对话框  
	//{
	//	gReadFilePathName = fileDlg.GetPathName();//得到完整的文件名和目录名拓展名  
	//	GetDlgItem(IDC_EDIT2)->SetWindowText(gReadFilePathName);//将路径显示  
	//	CString filename = fileDlg.GetFileName();
	//}

	char szPath[MAX_PATH];     //存放选择的目录路径   
	CString Dir_Path = "";

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	if (Manage.ANSI_CODE == 936 || Manage.ANSI_CODE == 950)
	{
		bi.lpszTitle = "请选择日志所在目录：";
	}
	else
		bi.lpszTitle = "Please select the directory where the log is located :";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//弹出选择目录对话框  
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);

	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		Dir_Path.Format(szPath);
		//AfxMessageBox(Dir_Path);
	}
	/*else
		AfxMessageBox("无效的目录，请重新选择");*/

	GetDlgItem(IDC_EDIT6)->SetWindowText(Dir_Path);//将路径显示  
}


void Cnxlog_managerDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cnxlog_managerDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cnxlog_managerDlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cnxlog_managerDlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cnxlog_managerDlg::OnCbnSelchangeCombo8()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSel;
	CString textdata = "";
	// 获取组合框控件的列表框中选中项的索引   
	nSel = Log_Type.GetCurSel();
	// 根据选中项索引获取该项字符串   
	Log_Type.GetLBText(nSel, textdata);
	// 将组合框中选中的字符串显示到IDC_SEL_WEB_EDIT编辑框中   
	SetDlgItemText(IDC_COMBO8, textdata);

	Manage.IP_Info = string(textdata);
	Manage.Type1_Is_Select = true;
}


void Cnxlog_managerDlg::OnCbnSelchangeCombo9()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSel;
	CString textdata = "";
	// 获取组合框控件的列表框中选中项的索引   
	nSel = Log_Type.GetCurSel(); 
	// 根据选中项索引获取该项字符串 
	Log_Type.GetLBText(nSel, textdata);
	// 将组合框中选中的字符串显示到IDC_SEL_WEB_EDIT编辑框中   
	SetDlgItemText(IDC_COMBO9, textdata);

	Manage.System_VBS = string(textdata);
	Manage.Open_VBS = true;
}

