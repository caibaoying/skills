#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <direct.h>           // ����_chdir����
#include <string.h>
#include "unistd.h"
#include "common.h"

using namespace std;


// ����Ŀ¼�µ������ļ���������Ŀ¼
void Find_File_From_Dir(string mainDir, vector<string> &files)
{
	files.clear();
	const char *dir = mainDir.c_str();
	_chdir(dir);
	long hFile;

	//Ϊȫ�ֱ���������һ�ξ͵����
	_finddata_t fileinfo;

	// *.* ��ʾ�������ļ�
	if (((hFile = _findfirst("*.log", &fileinfo)) != -1) && mainDir != "")
	{
		do 
		{
			if (!(fileinfo.attrib & _A_SUBDIR))//�ҵ��ļ�  
			{
				char filename[_MAX_PATH];
				strcpy_s(filename, dir); 
				strcat_s(filename, "\\");
				strcat_s(filename, fileinfo.name);
				string temfilename = filename;
				files.push_back(temfilename);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

//void Path_to_Config1(vector<string>::iterator iter_begin, vector<string>::iterator iter_end, FILE** fp, int& Flag_index)
//{
//	char buffer[100];
//	for (int _index = 0; iter_begin != iter_end; iter_begin++, _index++)
//	{
//		fputs("<Input file", *fp);
//		itoa(Flag_index, buffer, 10);
//		fputs( buffer, *fp);
//		fputs(">\n", *fp);
//		fputs("    Module      im_file\n", *fp);
//		fputs("    File        ", *fp);
//		fputs((*iter_begin).c_str(), *fp);
//		fputc('\n', *fp);
//		fputs("    Exec        convert_fields(\"GB2312\", \"utf-8\");\n", *fp);
//		fputs("    Exec        $raw_event = now() + \" \" + host_ip() + \" \" + \"0\" + \" \" + \"1\" + \" \" + $raw_event;\n", *fp);
//		fputs("</Input>\n\n", *fp);
//
//		fputs("<Route ", *fp);
//		itoa(Flag_index+1, buffer, 10);
//		fputs(buffer, *fp);
//		fputs(">\n",* fp);
//		fputs("    Path        file", *fp);
//		fputs(buffer, *fp);
//		fputs(" => out\n", *fp);
//		fputs("</Route>\n\n", *fp);
//		Flag_index++;
//	}
//}

void Path_To_Config(FILE** fp, string Str_Path, int& Flag_index, string ID)
{
	char buffer_file[100], buffer_route[100];
	if (NULL == fp)
	{
		return;
	}
	itoa(Flag_index, buffer_file, 10);
	fputs("define PATH", *fp);
	fputs(buffer_file, *fp);
	fputs(" ", *fp);
	//����б�ܱ�Ϊ˫б��
	string tmp = "";
	int index = 0;
	while (Str_Path[index] != '\0')
	{
		tmp += Str_Path[index];
		if (Str_Path[index] == '\\')
		{
			tmp += '\\';
		}
		index++;
	}
	fputs(tmp.c_str(), *fp);
	fputc('\n', *fp);
	fputs("<Input file", *fp);
	
	fputs(buffer_file, *fp);
	fputs(">\n", *fp);
	fputs("    Module      im_file\n", *fp);
	fputs("    File        \"", *fp);

	fputs("%PATH", *fp);
	fputs(buffer_file, *fp);
	
	fputs("%\\\\\\\*.log\"", *fp);
	fputc('\n', *fp);
	fputs("    Exec        convert_fields(\"GB2312\", \"utf-8\");\n", *fp);
	fputs("    Exec        $raw_event = \"0\" + \" \" + \"2\" + \" \" + \"", *fp);
	fputs(ID.c_str(), *fp);
	fputs("\" + \" \" + now() + \" \" + host_ip() + \" \" + $raw_event;\n", *fp);
	fputs("    Exec        if size($raw_event) > 1472 $raw_event=substr($raw_event,0,1472);\n", *fp);
	fputs("</Input>\n\n", *fp);
	
	fputs("<Route ", *fp);
	itoa(Flag_index+1, buffer_route, 10);
	fputs(buffer_route, *fp);
	fputs(">\n",* fp);
	fputs("    Path        file", *fp);
	fputs(buffer_file, *fp);
	fputs(" => out\n", *fp);
	fputs("</Route>\n\n", *fp);
	Flag_index++;
}

void Read_File(string& Client_IP, string& Client_ID)
{
	/*FILE* fp = NULL;
	errno_t err = fopen_s(&fp, "..\\test\\test.txt", "r");
	if (err != 0)
		return;
	char IP_Buffer[100], ID_Buffer[100];
	Client_IP = fgets(IP_Buffer, 50, fp);
	Client_ID = fgets(ID_Buffer, 50, fp);
	
	fclose(fp);*/

	FILE* fp = NULL;
	errno_t err = fopen_s(&fp, ".\\square_away.txt", "r");
	if (err != 0)
		return;
	char* tmp_IP = NULL;
	char* tmp_ID = NULL;
	// һ��NULL���ַ������ܸ��Ƹ�string����
	char IP_Buffer[100], ID_Buffer[100];
	tmp_ID = fgets(ID_Buffer, 50, fp);
	tmp_IP = fgets(IP_Buffer, 50, fp);
	if (tmp_ID != NULL)
		Client_ID = tmp_ID;
	if (tmp_IP != NULL)
		Client_IP = tmp_IP;
	fclose(fp); 
}



