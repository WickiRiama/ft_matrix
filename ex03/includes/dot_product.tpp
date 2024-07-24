#ifndef DOT_PRODUCT_TPP
#define DOT_PRODUCT_TPP

#include <cmath>

#include "Vector.hpp"

template <typename K>
K Vector<K>::dot(Vector<K> const &v)
{
	size_t size = this->getSize();
	if (v.getSize() != size)
	{
		throw std::length_error("Vectors with different sizes");
	}

	K result = 0;
	for (size_t i = 0; i < size; i++)
	{
		result = fma((*this)[i], v[i], result);
	}
	return result;
}

#endif