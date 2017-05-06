#include "stdafx.h"
#include "../Vector/lab2vector.h"

#include <vector>
#include <set>
#include <sstream>
#include <iostream>
#include <istream>
#include <streambuf>
using namespace std;

struct membuf : std::streambuf
{
	membuf(char* begin, char* end) 
	{
		this->setg(begin, begin, end);
	}
};

BOOST_AUTO_TEST_SUITE(Vector)
	BOOST_AUTO_TEST_CASE(Import_numbers)
	{
		//setlocale(LC_ALL, "Russian");

		char buffer[] = "-5 10.56 2.3";

		membuf sbuf(buffer, buffer + sizeof(buffer));
		std::istream in(&sbuf);
		
		vector<double> numbers = ImportNumbers(in);

		BOOST_CHECK(numbers[0] == -5 );
		BOOST_CHECK(numbers[1] == 10.56);
		BOOST_CHECK(numbers[2] == 2.3);
	}

	BOOST_AUTO_TEST_CASE(Math_Logic)
	{
		vector<double> numbers({-5, 10.56, 2.3});
		MathLogic(numbers);
		
		BOOST_CHECK(numbers[0] == 264.0);
		BOOST_CHECK(numbers[1] == 10.56);
		BOOST_CHECK(numbers[2] == 2.3);
	}

BOOST_AUTO_TEST_SUITE_END()