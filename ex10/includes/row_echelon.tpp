#ifndef ROW_ECHELON_TPP
#define ROW_ECHELON_TPP

#include "Matrix.hpp"

// Search the index of the maximum value in the column 'col', in the matrix 'mat', below the row 'from'
template<typename K>
size_t column_max_index(Matrix<K> const &mat, size_t col, size_t from)
{
	std::pair<size_t, size_t> shape = mat.getShape();
	float max_value = mat[from][col];
	size_t max_index = from;
	for (size_t row = from; row < shape.first; row++)
	{
		if (mat[row][col] > max_value)
		{
			max_index = row;
			max_value = mat[row][col];
		}
	}
	return max_index;
}

template<typename K>
void row_switch(std::vector<K> &row1, std::vector<K> &row2)
{
	std::vector<K> tmp;
	tmp = row1;
	row1 = row2;
	row2 = tmp;
}

template<typename K>
void row_multiplication(std::vector<K> &row, K n)
{
	if (n == K())
	{
		throw std::invalid_argument("Multpilication by 0 is not allowed");
	}
	size_t size = row.size();
	for (size_t i = 0; i < size; i++)
	{
		row[i] *= n;
		if (isEqual(row[i], 0))
		{
			row[i] = 0;
		}
	}
}

template<typename K>
void row_add_mul(std::vector<K> &row1, std::vector<K> const &row2, K n)
{
	if (n == K())
	{
		throw std::invalid_argument("Multpilication by 0 is not allowed");
	}
	size_t size = row1.size();
	if (size != row2.size())
	{
		throw std::length_error("Matrix rows with different sizes");
	}
	for (size_t i = 0; i < size; i++)
	{
		row1[i] += n * row2[i];
		if (isEqual(row1[i], 0))
		{
			row1[i] = 0;
		}
	}
}


template<typename K>
Matrix<K> Matrix<K>::row_echelon(void) const
{
	Matrix<K> result(*this);
	std::pair<size_t, size_t> shape = this->getShape();
	size_t row = 0;
	for (size_t col = 0; col < shape.second && row < shape.first; col++)
	{
		size_t max_i = column_max_index(result, col, row);

		if (result[max_i][col] != 0)
		{
			if (max_i != row)
			{
				row_switch(result[row], result[max_i]); // Puts the row with the max value in column col up
			}
			row_multiplication(result[row], 1 / result[row][col]); // Transforms leading coefficient to 1

			for (size_t r_i = 0; r_i < shape.first; r_i ++) // Transforms other values in column col to 0
			{
				if (r_i != row && !isEqual(result[r_i][col], 0))
				{
					row_add_mul(result[r_i], result[row], -1 * result[r_i][col]);
				}
			}
			row++;
		}
	}
	return result;
}

#endif