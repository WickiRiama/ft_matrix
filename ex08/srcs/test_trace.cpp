#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "trace.hpp"

Test(Trace, school1)
{
	Matrix<float> u({{1.f, 0.f}, {0.f, 1.f}});

	cr_assert(u.trace() == 2.0f);
}

Test(Trace, school2)
{
	Matrix<float> u({{2.f, -5.f, 0.f}, {4.f, 3.f, 7.f}, {-2.f, 3.f, 4.f}});

	cr_assert(u.trace() == 9.0f);
}

Test(Trace, school3)
{
	Matrix<float> u({{-2.f, -8.f, 4.f}, {1.f, -23.f, 4.f}, {0.f, 6.f, 4.f}});

	cr_assert(u.trace() == -21.0f);
}

Test(Trace, empty)
{
	Matrix<float> u;

	cr_assert(u.trace() == 0.0f);
}

Test(Trace, nonSquare)
{
	Matrix<float> u({{-2.f, -8.f, 4.f}, {1.f, -23.f, 4.f}});
	std::stringstream ss("");

	try
	{
		u.trace();
	}
	catch(const std::length_error &e)
	{
		ss << e.what();
	}
	
	cr_assert(ss.str() == "Attempt to get the trace of a non square matrix.");
}
