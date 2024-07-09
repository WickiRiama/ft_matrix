#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

Test(Add, matrixAdd)
{
	Matrix<float> mat1;
	Matrix<float> mat2;
	Matrix<float> mat3({{1.0, 8}, {-1, 3.6}});
	Matrix<float> mat4({{4, -12}, {-6, 9.6}});

	Matrix<float> result1;
	Matrix<float> result2({{5, -4}, {-7, 13.2}});
	mat1.add(mat2);
	cr_expect(mat1 == result1);
	mat3.add(mat4);
	cr_expect(mat3 == result2);

	std::stringstream ss;
	ss << "";
	try
	{
		mat1.add(mat3);
	}
	catch (const std::length_error &e)
	{
		ss << e.what();
	}
	cr_expect(strcmp(ss.str().c_str(), "Matrices with different sizes") == 0);
}

Test(Add, vectorAdd)
{
	Vector<float> vec1;
	Vector<float> vec2;
	Vector<float> vec3({1.0, 8, -1, 3.6});
	Vector<float> vec4({4, -12, -6, 9.6});
	Vector<float> vec5({4, -12, -6, 9.6, 25});

	Vector<float> result1;
	Vector<float> result2({5, -4, -7, 13.2});
	vec1.add(vec2);
	cr_expect(vec1 == result1);
	vec3.add(vec4);
	cr_expect(vec3 == result2);

	std::stringstream ss;
	ss << "";
	try
	{
		vec1.add(vec3);
	}
	catch (const std::length_error &e)
	{
		ss << e.what();
	}
	cr_expect(strcmp(ss.str().c_str(), "Vectors with different sizes") == 0);
	ss.str("");
	try
	{
		vec3.add(vec5);
	}
	catch (const std::length_error &e)
	{
		ss << e.what();
	}
	cr_expect(strcmp(ss.str().c_str(), "Vectors with different sizes") == 0);
}
