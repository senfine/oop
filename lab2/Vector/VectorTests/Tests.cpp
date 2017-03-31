#include "stdafx.h"
#include "../Vector/lab2vector.h"

#include <vector>
#include <set>
#include <sstream>
#include <iostream>
using namespace std;

BOOST_AUTO_TEST_SUITE(Vector)
	BOOST_AUTO_TEST_CASE(Import_numbers)
	{
		setlocale(LC_ALL, "Russian");
		char* argv[] = { "-5","10,56","2,3" };
		int argc = 3;
		vector<double> numbers = ImportNumbers(argc, argv);

		BOOST_CHECK(numbers[0] == -5 );
		BOOST_CHECK(numbers[1] == 10.56);
		BOOST_CHECK(numbers[2] == 2.3);
	}

	BOOST_AUTO_TEST_CASE(Math_Logic)
	{
		vector<double> numbers({-5, 10.56, 2.3});
		numbers = MathLogic(numbers);
		
		BOOST_CHECK(numbers[0] == 264.0);
		BOOST_CHECK(numbers[1] == 10.56);
		BOOST_CHECK(numbers[2] == 2.3);
	}

BOOST_AUTO_TEST_SUITE_END()