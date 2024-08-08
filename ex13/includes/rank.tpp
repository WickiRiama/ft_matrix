#ifndef RANK_TPP
#define RANK_TPP

#include "Matrix.hpp"

template <typename K>
size_t Matrix<K>::rank(void) const
{
	size_t result = 0;
	Matrix<K> echeloned = this->row_echelon();
	for (size_t row = 0; row < _shape.first; row++)
	{
		for (size_t col = 0; col < _shape.second; col++)
		{
			if (!isEqual(echeloned[row][col], 0))
			{
				result++;
				break ;
			}
		}
	}
	return result;
}


#endif