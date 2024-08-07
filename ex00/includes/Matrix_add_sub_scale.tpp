#ifndef MATRIX_ADD_SUB_SCALE_TPP
#define MATRIX_ADD_SUB_SCALE_TPP

#include "Matrix.hpp"

//=============================================================================
// Methods
//=============================================================================

template <typename K>
void Matrix<K>::add(Matrix<K> const &m)
{
	if (m._shape != this->_shape)
	{
		throw std::length_error("Matrices with different sizes");
	}
	for (size_t row = 0; row < _shape.first; row++)
	{
		for (size_t col = 0; col < _shape.second; col++)
		{
			(*this)[row][col] += m[row][col];
		}
	}
}

template <typename K>
void Matrix<K>::sub(Matrix<K> const &m)
{
	if (m._shape != this->_shape)
	{
		throw std::length_error("Matrices with different sizes");
	}
	for (size_t row = 0; row < _shape.first; row++)
	{
		for (size_t col = 0; col < _shape.second; col++)
		{
			(*this)[row][col] -= m[row][col];
		}
	}
}

template <typename K>
void Matrix<K>::scl(K const a)
{
	for (size_t row = 0; row < _shape.first; row++)
	{
		for (size_t col = 0; col < _shape.second; col++)
		{
			(*this)[row][col] *= a;
		}
	}
}


#endif