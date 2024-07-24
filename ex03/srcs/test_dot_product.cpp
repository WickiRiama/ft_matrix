#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "dot_product.hpp"

Test(DotPrd, school1)
{
	Vector<float> u({0., 0.});
	Vector<float> v({1., 1.});
	
	cr_assert(isEqual(u.dot(v), 0.0));
}

Test(DotPrd, school2)
{
	Vector<float> u({1., 1.});
	Vector<float> v({1., 1.});
	
	cr_assert(isEqual(u.dot(v), 2.0));
}

Test(DotPrd, school3)
{
	Vector<float> u({-1., 6.});
	Vector<float> v({3., 2.});
	
	cr_assert(isEqual(u.dot(v), 9.0));
}

Test(DotPrd, vectorSizeError)
{
	Vector<float> u({1., 1.});
	Vector<float> v({1., 1., 1.});
	std::stringstream ss("");

	try
	{
		u.dot(v);
	}
	catch (const std::length_error &e)
	{
		ss << e.what();
	}
	cr_assert(ss.str() == "Vectors with different sizes");
}

Test(DotPrd, ortho)
{
	Vector<float> u({0., 1.});
	Vector<float> v({1., 0.});
	
	cr_assert(isEqual(u.dot(v), 0.0));
}

Test(DotPrd, empty)
{
	Vector<float> u;
	Vector<float> v;
	
	cr_assert(isEqual(u.dot(v), 0.0));
}

