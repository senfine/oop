#include "stdafx.h"
#include "lab2vector.h"
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 2)
	{
		printf("Неверное количество параметров.\n");
		return 1;
	}

	vector<double> numbers = ImportNumbers(argc, argv);
	PrintNumbers(numbers);
	printf("\n");

	numbers = MathLogic(numbers);
	
	PrintNumbers(numbers);
	
	system("pause");
    return 0;
}

