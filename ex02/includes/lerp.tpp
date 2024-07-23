#ifndef LERP_TPP
#define LERP_TPP

#include <cmath>

#include "Vector_lin_cmb.hpp"

template <typename K>
K lerp(K const u, K const v, float t)
{
	return fma(t, v - u, u);
}

template <typename K>
Vector<K> lerp(Vector<K> const &u, Vector<K> const &v, float t)
{
	size_t size = u.getSize();
	if (size != v.getSize())
	{
		throw std::length_error("Vectors with different sizes");
	}
	Vector<K> result(u);
	for (size_t i = 0; i < size; i++)
	{
		result[i] = fma(t, v[i] - u[i], u[i]);
	}
	return result;
}

#endif