#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "cross_product.hpp"

Test(CrossProduct, school1)
{
	Vector<float> u({0.f, 0.f, 1.f});
	Vector<float> v({1.f, 0.f, 0.f});

	cr_assert(cross_product(u, v) == Vector<float>({0.f, 1.f, 0.f}));
}

Test(CrossProduct, school2)
{
	Vector<float> u({1.f, 2.f, 3.f});
	Vector<float> v({4.f, 5.f, 6.f});

	cr_assert(cross_product(u, v) == Vector<float>({-3.f, 6.f, -3.f}));
}

Test(CrossProduct, school3)
{
	Vector<float> u({4.f, 2.f, -3.f});
	Vector<float> v({-2.f, -5.f, 16.f});

	cr_assert(cross_product(u, v) == Vector<float>({17.f, -58.f, -16.f}));
}

Test(CrossProduct, empty)
{
	Vector<float> u;
	Vector<float> v;
	std::stringstream ss("");

	try
	{
		cross_product(u, v);
	}
	catch(const std::length_error& e)
	{
		ss << e.what();
	}
	
	cr_assert(ss.str() == "Cross product with vectors of size different than 3.");
}

Test(CrossProduct, sizeError)
{
	Vector<float> u({1.f, 2.f});
	Vector<float> v({1.f, 2.f});
	std::stringstream ss("");

	try
	{
		cross_product(u, v);
	}
	catch(const std::length_error& e)
	{
		ss << e.what();
	}
	
	cr_assert(ss.str() == "Cross product with vectors of size different than 3.");
}

Test(CrossProduct, colinearity)
{
	Vector<float> u({1.f, 2.f, 3.f});
	Vector<float> v({2.f, 4.f, 6.f});
	std::stringstream ss("");

	cr_assert(cross_product(u, v) == Vector<float>({0.f, 0.f, 0.f}));
}
