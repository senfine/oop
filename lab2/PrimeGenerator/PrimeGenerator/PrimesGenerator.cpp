#include "stdafx.h"
#include "PrimesGenerator.h"

#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;

vector<bool> GetPrimes(int upperBound)
{
	vector<bool> sieve;
	for (int i = 0; i < upperBound; ++i)
	{
		if (i % 2 != 0)
			sieve.push_back(true);
		else
			sieve.push_back(false);
	}
	sieve[2] = true;

	for (long long i = 3; i <= upperBound; i++)
	{
		if (sieve[static_cast<unsigned int>(i)])
		{
			for (long long j = i * i; j <= upperBound; j += 2 * i)
			{
				sieve[static_cast<unsigned int>(j)] = false;
			}
		}
	}	
	return sieve;
}

set<int> GetPrimesSet(vector<bool> &numbers)
{
	set<int> primes;
	primes.emplace(2);

	for (unsigned int i = 3; i <= numbers.size(); ++i)
	{
		if (numbers[i])
			primes.emplace(i);
	}
	return primes;
}

void PrintSet(set<int> &set, ostream &stream)
{
	copy(set.begin(), set.end(), ostream_iterator<int>(stream, " "));
}