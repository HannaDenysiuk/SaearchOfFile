#include "SearchOfFile.h"
#include<iostream>
#include<iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

	vector<string> SearchOfFile::GetDicsks()
	{
		vector<string> disks;
		DWORD Disks = GetLogicalDrives();
		char temp[2];
		for (int dc = 0; dc < 32; dc++)
		{
			if (Disks & (1 << dc))
			{
				temp[1] = 0;
				temp[0] = 'A' + dc;
				disks.push_back(temp);
			}
		}

		return disks;
	}

	void SearchOfFile::SarchFilePath(string strRootPath,  string name,bool* flag, bool bRecursive)
	{
        string strFileToFind = strRootPath + "*.*";
        WIN32_FIND_DATAA findData;
        HANDLE hFileFind = FindFirstFileA(LPCSTR(strFileToFind.c_str()), &findData);
        if (INVALID_HANDLE_VALUE != hFileFind)
        {
            do
            {
                string strFileName = findData.cFileName;

                if ((strFileName == ".") || (strFileName == ".."))
                    continue;

                string strFilePath = strRootPath + strFileName + "\\";

                if (bRecursive && (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
                {
                    SarchFilePath(strFilePath, name, flag);
                }
                else
                {
                    if (findData.cFileName == name)
                    {
                        std::cout << strFilePath << endl;
                        *flag = true;
                        return;
                    }
                }

            } while (FindNextFileA(hFileFind, &findData));

            FindClose(hFileFind);
        }
	}

    void  SearchOfFile::GetFilePath(string name) {
        vector<string> disks;
        bool flag = false;
        disks = GetDicsks();
        for (int i = 0; i < disks.size(); i++)
        {
          SearchOfFile::SarchFilePath(disks[i]+":\\", name, &flag);
          if (flag)
              return ;
        }
        if (!flag)
            cout << "file note found" << endl;
    }