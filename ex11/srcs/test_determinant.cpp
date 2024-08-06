#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "determinant.hpp"

Test(Determinant, notSquare)
{
	Matrix<float> m({{1, 2, 3}, {4, 5, 6}});
	std::stringstream ss("");

	try
	{
		m.determinant();
	}
	catch (std::length_error const &e)
	{
		ss << e.what();
	}
	cr_expect(ss.str() == "Attempt to get the determinant of a non square matrix.");
}

Test(Determinant, empty)
{
	Matrix<float> m;
	cr_expect(isEqual(m.determinant(), 1));
}

Test(Determinant, size_1)
{
	std::vector<std::vector<float> > v({{1}});
	std::vector<std::vector<float> > u({{2}});
	Matrix<float> m_1(v);
	Matrix<float> m_2(u);
	cr_expect(isEqual(m_1.determinant(), 1));
	cr_expect(isEqual(m_2.determinant(), 2));
}

Test(Determinant, size_2)
{
	Matrix<float> m({{1, -1}, {-1, 1}});
	cr_expect(isEqual(m.determinant(), 0));

	m = Matrix<float>({{1, 0}, {0, 1}});
	cr_expect(isEqual(m.determinant(), 1));

	m = Matrix<float>({{1, 2}, {3, 4}});
	cr_expect(isEqual(m.determinant(), -2));

	m = Matrix<float>({{1, -2}, {3, -4}});
	cr_expect(isEqual(m.determinant(), 2));
}

Test(Determinant, size_3)
{
	Matrix<float> m({{2, 0, 0}, {0, 2, 0}, {0, 0, 2}});
	cr_expect(isEqual(m.determinant(), 8));

	m = Matrix<float>({{2, -3, 1}, {2, 0, -1}, {1, 4, 5}});
	cr_expect(isEqual(m.determinant(), 49));

	m = Matrix<float>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
	cr_expect(isEqual(m.determinant(), 1));
}
