// findtext.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Wrong command line\n";
		cout << "Usage: findtext.exe <file name> <text to search>\n";
		return 1;
	}
    return 0;
}

