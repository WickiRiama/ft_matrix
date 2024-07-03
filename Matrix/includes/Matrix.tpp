#ifndef MATRIX_TPP
#define MATRIX_TPP

#include "Matrix.hpp"

//=============================================================================
// Constructors
//=============================================================================

template <typename K>
Matrix<K>::Matrix(std::vector<std::vector<K>> mat)
{
	_matrix = mat;
}

template <typename K>
Matrix<K>::Matrix(Matrix<K> const &src)
{
	*this = src;
}

template <typename K>
Matrix<K>::~Matrix(){};

//=============================================================================
// Operators
//=============================================================================

template <typename K>
Matrix<K> &Matrix<K>::operator=(Matrix<K> const &rhs)
{
	if (this != &rhs)
	{
		_matrix = rhs._matrix;
	}
	return *this;
}

template <typename K>
std::vector<K> &Matrix<K>::operator[](std::size_t idx)
{
	return _matrix[idx];
}

template <typename K>
const std::vector<K> &Matrix<K>::operator[](std::size_t idx) const
{
	return _matrix[idx];
}

template <typename K>
std::ostream &operator<<(std::ostream &os, const Matrix<K> &mat)
{
	os << "[";
	for (size_t row = 0; row < mat.getSize().first; row++)
	{
		if (row != 0)
		{
			os << " ";
		}
		os << "[";
		for (size_t col = 0; col < mat[row].size(); col++)
		{
			if (col != 0)
			{
				os << ", ";
			}
			os << mat[row][col];
		}
		os << "]";
		if (row != mat.getSize().first - 1)
		{
			os << "," << std::endl;
		}
	}
	os << "]";

	return os;
}

//=============================================================================
// Getters
//=============================================================================

template <typename K>
std::pair<size_t, size_t> Matrix<K>::getSize(void) const
{
	if (_matrix.size() == 0)
	{
		return {0, 0};
	}
	else
	{
		return {_matrix.size(), _matrix[0].size()};
	}
}

#endif