#ifndef SEARCHOFFILE_H 
#define SEARCHOFFILE_H 

#include<iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;
	class SearchOfFile
	{
	public:

		vector<string> GetDicsks();
		void SarchFilePath(string strRootPath, string name,bool* flag, bool bRecursive = true);
		void GetFilePath(string name);

	};

#endif //SearchOfFile
