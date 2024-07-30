#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "mat_mul.hpp"

Test(MatMul, matSizeError)
{
	Matrix<float> m1({{1, 2}, {3, 4}, {5, 6}});
	Matrix<float> m2({{1, 2}, {3, 4}, {5, 6}});
	
	std::stringstream ss("");
	try
	{
		m1.mul_mat(m2);
	}
	catch(const std::length_error &e)
	{
		ss << e.what();
	}
	cr_assert(ss.str() == "Attempt to multiply a matrix of 2 columns with a matrix of 3 rows.");
}

Test(MatMul, matSchool1)
{
	Matrix<float> u({{1, 0}, {0, 1}});
	Matrix<float> v({{1, 0}, {0, 1}});
	
	cr_assert(u.mul_mat(v) == Matrix<float>({{1, 0}, {0, 1}}));
}

Test(MatMul, matSchool2)
{
	Matrix<float> u({{1, 0}, {0, 1}});
	Matrix<float> v({{2, 1}, {4, 2}});
	
	cr_assert(u.mul_mat(v) == Matrix<float>({{2, 1}, {4, 2}}));
}

Test(MatMul, matSchool3)
{
	Matrix<float> u({{3, -5}, {6, 8}});
	Matrix<float> v({{2, 1}, {4, 2}});
	
	cr_assert(u.mul_mat(v) == Matrix<float>({{-14, -7}, {44, 22}}));
}

Test(MatMul, matEmpty)
{
	Matrix<float> u;
	Matrix<float> v;
	
	cr_assert(u.mul_mat(v) == Matrix<float>());
}

Test(MatMul, vecSizeError)
{
	Matrix<float> m({{1, 2}, {3, 4}, {5, 6}});
	Vector<float> v({1, 2, 3});
	
	std::stringstream ss("");
	try
	{
		m.mul_vec(v);
	}
	catch(const std::length_error &e)
	{
		ss << e.what();
	}
	cr_assert(ss.str() == "Attempt to multiply a matrix of 2 columns with a vector of 3 elements.");
}

Test(MatMul, vecSchool1)
{
	Matrix<float> u({{1, 0}, {0, 1}});
	Vector<float> v({4, 2});
	
	cr_assert(u.mul_vec(v) == Vector<float>({4, 2}));
}

Test(MatMul, vecSchool2)
{
	Matrix<float> u({{2, 0}, {0, 2}});
	Vector<float> v({4, 2});
	
	cr_assert(u.mul_vec(v) == Vector<float>({8, 4}));
}

Test(MatMul, vecSchool3)
{
	Matrix<float> u({{2, -2}, {-2, 2}});
	Vector<float> v({4, 2});
	
	cr_assert(u.mul_vec(v) == Vector<float>({4, -4}));
}

Test(MatMul, vecEmpty)
{
	Matrix<float> u;
	Vector<float> v;
	
	cr_assert(u.mul_vec(v) == Vector<float>());
}
