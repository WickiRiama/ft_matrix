#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"

Test(Scl, matrixScl)
{
	cr_expect(1 == 1);
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
