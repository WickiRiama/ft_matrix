#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "Matrix_add_sub_scale.hpp"
#include "Vector_add_sub_scale.hpp"

Test(Scl, matrixScl)
{
	Matrix<float> mat1;
	Matrix<float> mat2({{1.0, 8}, {-1, 3.6}});

	Matrix<float> result1;
	Matrix<float> result2({{1, 8}, {-1, 3.6}});
	Matrix<float> result3({{-1, -8}, {1, -3.6}});
	Matrix<float> result4({{0, 0}, {0, 0}});

	mat1.scl(1);
	mat2.scl(1);
	cr_expect(mat1 == result1);
	cr_expect(mat2 == result2);

	mat1.scl(-1);
	mat2.scl(-1);
	cr_expect(mat1 == result1);
	cr_expect(mat2 == result3);

	mat1.scl(0);
	mat2.scl(0);
	cr_expect(mat1 == result1);
	cr_expect(mat2 == result4);
}

Test(Scl, vectorScl)
{
	Vector<float> vec1;
	Vector<float> vec2({1.0, 8, -1, 3.6});

	Vector<float> result1;
	Vector<float> result2({1, 8, -1, 3.6});
	Vector<float> result3({-1, -8, 1, -3.6});
	Vector<float> result4({0, 0, 0, 0});

	vec1.scl(1);
	vec2.scl(1);
	cr_expect(vec1 == result1);
	cr_expect(vec2 == result2);

	vec1.scl(-1);
	vec2.scl(-1);
	cr_expect(vec1 == result1);
	cr_expect(vec2 == result3);

	vec1.scl(0);
	vec2.scl(0);
	cr_expect(vec1 == result1);
	cr_expect(vec2 == result4);
}

Test(Scl, matrixSchoolTest)
{
	Matrix<float> u({{1., 2.}, {3., 4.}});
	u.scl(2.);
	cr_expect(u == Matrix<float>({{2.0, 4.0}, {6.0, 8.0}}));
}

Test(Scl, vectorSchoolTest)
{
	Vector<float> u({2., 3.});
	u.scl(2.);
	Vector<float> result({4.0, 6.0});
	cr_expect(u == result);
}