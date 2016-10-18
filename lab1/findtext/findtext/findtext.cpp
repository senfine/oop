#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main(int argc, char *argv[]) 
{
	ifstream in;
	string buffer, sought;
	int cnt = 0;
	bool is_find = false;

	if (argc != 3) 
	{
		cout << "Arguments is invalid\n";
		return 1;
	}

	in.open(argv[1]);
	sought = argv[2];

	if (!in.is_open())
	{
		cout << "File not exists\n";
		return 1;
	}


	while (!in.eof()) 
	{
		getline(in, buffer);

		cnt++;
		if (buffer.find(sought) != string::npos) 
		{
			cout << cnt << "\n";
			is_find = true;
		}
	}

	if (is_find) 
	{
		return 0;
	}
	else 
	{
		cout << "Text not found\n";
		return 1;
	}
}
