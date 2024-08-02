#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "row_echelon.hpp"

Test(RowEchelon, columnMaxIndex)
{
	Matrix<float> mat({{0, 1, 2}, {0, 2, 0}, {0, 0, 1}});
	cr_expect(column_max_index(mat, 0, 0) == 0);
	cr_expect(column_max_index(mat, 0, 1) == 1);
	cr_expect(column_max_index(mat, 1, 0) == 1);
	cr_expect(column_max_index(mat, 2, 0) == 0);
	cr_expect(column_max_index(mat, 2, 1) == 2);
}

Test(RowEchelon, rowSwitch)
{
	Matrix<float> mat({{0, 1, 2}, {0, 2, 0}, {0, 0, 1}});
	row_switch(mat[1], mat[2]);
	cr_expect(mat == Matrix<float>({{0, 1, 2}, {0, 0, 1}, {0, 2, 0}}));
	row_switch(mat[1], mat[1]);
	cr_expect(mat == Matrix<float>({{0, 1, 2}, {0, 0, 1}, {0, 2, 0}}));
}

Test(RowEchelon, rowMultiplication)
{
	Matrix<float> mat({{0, 1, 2}, {0, 2, 0}, {0, 0, 1}});
	row_multiplication(mat[0], 2.5f);
	cr_expect(mat == Matrix<float>({{0, 2.5, 5}, {0, 2, 0}, {0, 0, 1}}));
	row_multiplication(mat[2], -10.f);
	cr_expect(mat == Matrix<float>({{0, 2.5, 5}, {0, 2, 0}, {0, 0, -10}}));

	std::stringstream ss("");
	try
	{
		row_multiplication(mat[0], 0.f);
	}
	catch (std::invalid_argument const &e)
	{
		ss << e.what();
	}
	cr_expect(ss.str() == "Multpilication by 0 is not allowed");
}

Test(RowEchelon, rowAddMul)
{
	Matrix<float> mat({{0, 1, 2}, {0, 2, 0}, {0, 0, 1}});
	std::vector<float> v({0, 1, 2, 3});

	row_add_mul(mat[0], mat[1], 2.5f);
	cr_expect(mat == Matrix<float>({{0, 6, 2}, {0, 2, 0}, {0, 0, 1}}));
	row_add_mul(mat[0], mat[2], -10.f);
	cr_expect(mat == Matrix<float>({{0, 6, -8}, {0, 2, 0}, {0, 0, 1}}));

	std::stringstream ss("");
	try
	{
		row_add_mul(mat[0], mat[1], 0.f);
	}
	catch (std::invalid_argument const &e)
	{
		ss << e.what();
	}
	cr_expect(ss.str() == "Multpilication by 0 is not allowed");

	ss.str("");
	try
	{
		row_add_mul(mat[0], v, 1.f);
	}
	catch (std::length_error const &e)
	{
		ss << e.what();
	}
	cr_expect(ss.str() == "Matrix rows with different sizes");
}

Test(RowEchelon, school1)
{
	Matrix<float> u({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
	cr_expect(u.row_echelon() == Matrix<float>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}));
}

Test(RowEchelon, school2)
{
	Matrix<float> u({{1, 2}, {3, 4}});
	cr_expect(u.row_echelon() == Matrix<float>({{1, 0}, {0, 1}}));
}

Test(RowEchelon, school3)
{
	Matrix<float> u({{1, 2}, {2, 4}});
	cr_expect(u.row_echelon() == Matrix<float>({{1, 2}, {0, 0}}));
}

Test(RowEchelon, school4)
{
	Matrix<float> u({{8, 5, -2, 4, 28}, {4, 2.5, 20, 4, -4}, {8, 5, 1, 4, 17}});
	cr_expect(u.row_echelon() == Matrix<float>({{1, 0.625, 0, 0, -12.1666667}, {0, 0, 1, 0, -3.6666667}, {0, 0, 0, 1, 29.5}}));
}

Test(RowEchelon, manyRows)
{
	Matrix<float> u({{8, 5, -2}, {4, 2.5, 20}, {8, 5, 1}, {1, 1, 1}});
	cr_expect(u.row_echelon() == Matrix<float>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0, 0, 0}}));
}

Test(RowEchelon, empty)
{
	Matrix<float> u;
	cr_expect(u.row_echelon() == Matrix<float>());
}