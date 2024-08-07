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
	K result = K();

	for (size_t i = 0; i < _shape.first; i++)
	{
		result += (*this)[i][i];
	}
	return result;
}

#endif