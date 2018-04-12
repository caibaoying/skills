#pragma once

#include <iostream>
#include <stdlib.h>
#include <afxtempl.h>
#include "stdafx.h"

using namespace std;
#pragma warning(disable: 4996)

void Get_OS_Version(CString& strOSVersion, CString& strServiceVersion)
{
	CString str = "";
	OSVERSIONINFOEX osvi;
	SYSTEM_INFO si;
	BOOL bOsVersionInfoEx;

	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));

	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	if (!(bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO *)&osvi)))
	{
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	    GetVersionEx((OSVERSIONINFO *)&osvi);
	}


	GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")),
		"GetNativeSystemInfo");

	GetSystemInfo(&si);
	switch (osvi.dwPlatformId)
	{
	case VER_PLATFORM_WIN32_NT:
		if (osvi.dwMajorVersion == 10 && osvi.dwMinorVersion == 0)
		{
			if (osvi.wProductType == VER_NT_WORKSTATION)
			{
				str.Format(_T("Windows 10 "));
			}
			else
			{
				str.Format(_T("Windows Server 2016 "));
			}
		}

		if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 3)
		{
			if (osvi.wProductType == VER_NT_WORKSTATION)
			{
				str.Format(_T("Windows 8.1 "));
			}
			else
			{
				str.Format(_T("Windows Server 2012 R2"));
			}
		}

		if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 2)
		{
			if (osvi.wProductType == VER_NT_WORKSTATION)
			{
				str.Format(_T("Windows 8 "));
			}
			else
			{
				str.Format(_T("Windows Server 2012 "));
			}
		}

		if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 1)
		{
			if (osvi.wProductType == VER_NT_WORKSTATION)
			{
				str.Format(_T("Windows 7"));
			}
			else
			{
				str.Format(_T("Windows Server 2008 R2"));
			}
		}

		if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 0)
		{
			if (osvi.wProductType == VER_NT_WORKSTATION)
			{
				str.Format(_T("Windows Vista "));
			}
			else
			{
				str.Format(_T("Windows Server 2008 "));
			}
		}

		if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2)
		{
			if (GetSystemMetrics(SM_SERVERR2))
			{
				str.Format(_T("Microsoft Windows Server 2003 R2 "));
			}
			else if (osvi.wProductType == VER_NT_WORKSTATION &&
				si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
			{
				str.Format(_T("Microsoft Windows XP Professional x64 Edition "));
			}
			else
			{
				str.Format(_T("Microsoft Windows Server 2003 "));
			}
		}

		if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1)
		{
			str.Format(_T("Microsoft Windows XP "));
		}

		if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0)
			str.Format(_T("Microsoft Windows 2000 "));

		if (osvi.dwMajorVersion <= 4)
		{
			str.Format(_T("Microsoft Windows NT "));
		}

		// Test for specific product on Windows NT 4.0 SP6 and later.
		if (bOsVersionInfoEx)
		{

			//½«Service Pack °æ±¾±£´æ
			strServiceVersion.Format(_T("Service Pack %d"), osvi.wServicePackMajor);

			// Test for the workstation type.
			if (osvi.wProductType == VER_NT_WORKSTATION &&
				si.wProcessorArchitecture != PROCESSOR_ARCHITECTURE_AMD64)
			{
				if (osvi.dwMajorVersion == 4)
					str = str + _T("Workstation 4.0");
				else if (osvi.wSuiteMask & VER_SUITE_PERSONAL)
					str = str + _T("Home Edition");
				else str = str + _T("Professional");
			}

			// Test for the server type.
			else if (osvi.wProductType == VER_NT_SERVER ||
				osvi.wProductType == VER_NT_DOMAIN_CONTROLLER)
			{
				if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2)
				{
					if (si.wProcessorArchitecture ==
						PROCESSOR_ARCHITECTURE_IA64)
					{
						if (osvi.wSuiteMask & VER_SUITE_DATACENTER)
							str = str + _T("Datacenter Edition for Itanium-based Systems");
						else if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE)
							str = str + _T("Enterprise Edition for Itanium-based Systems");
					}

					else if (si.wProcessorArchitecture ==
						PROCESSOR_ARCHITECTURE_AMD64)
					{
						if (osvi.wSuiteMask & VER_SUITE_DATACENTER)
							str = str + _T("Datacenter x64 Edition ");
						else if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE)
							str = str + _T("Enterprise x64 Edition ");
						else str = str + _T("Standard x64 Edition ");
					}

					else
					{
						if (osvi.wSuiteMask & VER_SUITE_DATACENTER)
							str = str + _T("Datacenter Edition ");
						else if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE)
							str = str + _T("Enterprise Edition ");
						else if (osvi.wSuiteMask & VER_SUITE_BLADE)
							str = str + _T("Web Edition ");
						else str = str + _T("Standard Edition ");
					}
				}
				else if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0)
				{
					if (osvi.wSuiteMask & VER_SUITE_DATACENTER)
						str = str + _T("Datacenter Server ");
					else if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE)
						str = str + _T("Advanced Server ");
					else str = str + _T("Server ");
				}
				else  // Windows NT 4.0
				{
					if (osvi.wSuiteMask & VER_SUITE_ENTERPRISE)
						str = str + _T("Server 4.0, Enterprise Edition ");
					else str = str + _T("Server 4.0 ");
				}
			}
		}
		// Test for specific product on Windows NT 4.0 SP5 and earlier
		else
		{
			HKEY hKey;
			TCHAR szProductType[256];
			DWORD dwBufLen = 256 * sizeof(TCHAR);
			LONG lRet;

			lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
				_T("SYSTEM\\CurrentControlSet\\Control\\ProductOptions"), 0, KEY_QUERY_VALUE, &hKey);
			if (lRet != ERROR_SUCCESS)
				strOSVersion = str;
			return;

			lRet = RegQueryValueEx(hKey, TEXT("ProductType"),
				NULL, NULL, (LPBYTE)szProductType, &dwBufLen);
			RegCloseKey(hKey);

			if ((lRet != ERROR_SUCCESS) ||
				(dwBufLen > 256 * sizeof(TCHAR)))
				strOSVersion = str;
			return;

			if (lstrcmpi(TEXT("WINNT"), szProductType) == 0)
				str = str + _T("Workstation ");
			if (lstrcmpi(TEXT("LANMANNT"), szProductType) == 0)
				str = str + _T("Server ");
			if (lstrcmpi(TEXT("SERVERNT"), szProductType) == 0)
				str = str + _T("Advanced Server ");
			str.Format(_T("%d.%d "), osvi.dwMajorVersion, osvi.dwMinorVersion);
		}

		// Display service pack (if any) and build number.

		if (osvi.dwMajorVersion == 4 &&
			lstrcmpi(osvi.szCSDVersion, TEXT("Service Pack 6")) == 0)
		{
			HKEY hKey;
			LONG lRet;

			// Test for SP6 versus SP6a.
			lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
				_T("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Hotfix\\Q246009"), 0, KEY_QUERY_VALUE, &hKey);
			if (lRet == ERROR_SUCCESS)
				str.Format(_T("Service Pack 6a (Build %d)\n"),
					osvi.dwBuildNumber & 0xFFFF);
			else // Windows NT 4.0 prior to SP6a
			{
				_tprintf(TEXT("%s (Build %d)\n"),
					osvi.szCSDVersion,
					osvi.dwBuildNumber & 0xFFFF);
			}

			RegCloseKey(hKey);
		}
		else // not Windows NT 4.0
		{
			_tprintf(TEXT("%s (Build %d)\n"),
				osvi.szCSDVersion,
				osvi.dwBuildNumber & 0xFFFF);
		}

		break;

		// Test for the Windows Me/98/95.
	case VER_PLATFORM_WIN32_WINDOWS:

		if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 0)
		{
			str.Format(_T("Microsoft Windows 95 "));
			if (osvi.szCSDVersion[1] == 'C' || osvi.szCSDVersion[1] == 'B')
				str = str + _T("OSR2 ");
		}

		if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 10)
		{
			str.Format(_T("Microsoft Windows 98 "));
			if (osvi.szCSDVersion[1] == 'A' || osvi.szCSDVersion[1] == 'B')
				str = str + _T("SE ");
		}
		if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 90)
		{
			str.Format(_T("Microsoft Windows Millennium Edition\n"));
		}
		break;

	case VER_PLATFORM_WIN32s:
		str.Format(_T("Microsoft Win32s\n"));
		break;
	default:
		break;
	}

	strOSVersion = str;
}

