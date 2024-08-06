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
		default:
			std::cerr << "Determinant for matrices larger than 4x4 is not implemented." << std::endl;
			result = -1;
	}
	return result;
}

#endif