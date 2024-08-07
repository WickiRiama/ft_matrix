#ifndef INVERSE_TPP
#define INVERSE_TPP

#include "Matrix.hpp"

template <typename K>
Matrix<K> Matrix<K>::augmented_matrix(void) const
{
	Matrix<K> result(_shape.first, _shape.second * 2);
	for (size_t row = 0; row < _shape.first; row++)
	{
		for (size_t col = 0; col < _shape.second; col++)
		{
			result[row][col] = (*this)[row][col];
			if (row == col)
			{
				result[row][col + _shape.second] = 1;
			}
		}
	}
	return result;
}

template <typename K>
Matrix<K> Matrix<K>::inverse(void) const
{
	if (!this->isSquare())
	{
		throw std::length_error("Attempt to get the inverse of a non square matrix.");
	}

	Matrix<K> augmented = this->augmented_matrix();
	return Matrix<K>();
}


#endif