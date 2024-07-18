#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "Vector.hpp"

Test(LinCmb, empty)
{
	std::vector< Vector<float> > vectors;
	std::vector<float> coefs;

	Vector<float> result = linear_combination(vectors, coefs);
	cr_expect(result == Vector<float>(std::vector<float>()));
}

Test(LinCmb, emptyVectors)
{
	Vector<float> v1;
	Vector<float> v2;
	std::vector< Vector<float> > vectors({v1, v2});
	std::vector<float> coefs({-1, 42});

	Vector<float> result = linear_combination(vectors, coefs);
	cr_expect(result == Vector<float>(std::vector<float>()));
}


Test(LinCmb, emptyCoeff)
{
	Vector<float> v({1, 2});
	std::vector< Vector<float> > vectors({v});
	std::vector<float> coefs;

	std::stringstream ss("");
	try
	{
		Vector<float> result = linear_combination(vectors, coefs);
	}
	catch (const std::length_error &e)
	{
		ss << e.what();
	}
	cr_expect(ss.str() == "Coefficients number different from vectors number");
}


Test(LinCmb, diffVectorCoeff)
{
	std::vector< Vector<float> > vectors;
	std::vector<float> coefs = {1, 2, 3};

	std::stringstream ss("");
	try
	{
		Vector<float> result = linear_combination(vectors, coefs);
	}
	catch (const std::length_error &e)
	{
		ss << e.what();
	}
	cr_expect(ss.str() == "Coefficients number different from vectors number");
}

Test(LinCmb, diffVectorSize)
{
	Vector<float> vec1;
	Vector<float> vec2({1, 2.5});
	Vector<float> vec3({8, 2.3});
	std::vector< Vector<float> > vectors = {vec1, vec2, vec3};
	std::vector<float> coefs = {1, 2, 3};

	std::stringstream ss("");
	try
	{
		Vector<float> result = linear_combination(vectors, coefs);
	}
	catch (const std::length_error &e)
	{
		ss << e.what();
	}
	cr_expect(ss.str() == "Vectors with different sizes");
}

Test(LinCmb, school1)
{
	Vector<float> e1({1., 0., 0.});
	Vector<float> e2({0., 1., 0.});
	Vector<float> e3({0., 0., 1.});
	std::vector< Vector<float> > vectors = {e1, e2, e3};
	std::vector<float> coefs = {10., -2., 0.5};

	Vector<float> result = linear_combination(vectors, coefs);
	cr_expect(result == Vector<float>({10., -2., 0.5}));
}

Test(LinCmb, school2)
{
	Vector<float> v1({1., 2., 3.});
	Vector<float> v2({0., 10., -100.});
	std::vector< Vector<float> > vectors = {v1, v2};
	std::vector<float> coefs = {10., -2.};

	Vector<float> result = linear_combination(vectors, coefs);
	cr_expect(result == Vector<float>({10., 0., 230.}));
}
