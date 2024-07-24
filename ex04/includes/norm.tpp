#ifndef NORM_TPP
#define NORM_TPP

#include <cmath>

#include "Vector.hpp"

template <typename K>
float Vector<K>::norm_1(void)
{
	size_t size = this->getSize();
	float result = 0;
	for (size_t i = 0; i < size; i++)
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

#endif