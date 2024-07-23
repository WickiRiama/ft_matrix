#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include <cmath>

#include "lerp.hpp"

Test(Lerp, floatSchool)
{
	cr_expect(isEqual(lerp(0., 1., 0.), 0.0));
	cr_expect(isEqual(lerp(0., 1., 1.), 1.0));
	cr_expect(isEqual(lerp(0., 1., 0.5), 0.5));
	cr_expect(isEqual(lerp(21., 42., 0.3), 27.3));
}

Test(Lerp, floatReverse)
{
	cr_expect(isEqual(lerp(1., 0., 0.), 1.0));
	cr_expect(isEqual(lerp(1., 0., 1.), 0.0));
	cr_expect(isEqual(lerp(1., 0., 0.5), 0.5));
	cr_expect(isEqual(lerp(42., 21., 0.3), 35.7));
}

Test(Lerp, extrapolation)
{
	cr_expect(isEqual(lerp(0., 1., 1.5), 1.5));
}

Test(Lerp, intLerp)
{
	cr_expect(lerp((int)0, (int)1, 0.) == 0);
	cr_expect(lerp((int)0, (int)1, 1.) == 1);
	cr_expect(lerp((int)0, (int)1, 0.) == 0);
	cr_expect(lerp((int)21, (int)42, 0.3) == 27);
}

Test(Lerp, vectorSchool)
{
	cr_expect(lerp(Vector<float>({2., 1.}), 
			  Vector<float>({4., 2.}), 0.3) == Vector<float>({2.6, 1.3}));
}

Test(Lerp, vectorReverse)
{
	cr_expect(lerp(Vector<float>({4., 2.}), 
			  Vector<float>({2., 1.}), 0.3) == Vector<float>({3.4, 1.7}));
}


Test(Lerp, vectorEmpty)
{
	cr_expect(lerp(Vector<float>(), 
			  Vector<float>(), 0.3) == Vector<float>());
}

Test(Lerp, vectorSizeError)
{
	std::stringstream ss("");
	try
	{
		Vector<float> result = lerp(Vector<float>({1}), Vector<float>({1, 2}), 0.3);
	}
	catch(const std::length_error& e)
	{
		ss << e.what();
	}
	cr_expect(ss.str() == "Vectors with different sizes");
}

Test(Lerp, matrixSchool)
{
	cr_expect(lerp(Matrix<float>({{2., 1.}, {3., 4.}}), 
			  Matrix<float>({{20., 10.}, {30., 40.}}), 0.5) \
			  == Matrix<float>({{11., 5.5}, {16.5, 22.}}));
}

Test(Lerp, matrixReverse)
{
	cr_expect(lerp(Matrix<float>({{20., 10.}, {30., 40.}}), 
			  Matrix<float>({{2., 1.}, {3., 4.}}), 0.5) \
			  == Matrix<float>({{11., 5.5}, {16.5, 22.}}));
}

Test(Lerp, matrixEmpty)
{
	cr_expect(lerp(Matrix<float>(), Matrix<float>(), 0.5) \
			  == Matrix<float>());
}

Test(Lerp, matrixSizeError)
{
	std::stringstream ss("");
	std::vector<float> v(1, 1.);
	std::vector<std::vector<float>> m(1, v);
	try
	{
		Matrix<float> result = lerp(Matrix<float>({m}), Matrix<float>({{1.}, {2.}}), 0.5);
	}
	catch(const std::length_error& e)
	{
		ss << e.what();
	}
	cr_expect(ss.str() == "Matrices with different sizes");
}
