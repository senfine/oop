// findtext.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <functional>
#include <string>
#include <fstream>

using namespace std;


using FindStringCallback = function<void(int lineIndex, const string& line, size_t foundPos)>;
// using позволяет сделать то же, что и typedef, но даже больше.
//typedef function<void(int lineIndex, const string& line, size_t foundPos)> FindStringCallback;

bool FindStingInStream(istream & haystack,
	const string& needle,
	const FindStringCallback & callback = FindStringCallback())
{
	string line;
	bool found = false;
	for (int lineIndex = 1; getline(haystack, line); ++lineIndex)
	{
		auto pos = line.find(needle);
		if (pos != string::npos)
		{
			found = true;
			// Передаем в функцию обратного вызова информацию о первом найденном вхождении подстроки
			if (callback)
			{
				callback(lineIndex, line, pos);
			}
		}
	}
	return found;
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Wrong command line\n";
		cout << "Usage: findtext.exe <file name> <text to search>\n";
		return 1;
	}

	ifstream input(argv[1]);
	if (!FindStingInStream(input, argv[2]))
	{
		return 1;
	}

    return 0;
}

