#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "Matrix_add_sub_scale.hpp"
#include "Vector_add_sub_scale.hpp"

Test(Sub, matrixSub)
{
	Matrix<float> mat1;
	Matrix<float> mat2;
	Matrix<float> mat3({{1.0, 8}, {-1, 3.6}});
	Matrix<float> mat4({{4, -12}, {-6, 9.6}});

	Matrix<float> result1;
	Matrix<float> result2({{-3, 20}, {5, -6}});
	mat1.sub(mat2);
	cr_expect(mat1 == result1);
	mat3.sub(mat4);
	cr_expect(mat3 == result2);

	std::stringstream ss;
	ss << "";
	try
	{
		mat1.sub(mat3);
	}
	catch (const std::length_error &e)
	{
		ss << e.what();
	}
	cr_expect(strcmp(ss.str().c_str(), "Matrices with different sizes") == 0);
}

Test(Sub, vectorSub)
{
	Vector<float> vec1;
	Vector<float> vec2;
	Vector<float> vec3({1.0, 8, -1, 3.6});
	Vector<float> vec4({4, -12, -6, 9.6});

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
}

Test(Sub, matrixSchoolTest)
{
	Matrix<float> u({{1., 2.}, {3., 4.}});
	Matrix<float> v({{7., 4.}, {-2., 2.}});
	u.sub(v);
	cr_expect(u == Matrix<float>({{-6.0, -2.0}, {5.0, 2.0}}));
}

Test(Sub, vectorSchoolTest)
{
	Vector<float> u({2., 3.});
	Vector<float> v({5., 7.});
	u.sub(v);
	cr_expect(u == Vector<float>({-3.0, -4.0}));
}