#ifndef TRACE_TPP
#define TRACE_TPP

#include <cmath>

#include "Matrix.hpp"

template<typename K>
K Matrix<K>::trace(void) const
{
	if (!this->isSquare())
	{
		throw std::length_error("Attempt to get the trace of a non square matrix.");
	}
	std::pair<size_t, size_t> shape = this->getShape();
	K result = K();

	for (size_t i = 0; i < shape.first; i++)
	{
		result += (*this)[i][i];
	}
	return result;
}

#endif