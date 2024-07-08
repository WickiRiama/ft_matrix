#include "Matrix.hpp"

bool isEqual(float const &a, float const &b)
{
	float epsilon = 0.000001;
	return (a < b + epsilon && a > b - epsilon);
}
