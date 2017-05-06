#pragma once

#include <set>
#include <vector>
#include <iostream>
#include <iterator>

std::vector<double> ImportNumbers(std::istream & stream);
void PrintNumbers(const std::vector<double> &numbers);
void MathLogic(std::vector<double> &numbers);