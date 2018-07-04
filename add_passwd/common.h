#pragma once

#include <iostream>
using namespace std;

#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <Windows.h>
#include <cstring>
#include <atlbase.h>
#include "stdafx.h"

// 修改注册表

LPCTSTR Is64Bit_OS()
{
	bool ret = FALSE;
	typedef VOID(WINAPI *LPFN_GetNativeSystemInfo)(__out LPSYSTEM_INFO lpSystemInfo);
	LPFN_GetNativeSystemInfo fnGetNativeSystemInfo = (LPFN_GetNativeSystemInfo)GetProcAddress(GetModuleHandleW(L"kernel32"), "GetNativeSystemInfo");
	if (fnGetNativeSystemInfo)
	{
		SYSTEM_INFO stInfo = { 0 };
		fnGetNativeSystemInfo(&stInfo);
		if (stInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64
			|| stInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
		{
			ret = TRUE;
		}
	}

	LPCTSTR rege_path = NULL;
	if (ret == TRUE)
	{
		rege_path = _T("SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall");
	}
	else if (ret == FALSE)
	{
		rege_path = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall");
	}

	return rege_path;
}

void read_dword()//读取操作表,其类型为DWORD  
{

	HKEY hKEY;//定义有关的键，在查询结束时关闭  
			  //打开与路径data_Set相关的hKEY  

	//LPCTSTR data_set = _T("Software\\Chicony\\Lenovo1");  

	LPCTSTR data_set = Is64Bit_OS();  


	//访问注册表，hKEY则保存此函数所打开的键的句柄  
	int tmp = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, data_set, 0, KEY_WOW64_64KEY | KEY_READ, &hKEY);
	if (ERROR_SUCCESS)
	{
		DWORD dwValue;//长整型数据，如果是字符串数据用char数组  
		DWORD dwSize = sizeof(DWORD);
		DWORD dwType = REG_DWORD;

		if (::RegQueryValueEx(hKEY, _T("123"), 0, &dwType, (LPBYTE)&dwValue, &dwSize) != ERROR_SUCCESS)
		{
			cout << "错误：无法查询有关的注册表信息" << endl;
		}

		cout << dwValue << endl;
	}
	::RegCloseKey(hKEY);
}

void read_reg_sz()//读取操作表,其类型为REG_SZ  
{
	HKEY hkey;
	//LPCTSTR data_set = _T("Software\\Chicony\\Lenovo1");
	LPCTSTR data_set = Is64Bit_OS();

	if (ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_CURRENT_USER, data_set, 0, KEY_READ, &hkey))
	{
		char dwValue[256];
		DWORD dwSzType = REG_SZ;
		DWORD dwSize = sizeof(dwValue);
		if (::RegQueryValueEx(hkey, _T("wangchong"), 0, &dwSzType, (LPBYTE)&dwValue, &dwSize) != ERROR_SUCCESS)
		{
			cout << "无法查询有关的注册表信息" << endl;
		}
		cout << dwValue << endl;
	}
	::RegCloseKey(hkey);
}

void write_dword()//在\Software\\Chicony\\Lenovo1文件夹下写入一个test111的子键，设置其名称为Name，其值为6  
{
	HKEY hkey;//定义有关的hkey，在查询结束时要关闭  
	HKEY hTempKey;

	DWORD dwValue = 6;
	DWORD dwSize = sizeof(DWORD);
	DWORD dwType = REG_DWORD;

	//LPCTSTR data_set = _T("Software\\Chicony\\Lenovo1");
	LPCTSTR data_set = Is64Bit_OS();

	if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_CURRENT_USER, data_set, 0, KEY_SET_VALUE, &hkey))
	{
		if (ERROR_SUCCESS == ::RegCreateKey(hkey, _T("test111"), &hTempKey))
		{
			if (ERROR_SUCCESS != ::RegSetValueEx(hTempKey, _T("Name"), 0, REG_DWORD, (CONST BYTE*)&dwValue, sizeof(DWORD)))
			{
				cout << "写入注册表失败" << endl;
			}
		}
	}
	::RegCloseKey(hkey);
}

void write_reg_sz()
{
	HKEY hkey;
	HKEY hTempKey;
	char m_name_set[256] = "China";

	DWORD len = strlen(m_name_set) + 1;
	/*LPCTSTR data_set = _T("Software\\Chicony\\Lenovo1");*/
	LPCTSTR data_set = Is64Bit_OS();
	if (ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_CURRENT_USER, data_set, 0, KEY_SET_VALUE, &hkey))
	{
		if (ERROR_SUCCESS == ::RegCreateKey(hkey, _T("test1112"), &hTempKey))
		{
			if (ERROR_SUCCESS != ::RegSetValueEx(hTempKey, _T("Name"), 0, REG_SZ, (const BYTE*)m_name_set, len))
			{
				cout << "写入错误" << endl;
			}
		}
	}
	::RegCloseKey(hkey);
}

void write_binary()
{
	HKEY hkey;
	HKEY hTempKey;
	BYTE m_name[1] = {0};
	m_name[0] = 0x00;

	/*LPCTSTR data_set = _T("Software\\Chicony\\Lenovo1");*/
	LPCTSTR data_set = Is64Bit_OS();
	if (ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, data_set, 0, KEY_SET_VALUE, &hkey))
	{
		// 用来创建或打开注册表项
		if (ERROR_SUCCESS == ::RegCreateKey(hkey, _T("{BBCA9D02-13B8-4CC8-BC04-752073EFDF2A}"), &hTempKey))
		{
			if (ERROR_SUCCESS != ::RegSetValueEx(hTempKey, _T("UninstallString"), 0, REG_SZ, (const BYTE*)m_name, 50))
			{
				cout << "写入错误" << endl;
			}
		}
	}
	::RegCloseKey(hkey);
}

void delete_value()
{
	HKEY hkey;
	/*LPCTSTR data_set = _T("Software\\Chicony\\Lenovo1\\test1112");*/
	LPCTSTR data_set = Is64Bit_OS();

	if (ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_CURRENT_USER, data_set, 0, KEY_SET_VALUE, &hkey))
	{
		if (ERROR_SUCCESS != ::RegDeleteValue(hkey, _T("Name")))
		{
			cout << "删除错误" << endl;
		}
	}
	::RegCloseKey(hkey);
}

void delete_key()
{
	HKEY hkey;
	/*LPCTSTR data_set = _T("Software\\Chicony\\Lenovo1");*/
	LPCTSTR data_set = Is64Bit_OS();

	if (ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_CURRENT_USER, data_set, 0, KEY_SET_VALUE, &hkey))
	{
		if (ERROR_SUCCESS != ::RegDeleteKey(hkey, "test1112"))
		{
			cout << "删除错误" << endl;
		}
	}
	::RegCloseKey(hkey);
}

