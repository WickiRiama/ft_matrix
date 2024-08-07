#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "inverse.hpp"

Test(Inverse, notSquare)
{
	Matrix<float> m({{1, 2, 3}, {4, 5, 6}});
	std::stringstream ss("");
	try
	{
		m.inverse();
	}
	catch(const std::length_error &e)
	{
		ss << e.what();
	}
	cr_expect(ss.str() == "Attempt to get the inverse of a non square matrix.");
}

