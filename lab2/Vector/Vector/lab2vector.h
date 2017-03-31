#pragma once

#include <set>
#include <vector>
#include <iostream>

std::vector<double> ImportNumbers(int argc, char *argv[]);
void PrintNumbers(std::vector<double> &numbers);
std::vector<double> MathLogic(std::vector<double> &numbers);