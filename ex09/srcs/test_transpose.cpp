#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "transpose.hpp"

Test(Transpose, square1)
{
	Matrix<float> u({{1.f, 0.f}, {0.f, 1.f}});

	cr_assert(u.transpose() == Matrix<float>({{1.f, 0.f}, {0.f, 1.f}}));
}

Test(Transpose, square2)
{
	Matrix<float> u({{1.f, 2.f}, {3.f, 4.f}});

	cr_assert(u.transpose() == Matrix<float>({{1.f, 3.f}, {2.f, 4.f}}));
}

Test(Transpose, nonSquare)
{
	Matrix<float> u({{-1.f, 2.f, -3.f}, {4.f, -5.f, 6.f}});

	cr_assert(u.transpose() == Matrix<float>({{-1.f, 4.f}, {2.f, -5.f}, {-3.f, 6.f}}));
}

Test(Transpose, empty)
{
	Matrix<float> u;

	cr_assert(u.transpose() == Matrix<float>());
}

Test(Transpose, oneRow)
{
	Matrix<float> u({{1.f, 2.f}});

	cr_assert(u.transpose() == Matrix<float>({std::vector<float>(1, 1.f), std::vector<float>(1, 2.f)}));
}

Test(Transpose, oneCol)
{
	Matrix<float> u({std::vector<float>(1, 1.f), std::vector<float>(1, 2.f)});

	cr_assert(u.transpose() == Matrix<float>({{1.f, 2.f}}));
}
