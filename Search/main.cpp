
#include "SearchOfFile.h"
#include<iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string name;
    cout << "enter name of file with extension: ";
    cin >> name;
    SearchOfFile sf;
	sf.GetFilePath(name);
	
    return 0;
}

