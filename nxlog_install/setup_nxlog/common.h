#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <stdint.h>
#include <string>
#include <Windows.h>

using namespace std;

#define MAX_PATH_LEN 256
#define ACCESS(fileName,accessMode) _access(fileName,accessMode)
#define MKDIR(path) _mkdir(path)

int32_t createDirectory(const std::string &directoryPath)
{
	uint32_t dirPathLen = directoryPath.length();
	if (dirPathLen > MAX_PATH_LEN)
	{
		return -1;
	}
	char tmpDirPath[MAX_PATH_LEN] = { 0 };
	for (uint32_t i = 0; i < dirPathLen; ++i)
	{
		tmpDirPath[i] = directoryPath[i];
		if (tmpDirPath[i] == '\\' || tmpDirPath[i] == '/')
		{
			if (ACCESS(tmpDirPath, 0) != 0)
			{
				int32_t ret = MKDIR(tmpDirPath);
				if (ret != 0)
				{
					return ret;
				}
			}
		}
	}
	return 0;
}

void Config_Path_Method(string& Conf_Path)
{
	//ÅÐ¶Ïnxlog.conf´æÔÚ²»´æÔÚ

	if (_access("C:\\Program Files (x86)", 0) != -1)
	{
		Conf_Path = "C:\\Program Files (x86)";
	}
	else if (_access("C:\\Program Files", 0) != -1)
	{
		Conf_Path = "C:\\Program Files";
	}
}


int Guide()
{
	FILE* fp = NULL;
	errno_t err = fopen_s(&fp, ".\\PACKAGE\\square_away.txt", "r");
	if (err != 0)
	{
		return -1;
	}

	char buffer_ID[50];
	fgets(buffer_ID, 30, fp);

	string ID_Path = "";
	Config_Path_Method(ID_Path);
	if (ID_Path.find("Program Files (x86)") != string::npos)
	{
		ID_Path = "C:\\Program Files (x86)\\nxlog\\";
	}
	else if (ID_Path.find("Program Files") != string::npos)
	{
		ID_Path = "C:\\Program Files\\nxlog\\";
	}

	int ret = createDirectory(ID_Path.c_str());
	if (ret != 0)
	{
		return -4;
	}
	ID_Path += "square_away.txt";
	FILE* fp2 = NULL;
	errno_t err2 = fopen_s(&fp2, ID_Path.c_str(), "w+");
	if (err2 != 0)
	{
		return -3;
	}
	fputs(buffer_ID, fp2);
	fclose(fp);
	fclose(fp2);

	system(".\\PACKAGE\\nxlog.msi");
	return 0;
}