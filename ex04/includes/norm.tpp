#ifndef NORM_TPP
#define NORM_TPP

#include <cmath>

#include "Vector.hpp"

// Manhattan norm
template <typename K>
float Vector<K>::norm_1(void) const
{
	float result = 0;
	for (size_t i = 0; i < _size; i++)
	{
		if ((*this)[i] < 0)
		{
			result = fma(-1., (*this)[i], result);
		}
		else
		{
			result += (*this)[i];
		}
	}
	return result;
}

// Euclidian norm
template <typename K>
float Vector<K>::norm(void) const
{
	float result = 0;

	for (size_t i = 0; i < _size; i++)
	{
		result = fma((*this)[i], (*this)[i], result);
	}

	return powf32(result, 0.5);
}

// Supremum norm
template <typename K>
float Vector<K>::norm_inf(void) const
{
	float result = 0;

	for (size_t i = 0; i < _size; i++)
	{
		result = std::max(result, std::max((*this)[i], -1 * (*this)[i]));
	}

	return result;
}


#endif