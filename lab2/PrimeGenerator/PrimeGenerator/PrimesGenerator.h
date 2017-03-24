#pragma once

#include <set>
#include <vector>
#include <iostream>

std::vector<bool> GetPrimes(int upperBound);
std::set<int> GetPrimesSet(std::vector<bool> &numbers);
void PrintSet(std::set<int> &set, std::ostream &stream = std::cout);