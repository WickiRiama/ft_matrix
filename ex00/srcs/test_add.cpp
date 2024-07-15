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
}

Test(Add, matrixSchoolTest)
{
	Matrix<float> u({{1., 2.}, {3., 4.}});
	Matrix<float> v({{7., 4.}, {-2., 2.}});
	u.add(v);
	cr_expect(u == Matrix<float>({{8.0, 6.0}, {1.0, 6.0}}));
}

Test(Add, vectorSchoolTest)
{
	Vector<float> u({2., 3.});
	Vector<float> v({5., 7.});
	u.add(v);
	cr_expect(u == Vector<float>({7.0, 10.0}));
}