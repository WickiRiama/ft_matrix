#ifndef VECTOR_TPP
#define VECTOR_TPP

#include "Vector.hpp"

//=============================================================================
// Constructors
//=============================================================================

template <typename K>
Vector<K>::Vector(std::vector<K> vec)
{
	_size = vec.size();
	_vector = vec;
}

template <typename K>
Vector<K>::Vector(size_t n)
{
	_size = n;
	for (size_t i = 0; i < n; i++)
	{
		_vector.push_back(K());
	}
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
		_size = rhs._size;
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
bool Vector<K>::operator==(Vector<K> const &b) const
{
	if (b._size != this->_size)
	{
		return false;
	}
	for (size_t i = 0; i < _size; i++)
	{
		if (!isEqual((*this)[i], b[i]))
		{
			return false;
		}
	}
	return true;
}

template <typename K>
std::ostream& operator<<(std::ostream& os, const Vector<K> &vec)
{
	size_t size = vec.getSize();
	os << "[";
	for (size_t i = 0; i < size; i++)
	{
		if (i != 0)
		{
			os << ", ";
		}
		os << vec[i];
	}
	os << "]";

	return os;
}



//=============================================================================
// Getters
//=============================================================================

template <typename K>
size_t Vector<K>::getSize(void) const
{
	return _size;
}

template <typename K>
Matrix<K> Vector<K>::toColMatrix(void) const
{
	if (_size == 0)
	{
		return Matrix<K>();
	}

	std::vector< std::vector<K> > outvector;
	for (size_t k = 0; k < _size; k++)
	{
		std::vector<K> invector(1, (*this)[k]);
		outvector.push_back(invector);
	}

	return Matrix<K>(outvector);
}

template <typename K>
Matrix<K> Vector<K>::toRowMatrix(void) const
{
	if (_size == 0)
	{
		return Matrix<K>();
	}

	std::vector< std::vector<K> > outvector;
	std::vector<K> invector;
	for (size_t k = 0; k < _size; k++)
	{
		invector.push_back((*this)[k]);
	}
	outvector.push_back(invector);
	
	return Matrix<K>(outvector);
}


#endif