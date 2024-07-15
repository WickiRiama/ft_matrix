#ifndef VECTOR_ADD_SUB_SCALE_TPP
#define VECTOR_ADD_SUB_SCALE_TPP

#include "Vector.hpp"

//=============================================================================
// Methods
//=============================================================================

template <typename K>
void Vector<K>::add(Vector<K> const &v)
{
	size_t size = this->getSize();
	if (v.getSize() != size)
	{
		throw std::length_error("Vectors with different sizes");
	}
	for (size_t i = 0; i < size; i++)
	{
			(*this)[i] += v[i];
	}
}

template <typename K>
void Vector<K>::sub(Vector<K> const &v)
{
	size_t size = this->getSize();
	if (v.getSize() != size)
	{
		throw std::length_error("Vectors with different sizes");
	}
	for (size_t i = 0; i < size; i++)
	{
		(*this)[i] -= v[i];
	}
}

#endif