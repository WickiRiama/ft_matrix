#ifndef DETERMINANT_TPP
#define DETERMINANT_TPP

#include <iostream>
#include <cmath>

#include "Matrix.hpp"

template <typename K>
K Matrix<K>::determinant_2x2(void) const
{
	return fma(-1 * (*this)[0][1], (*this)[1][0], (*this)[0][0] * (*this)[1][1]);
}

template <typename K>
Matrix<K> Matrix<K>::create_minor(size_t col_index) const
{
	std::pair<size_t, size_t> shape = this->getShape();
	Matrix<K> result(shape.first - 1, shape.second - 1);

	for (size_t row = 1; row < shape.first; row++)
	{
		size_t new_col = 0;
		for (size_t col = 0; col < shape.second; col++)
		{
			if (col != col_index)
			{
				result[row - 1][new_col] = (*this)[row][col];
				new_col++;
			}
		}
	}
	return result;
}

template <typename K>
K Matrix<K>::determinant_nxn(size_t n) const
{
	K result = K();
	float mul = 1;
	for (size_t i = 0; i < n; i++)
	{
		Matrix<K> tmp = create_minor(i);
		result = fma(tmp.determinant(), mul * (*this)[0][i], result);
		mul *= -1;
	}
	return result;
}


template <typename K>
K Matrix<K>::determinant(void) const
{
	if (!this->isSquare())
	{
		throw std::length_error("Attempt to get the determinant of a non square matrix.");
	}
	std::pair<size_t, size_t> shape = this->getShape();
	float result;

	switch (shape.first)
	{
		case 0:
			result = 1;
			break;
		case 1:
			result = (*this)[0][0];
			break;
		case 2:
			result = this->determinant_2x2();
			break;
		case 3:
			result = this->determinant_nxn(3);
			break;
		case 4:
			result = this->determinant_nxn(4);
			break;
		default:
			std::cerr << "Determinant for matrices larger than 4x4 is not implemented." << std::endl;
			result = -1;
	}
	return result;
}

#endif