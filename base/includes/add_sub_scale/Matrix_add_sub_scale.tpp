#ifndef MATRIX_ADD_SUB_SCALE_TPP
#define MATRIX_ADD_SUB_SCALE_TPP

#include "Matrix.hpp"

//=============================================================================
// Methods
//=============================================================================

template <typename K>
void Matrix<K>::add(Matrix<K> const &m)
{
	std::pair<size_t, size_t> shape = this->getShape();
	if (m.getShape() != shape)
	{
		throw std::length_error("Matrices with different sizes");
	}
	for (size_t row = 0; row < shape.first; row++)
	{
		for (size_t col = 0; col < shape.second; col++)
		{
			(*this)[row][col] += m[row][col];
		}
	}
}

template <typename K>
void Matrix<K>::sub(Matrix<K> const &m)
{
	std::pair<size_t, size_t> shape = this->getShape();
	if (m.getShape() != shape)
	{
		throw std::length_error("Matrices with different sizes");
	}
	for (size_t row = 0; row < shape.first; row++)
	{
		for (size_t col = 0; col < shape.second; col++)
		{
			(*this)[row][col] -= m[row][col];
		}
	}
}

#endif