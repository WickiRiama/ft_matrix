#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "cosine.hpp"

Test(Cosine, school1)
{
	Vector<float> u({1, 0});
	Vector<float> v({1, 0});
	cr_assert(isEqual(angle_cos(u, v), 1.0));
}

Test(Cosine, school2)
{
	Vector<float> u({1, 0});
	Vector<float> v({0, 1});
	cr_assert(isEqual(angle_cos(u, v), 0.0));
}

Test(Cosine, school3)
{
	Vector<float> u({-1, 1});
	Vector<float> v({1, -1});
	cr_assert(isEqual(angle_cos(u, v), -1.0));
}

Test(Cosine, school4)
{
	Vector<float> u({2, 1});
	Vector<float> v({4, 2});
	cr_assert(isEqual(angle_cos(u, v), 1.0));
}

Test(Cosine, school5)
{
	Vector<float> u({1, 2, 3});
	Vector<float> v({4, 5, 6});
	cr_assert(isEqual(angle_cos(u, v), 0.974631846));
}

Test(Cosine, emptyVectors)
{
	Vector<float> u;
	Vector<float> v;

	std::stringstream ss("");
	try
	{
		std::cerr << angle_cos(u, v);
	}
	catch (std::runtime_error const &e)
	{
		ss << e.what();
	}
	cr_assert(ss.str() == "Attempt to divide by 0.");
}

Test(Cosine, zeroVector)
{
	Vector<float> u({1, 2});
	Vector<float> v({0, 0});

	std::stringstream ss("");
	try
	{
		std::cerr << angle_cos(u, v);
	}
	catch (std::runtime_error const &e)
	{
		ss << e.what();
	}
	cr_assert(ss.str() == "Attempt to divide by 0.");
}

Test(Cosine, sizeError)
{
	Vector<float> u({1, 2});
	Vector<float> v({0, 1, 2});

	std::stringstream ss("");
	try
	{
		std::cerr << angle_cos(u, v);
	}
	catch (std::length_error const &e)
	{
		ss << e.what();
	}
	cr_assert(ss.str() == "Vectors with different sizes.");
}
