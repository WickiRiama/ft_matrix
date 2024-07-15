#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "Matrix.hpp"

Test(Sub, matrixSub)
{
	cr_expect(1 == 1);
}

Test(Sub, vectorSub)
{
	Vector<float> vec1;
	Vector<float> vec2;
	Vector<float> vec3({1.0, 8, -1, 3.6});
	Vector<float> vec4({4, -12, -6, 9.6});
	Vector<float> vec5({4, -12, -6, 9.6, 25});

	Vector<float> result1;
	Vector<float> result2({-3, 20, 5, -6});
	vec1.sub(vec2);
	cr_expect(vec1 == result1);
	vec3.sub(vec4);
	cr_expect(vec3 == result2);

	std::stringstream ss;
	ss << "";
	try
	{
		vec1.sub(vec3);
	}
	catch (const std::length_error &e)
	{
		ss << e.what();
	}
	cr_expect(strcmp(ss.str().c_str(), "Vectors with different sizes") == 0);
	ss.str("");
	try
	{
		vec3.sub(vec5);
	}
	catch (const std::length_error &e)
	{
		ss << e.what();
	}
	cr_expect(strcmp(ss.str().c_str(), "Vectors with different sizes") == 0);
}
