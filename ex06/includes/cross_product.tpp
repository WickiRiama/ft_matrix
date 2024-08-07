#ifndef CROSS_PRODUCT_TPP
#define CROSS_PRODUCT_TPP

#include <cmath>

#include "Vector.hpp"

template<typename K>
Vector<K> cross_product(Vector<K> const &u, Vector<K> const &v)
{
	if (u.getSize() != 3 || v.getSize() != 3)
	{
		throw std::length_error("Cross product with vectors of size different than 3.");
	}

	Vector<K> result(u);
	result[0] = fma(-1.f, u[2] * v[1], u[1] * v[2]);
	result[1] = fma(-1.f, u[0] * v[2], u[2] * v[0]);
	result[2] = fma(-1.f, u[1] * v[0], u[0] * v[1]);

	return result;
}

#endif