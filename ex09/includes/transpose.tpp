#ifndef TRANSPOSE_TPP
#define TRANSPOSE_TPP

#include "Matrix.hpp"

template<typename K>
Matrix<K> Matrix<K>::transpose(void) const
{
	Matrix<K> result(_shape.second, _shape.first);

	for (size_t row = 0; row < _shape.first; row++)
	{
		for (size_t col = 0; col < _shape.second; col++)
		{
			result[col][row] = (*this)[row][col];
		}
	}
	return result;
}

#endif