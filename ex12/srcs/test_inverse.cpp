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

Test(Inverse, singular)
{
	Matrix<float> m({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
	std::stringstream ss("");
	try
	{
		m.inverse();
	}
	catch(const std::invalid_argument &e)
	{
		ss << e.what();
	}
	cr_expect(ss.str() == "Attempt to get the inverse of a singular matrix.");
}

Test(Inverse, empty)
{
	Matrix<float> m;
	cr_expect(m.inverse() == Matrix<float>());
}


Test(Inverse, school1)
{
	Matrix<float> m({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
	cr_expect(m.inverse() == Matrix<float>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}));
}

Test(Inverse, school2)
{
	Matrix<float> m({{2, 0, 0}, {0, 2, 0}, {0, 0, 2}});
	cr_expect(m.inverse() == Matrix<float>({{0.5, 0, 0}, {0, 0.5, 0}, {0, 0, 0.5}}));
}

Test(Inverse, school3)
{
	Matrix<float> m({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}});
	cr_expect(m.inverse() == Matrix<float>({ \
		{0.649425287, 0.097701149, -0.655172414}, \
		{-0.781609195, -0.126436782, 0.965517241}, \
		{0.143678161, 0.074712644, -0.206896552}}));
}
