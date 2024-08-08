#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "rank.hpp"

Test(Rank, school1)
{
	Matrix<float> m({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
	cr_expect(m.rank() == 3);
}

Test(Rank, school2)
{
	Matrix<float> m({
		{1, 2, 0, 0},
		{2, 4, 0, 0},
		{-1, 2, 1, 1}});
	cr_expect(m.rank() == 2);
}

Test(Rank, school3)
{
	Matrix<float> m({
		{8, 5, -2},
		{4, 7, 20},
		{21, 18, 7}});
	cr_expect(m.rank() == 3);
}

Test(Rank, empty)
{
	Matrix<float> m;
	cr_expect(m.rank() == 0);
}

Test(Rank, oneRow)
{
	Matrix<float> m({{21, 18, 7}});
	cr_expect(m.rank() == 1);
}

Test(Rank, oneCol)
{
	Matrix<float> m({
		{8},
		{5},
		{21}});
	std::cerr << m.rank() << std::endl;
	cr_expect(m.rank() == 1);
}
