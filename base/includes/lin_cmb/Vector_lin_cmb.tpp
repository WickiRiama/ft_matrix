#ifndef VECTOR_LIN_CMB_TPP
#define VECTOR_LIN_CMB_TPP

#include <cmath>

#include "Vector.hpp"

//=============================================================================
// Functions
//=============================================================================

template <typename K>
Vector<K> linear_combination(std::vector< Vector<K> > const &u, std::vector<K> const &coefs)
{
	size_t n_vectors = u.size();
	if (n_vectors != coefs.size())
	{
		throw std::length_error("Coefficients number different from vectors number");
	}
	if (n_vectors == 0)
	{
		return Vector<K>();
	}

	size_t n_elements = u[0].getSize();
	Vector<K> result(std::vector<K>(n_elements, 0));
	for (size_t vector_index = 0; vector_index < n_vectors; vector_index++)
	{
		if (u[vector_index].getSize() != n_elements)
		{
			throw std::length_error("Vectors with different sizes");
		}
		for (size_t i = 0; i < n_elements; i++)
		{
			result[i] = fma(u[vector_index][i], coefs[vector_index], result[i]);
		}
	}
	return result;
}


#endif