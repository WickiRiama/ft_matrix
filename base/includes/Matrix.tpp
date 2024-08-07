#ifndef MATRIX_TPP
#define MATRIX_TPP

#include <iostream>

#include "Matrix.hpp"

//=============================================================================
// Constructors
//=============================================================================

template <typename K>
Matrix<K>::Matrix(std::vector<std::vector<K>> mat)
{
	_shape.first = mat.size();
	_shape.second = 0;
	if (mat.size() > 0)
	{
		_shape.second = mat[0].size();
		for (size_t row = 1; row < mat.size(); row++)
		{
			if (mat[row].size() != _shape.second)
			{
				throw std::length_error("Rows with different sizes");
			}
		}
	}
	_matrix = mat;
}

template <typename K>
Matrix<K>::Matrix(size_t n_rows, size_t n_cols) : _shape({n_rows, n_cols})
{
	for (size_t row = 0; row < n_rows; row++)
	{
		std::vector<K> tmp;
		for (size_t col = 0; col < n_cols; col++)
		{
			tmp.push_back(K());
		}
		_matrix.push_back(tmp);
	}
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
		_shape = rhs._shape;
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
bool Matrix<K>::operator==(Matrix<K> const &b) const
{
	if (b._shape != this->_shape)
	{
		return false;
	}
	for (size_t row = 0; row < _shape.first; row++)
	{
		for (size_t col = 0; col < _shape.second; col++)
		{
			if (!isEqual((*this)[row][col], b[row][col]))
			{
				return false;
			}
		}
	}
	return true;
}

template <typename K>
std::ostream &operator<<(std::ostream &os, const Matrix<K> &mat)
{
	std::pair<size_t, size_t> shape = mat.getShape();
	os << "[";
	for (size_t row = 0; row < shape.first; row++)
	{
		if (row != 0)
		{
			os << " ";
		}
		os << "[";
		for (size_t col = 0; col < shape.second; col++)
		{
			if (col != 0)
			{
				os << ", ";
			}
			os << mat[row][col];
		}
		os << "]";
		if (row != shape.first - 1)
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
std::pair<size_t, size_t> Matrix<K>::getShape(void) const
{
	return _shape;
}

template <typename K>
bool Matrix<K>::isSquare(void) const
{
	return _shape.first == _shape.second;
}

//=============================================================================
// Methods
//=============================================================================

template <typename K>
Vector<K> Matrix<K>::toVector(void) const
{
	std::vector<K> result;
	if (_shape.first == 1)
	{
		result = (*this)[0];
	}
	else if (_shape.second == 1)
	{
		for (size_t row = 0; row < _shape.first; row++)
		{
			result.push_back((*this)[row][0]);
		}
	}
	else
	{
		std::cerr << "This matrix can't be converted to a vector (too many dimensions)" << std::endl;
	}
	return Vector<K>(result);
}

#endif