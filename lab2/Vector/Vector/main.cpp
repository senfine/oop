#include "stdafx.h"
#include "lab2vector.h"
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 2)
	{
		printf("Неверное количество параметров.\n");
		return 1;
	}

	vector<double> numbers;
	numbers = ImportNumbers(cin);
	PrintNumbers(numbers);
	printf("\n");

	MathLogic(numbers);
	
	PrintNumbers(numbers);
	
	system("pause");
    return 0;
}

