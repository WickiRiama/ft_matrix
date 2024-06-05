#ifndef VECTOR_TPP
#define VECTOR_TPP

#include "Vector.hpp"

//=============================================================================
// Constructors
//=============================================================================

template <typename K>
Vector<K>::Vector(std::vector<K> vec)
{
	_vector = vec;
}

template <typename K>
Vector<K>::Vector(Vector<K> const &src)
{
	*this = src;
}

template <typename K>
Vector<K>::~Vector(){};

//=============================================================================
// Operators
//=============================================================================

template <typename K>
Vector<K> &Vector<K>::operator=(Vector<K> const &rhs)
{
	if (this != &rhs)
	{
		_vector = rhs._vector;
	}
	return *this;
}

template <typename K>
K &Vector<K>::operator[](std::size_t idx)
{
	return _vector[idx];
}

template <typename K>
const K &Vector<K>::operator[](std::size_t idx) const
{
	return _vector[idx];
}


template <typename K>
std::ostream& operator<<(std::ostream& os, const Vector<K> &vec)
{
	std::cout << "[";
	for (size_t i = 0; i < vec.getSize(); i++)
	{
		if (i != 0)
		{
			os << ", ";
		}
		os << vec[i];
	}
	os << "]" << std::endl;

	return os;
}


//=============================================================================
// Getters
//=============================================================================

template <typename K>
size_t Vector<K>::getSize(void) const
{
	return _vector.size();
}

#endif