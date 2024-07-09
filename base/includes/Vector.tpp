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
bool Vector<K>::operator==(Vector<K> const &b) const
{
	size_t size = this->getSize();
	if (b.getSize() != size)
	{
		return false;
	}
	for (size_t i = 0; i < size; i++)
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
	os << "[";
	for (size_t i = 0; i < vec.getSize(); i++)
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
	return _vector.size();
}

template <typename K>
Matrix<K> Vector<K>::toColMatrix(void) const
{
	size_t size = this->getSize();
	if (size == 0)
	{
		return Matrix<K>();
	}

	std::vector< std::vector<K> > outvector;
	for (size_t k = 0; k < size; k++)
	{
		std::vector<K> invector(1, (*this)[k]);
		outvector.push_back(invector);
	}

	return Matrix<K>(outvector);
}

template <typename K>
Matrix<K> Vector<K>::toRowMatrix(void) const
{
	size_t size = this->getSize();
	if (size == 0)
	{
		return Matrix<K>();
	}

	std::vector< std::vector<K> > outvector;
	std::vector<K> invector;
	for (size_t k = 0; k < size; k++)
	{
		invector.push_back((*this)[k]);
	}
	outvector.push_back(invector);
	
	return Matrix<K>(outvector);
}


#endif