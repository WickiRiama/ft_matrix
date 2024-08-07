#ifndef LERP_TPP
#define LERP_TPP

#include <cmath>

#include "Vector.hpp"
#include "Matrix.hpp"

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
	Vector<K> result(size);
	for (size_t i = 0; i < size; i++)
	{
		result[i] = fma(t, v[i] - u[i], u[i]);
	}
	return result;
}

template <typename K>
Matrix<K> lerp(Matrix<K> const &u, Matrix<K> const &v, float t)
{
	std::pair<size_t, size_t> shape = u.getShape();
	if (shape != v.getShape())
	{
		throw std::length_error("Matrices with different sizes");
	}
	Matrix<K> result(shape.first, shape.second);
	for (size_t row = 0; row < shape.first; row++)
	{
		for (size_t col = 0; col < shape.second; col++)
		{
			result[row][col] = fma(t, v[row][col] - u[row][col], u[row][col]);
		}
	}
	return result;
}


#endif