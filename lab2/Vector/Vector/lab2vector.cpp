#include "stdafx.h"
#include "lab2vector.h"

#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

vector<double> ImportNumbers(int argc, char *argv[]) 
{
	char ** _EndPtr = (char **)malloc(sizeof(char*)); //выделяем память 
	vector<double> numbers;
	for (int i = 0; i < argc; ++i)
	{
		numbers.push_back(strtod(argv[i], _EndPtr));
	}
	free(_EndPtr); // освобождаем память
	return numbers;
}

void PrintNumbers(vector<double> &numbers)
{
	for (int i = 1; i < numbers.size(); ++i)
	{
		printf("%f ", numbers[i]);
	}
}

vector<double> MathLogic(vector<double> &numbers)
{
	double min = numbers[0];
	double max = numbers[0];
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] > max)
		{
			max = numbers[i];
		}
		if (numbers[i] < min)
		{
			min = numbers[i];
		}
	}
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] < 0)
		{
			numbers[i] *= min * max;
		}
	}
	return numbers;
}