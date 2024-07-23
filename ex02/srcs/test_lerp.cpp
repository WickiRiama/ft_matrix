#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "lerp.hpp"

Test(Lerp, floatSchool)
{
	cr_expect(isEqual(lerp(0., 1., 0.), 0.0));
	cr_expect(isEqual(lerp(0., 1., 1.), 1.0));
	cr_expect(isEqual(lerp(0., 1., 0.5), 0.5));
	cr_expect(isEqual(lerp(21., 42., 0.3), 27.3));
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