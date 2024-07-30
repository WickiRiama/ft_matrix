#ifndef MAT_MUL_TPP
#define MAT_MUL_TPP

#include <cmath>

#include "Matrix.hpp"

template<typename K>
Matrix<K> Matrix<K>::mul_mat(Matrix<K> const &mat) const
{
	std::pair<size_t, size_t> self_shape = this->getShape();
	std::pair<size_t, size_t> mat_shape = mat.getShape();
	size_t m = self_shape.first;
	size_t n = mat_shape.second;

	if (self_shape.second != mat_shape.first)
	{
		throw std::length_error("Attempt to multiply a matrix of " + std::to_string(self_shape.second) + " columns with a matrix of " + std::to_string(mat_shape.first) + " rows.");
	}

	size_t p = self_shape.second;
	
	Matrix<float> result(m, n);

	for (size_t self_row = 0; self_row < m; self_row++)
	{
		for (size_t mat_col = 0; mat_col < n; mat_col++)
		{
			for (size_t p_i = 0; p_i < p; p_i++)
			{
				result[self_row][mat_col] = fma((*this)[self_row][p_i], mat[p_i][mat_col], result[self_row][mat_col]);
			}
		}
	}
	return result;
}

template<typename K>
Vector<K> Matrix<K>::mul_vec(Vector<K> const &vec) const
{
	std::pair<size_t, size_t> self_shape = this->getShape();
	size_t n = vec.getSize();
	size_t m = self_shape.first;

	if (self_shape.second != n)
	{
		throw std::length_error("Attempt to multiply a matrix of " + std::to_string(self_shape.second) + " columns with a vector of " + std::to_string(n) + " elements.");
	}

	Vector<K> result(m);
	for (size_t row = 0; row < n; row++)
	{
		for (size_t col = 0; col < m; col++)
		{
			result[row] = fma((*this)[row][col], vec[col], result[row]);
		}
	}
	return result;
}

#endif