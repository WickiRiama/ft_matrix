#ifndef TRANSPOSE_TPP
#define TRANSPOSE_TPP

#include "Matrix.hpp"

template<typename K>
Matrix<K> Matrix<K>::transpose(void) const
{
	std::pair<size_t, size_t> shape = this->getShape();
	Matrix<K> result(shape.second, shape.first);

	for (size_t row = 0; row < shape.first; row++)
	{
		for (size_t col = 0; col < shape.second; col++)
		{
			result[col][row] = (*this)[row][col];
		}
	}
	return result;
}

#endif