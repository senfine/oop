#include "stdafx.h"
#include "lab2vector.h"

#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

vector<double> ImportNumbers(istream & stream)
{
	return move(vector<double>(istream_iterator<double>(stream), istream_iterator<double>()));
}

// вывод в стандартный поток полученный массив
void PrintNumbers(const vector<double> &numbers)
{
	for (const double &x : numbers)
			cout << x << " ";
}

// вариант 5
// Умножить каждый отрицательный элемент массива на 
// произведение максимального и минимального элементов исходного массива 
void MathLogic(vector<double> &numbers)
{
	auto result = minmax_element(numbers.begin(), numbers.end());

	auto min = *result.first;
	auto max = *result.second;

	for (double& x : numbers)
		if (x < 0)
			x *= min * max;
}
