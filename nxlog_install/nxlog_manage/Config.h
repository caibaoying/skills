#pragma once

#include <iostream>
#include <stdlib.h>
#include "System_Type.h"
#include "common.h"

using namespace std;

struct Move_Log_Type
{
	int DownList_X;
	int DownList_Y;
	int text_x;
	int text_y;
	int Button_X;
	int Button_Y;
};
Move_Log_Type MLT[5];

// 优化，结构体数组
struct Manage_Info
{
	string System_Info = "";   //系统日志
	string Conf_Info = "";     //配置文件地址
	string Type_Info1 = "";    // 第一行的中间件日志
	string Dir_Info1 = "";     // 对应日志路径
	string Type_Info2 = "";
	string Dir_Info2 = "";
	string Type_Info3 = "";
	string Dir_Info3 = "";
	string Type_Info4 = "";
	string Dir_Info4 = "";
	string Type_Info5 = "";
	string Dir_Info5 = "";
	string Type_Info6 = "";
	string Dir_Info6 = "";
	string IP_Info = "";   // server端的IP
	string Client_IP = ""; // 客户端的IP
	string Client_ID = ""; // 客户端的编号

	bool Open_VBS = true;
	string System_VBS = "";

	// 标记下拉列表是否有选择
	bool System_Is_Select = false;
	bool Type1_Is_Select = false;
	bool Type2_Is_Select = false;
	bool Type3_Is_Select = false;
	bool Type4_Is_Select = false;
	bool Type5_Is_Select = false;
	bool Type6_Is_Select = false;

	//判断系统字符集
	int ANSI_CODE = -1;
};

Manage_Info Manage;

FILE* Open_File()
{
	FILE *fp;
	errno_t err;
	err = fopen_s(&fp, "test.txt", "a+");
	//如果成功返回0
	if (0 != err)
	{
		return NULL;
	}

	////fseek
	//fputs(textdata, Open_File());

	//// 添加换行，文件写会覆盖掉前一次写入的内容
	//// fputchar 被替代为 _fputchar
	//_fputchar('\n');
	return fp;
}

void Config_Path_Method(string& Conf_Path)
{
	//判断nxlog.conf存在不存在
	FILE *fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "C:\\Program Files (x86)\\nxlog\\README.txt", "r");
	//如果成功返回0
	if (0 != err)
	{
		err = fopen_s(&fp, "C:\\Program Files\\nxlog\\README.txt", "r");
		if (0 != err)
		{
			Conf_Path = "open file error";
		}
		else
		{
			fclose(fp);
			Conf_Path = "C:\\Program Files\\nxlog\\conf\\nxlog.conf";
		}
	}
	else  // X86目录存在
	{
		fclose(fp);
		Conf_Path = "C:\\Program Files (x86)\\nxlog\\conf\\nxlog.conf";
	}
}

// 修改配置文件
bool Write_Config()
{
	FILE *fp = NULL;
	errno_t err;
	// BUG 不能以写的方式打开文件，权限的问题（以管理员身份运行）；或者添加管理员依据
	if (Manage.Conf_Info != "open file error" && Manage.Conf_Info != "")
		err = fopen_s(&fp, Manage.Conf_Info.c_str(), "w");
	else
		printf("文件不存在，nxlog未安装\n");
	//如果成功返回0
	if (0 != err)
	{
		return false;
	}
	
	if (Manage.Conf_Info == "C:\\Program Files\\nxlog\\conf\\nxlog.conf")
	{
		fputs("define ROOT C:\\\\Program Files\\\\nxlog\n\n", fp);
	}
	else if (Manage.Conf_Info == "C:\\Program Files (x86)\\nxlog\\conf\\nxlog.conf")
	{
		fputs("define ROOT C:\\\\Program Files (x86)\\\\nxlog\n\n", fp);
	}

	fputs("Moduledir %ROOT%\\\\modules\n", fp);
	fputs("CacheDir %ROOT%\\\\data\n", fp);
	fputs("Pidfile %ROOT%\\\\data\\\\nxlog.pid\n", fp);
	fputs("SpoolDir %ROOT%\\\\data\n", fp);
	fputs("LogFile %ROOT%\\\\data\\\\nxlog.log\n\n", fp);

	fputs("<Extension _syslog>\n", fp);
	fputs("    Module      xm_syslog\n", fp);
	fputs("</Extension>\n\n", fp);

	//计划任务
	if (Manage.Open_VBS == true)
	{
		fputs("<Extension exec>\n", fp);
		fputs("    Module          xm_exec\n", fp);
		fputs("    <Schedule>\n", fp);
		fputs("       Every        30 sec\n", fp);
		fputs("       Exec         exec_async(\"", fp);
		if (Manage.Conf_Info.find("Program Files (x86)"))
		{
			fputs("%ROOT%\\\\collect\\\\collect.bat", fp);
		}
		else if (Manage.Conf_Info.find("Program Files"))
		{
			fputs("%ROOT%\\\\collect\\\\collect.bat", fp);
		}

		fputs("\");\n", fp);
		fputs("    </Schedule>\n", fp);
		fputs("</Extension>\n\n", fp);
	}
	////////////////////////////////////////

	fputs("<Input in>\n", fp);
	CString strOSVersion = "", strServerVersion = "";
	Get_OS_Version(strOSVersion, strServerVersion);

	string str1 = (string)strOSVersion;
	string str2 = (string)strServerVersion;

	//if (Manage.System_Info == "windows server 2003" || Manage.System_Info == "")
	// 默认选择windows server 2003
	if (str1.find("Windows Server 2003") != string::npos)
	{
		fputs("    Module      im_mseventlog\n", fp);
	}
	else    // 08及其他
	{
		fputs("    Module      im_msvistalog\n", fp);
	}

	fputs("    Exec        $raw_event = \"0\" + \" \" + \"0\" + \" \" + \"", fp);
	fputs(Manage.Client_ID.c_str(), fp);
	fputs("\" + \" \" + $EventTime + \" \" + host_ip() + \" \" +$Message;\n", fp);
	fputs("</Input>\n\n", fp);

	if (Manage.Open_VBS == true)
	{
		// result 文件信息
		fputs("<Input in2>\n", fp);
		fputs("    Module      im_file\n", fp);
		fputs("    File        \"%ROOT%\\\\collect\\\\result.txt\"\n", fp);
		//fputs("    Exec	       convert_fields(\"GB2312\", \"utf-8\"", fp);
		fputs("    Exec        $raw_event = \"0\" + \" \" + \"1\" + \" \"+ \"", fp);
		fputs(Manage.Client_ID.c_str(), fp);
		fputs("\" + \" \" + now() + \" \" + host_ip() + \" \" + $raw_event;\n", fp);
		fputs("    Exec        if size($raw_event) > 1472 $raw_event=substr($raw_event,0,1472);\n", fp);
		fputs("</Input>\n\n", fp);
	}

	fputs("<Extension charconv>\n", fp);
	fputs("    Module       xm_charconv\n", fp);
	fputs("    AutodetectCharsets gbk, utf-8, euc-jp, utf-16, utf-32, iso8859-2, GB2312\n", fp);
	fputs("</Extension>\n\n", fp);

	fputs("<Output out>\n", fp);
	fputs("    Module      om_udp\n", fp);

	if (Manage.IP_Info == "默认匹配" || Manage.IP_Info == "" || Manage.IP_Info == "default" || Manage.Type1_Is_Select == false)
	{
		// 默认IP地址
		fputs("    Host        192.168.161.103\n", fp);
	}
	else if(Manage.IP_Info == "不发送到接收端" || Manage.IP_Info == "Not sent to the log receiver")
	{
		fputs("    Host        127.0.0.1\n", fp);
	}
	else 
	{
		//自己输入
		fputs("    Host        ", fp);
		fputs(Manage.IP_Info.c_str(), fp);
		fputc('\n', fp);
	}
	
	fputs("    Port        514\n", fp);
	fputs("</Output>\n\n", fp);

	fputs("<Route 1>\n", fp);
	fputs("    Path        in => out\n", fp);
	fputs("</Route>\n\n", fp);

	if (Manage.Open_VBS == true)
	{
		fputs("<Route 2>\n", fp);
		fputs("    Path        in2 => out\n", fp);
		fputs("</Route>\n\n", fp);
	}

	/*// Find_File_From_Dir， 根据给定的目录确定当前文件下的具体的日志文件
	vector<string> Files1, Files2, Files3, Files4, Files5, Files6;
	Find_File_From_Dir(Manage.Dir_Info1, Files1);
	Find_File_From_Dir(Manage.Dir_Info2, Files2);
	Find_File_From_Dir(Manage.Dir_Info3, Files3);
	Find_File_From_Dir(Manage.Dir_Info4, Files4);
	Find_File_From_Dir(Manage.Dir_Info5, Files5);
	Find_File_From_Dir(Manage.Dir_Info6, Files6);*/

	/*int Flag_index = 50;
	vector<string> Files = Files1;
	vector<string>::iterator iter_begin = Files.begin();
	vector<string>::iterator iter_end = Files.end();	
	Path_to_Config1(iter_begin, iter_end, &fp, Flag_index);

	Files = Files2;
	if (!Files.empty())
	{
		iter_begin = Files.begin();
		iter_end = Files.end();
		Path_to_Config1(iter_begin, iter_end, &fp, Flag_index);
	}

	Files = Files3;
	if (!Files.empty())
	{
		iter_begin = Files.begin();
		iter_end = Files.end();
		Path_to_Config1(iter_begin, iter_end, &fp, Flag_index);
	}

	Files = Files4;
	if (!Files.empty())
	{
		iter_begin = Files.begin();
		iter_end = Files.end();
		Path_to_Config1(iter_begin, iter_end, &fp, Flag_index);
	}

	Files = Files5;
	if (!Files.empty())
	{
		iter_begin = Files.begin();
		iter_end = Files.end();
		Path_to_Config1(iter_begin, iter_end, &fp, Flag_index);
	}
	
	Files = Files6;
	if (!Files.empty())
	{
		iter_begin = Files.begin();
		iter_end = Files.end();
		Path_to_Config1(iter_begin, iter_end, &fp, Flag_index);
	}*/
	
	int Flag_index = 50;
	if (!Manage.Dir_Info1.empty())
		Path_To_Config(&fp, Manage.Dir_Info1, Flag_index, Manage.Client_ID);
	if (!Manage.Dir_Info2.empty())
		Path_To_Config(&fp, Manage.Dir_Info2, Flag_index, Manage.Client_ID);
	if (!Manage.Dir_Info3.empty())
		Path_To_Config(&fp, Manage.Dir_Info3, Flag_index, Manage.Client_ID);
	if (!Manage.Dir_Info4.empty())
		Path_To_Config(&fp, Manage.Dir_Info4, Flag_index, Manage.Client_ID);
	if (!Manage.Dir_Info5.empty())
		Path_To_Config(&fp, Manage.Dir_Info5, Flag_index, Manage.Client_ID);
	if (!Manage.Dir_Info6.empty())
		Path_To_Config(&fp, Manage.Dir_Info6, Flag_index, Manage.Client_ID);

	fputs("", fp);
	fputs("", fp);

	fclose(fp);
	return true;
}
