#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "norm.hpp"

Test(Norm, school1)
{
	Vector<float> u({0., 0., 0.});
	cr_assert(isEqual(u.norm_1(), 0.0));
}

Test(Norm, school2)
{
	Vector<float> u({1., 2., 3.});
	cr_assert(isEqual(u.norm_1(), 6.0));
}

Test(Norm, school3)
{
	Vector<float> u({-1., -2.});
	cr_assert(isEqual(u.norm_1(), 3.0));
}

Test(Norm, emptyVector)
{
	Vector<float> u;
	cr_assert(isEqual(u.norm_1(), 0.));
}
