#include <limits>
#include <iostream>

bool isEqual(float const &a, float const &b)
{
	// std::numeric_limits<float>::digits10 : number of decimal digits that can be represented without change
	float epsilon = 1;
	for (int i = 0; i < std::numeric_limits<float>::digits10; i++)
	{
		epsilon /= 10;
	}
	return (a <= b + epsilon && a >= b - epsilon);
}
