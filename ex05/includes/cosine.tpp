#ifndef COSINE_TPP
#define COSINE_TPP

#include "dot_product.hpp"
#include "norm.hpp"

template <typename K>
float angle_cos(Vector<K> const &u, Vector<K> const &v)
{
	if (u.getSize() != v.getSize())
	{
		throw std::length_error("Vectors with different sizes.");
	}

	if (u.norm() == 0 || v.norm() == 0)
	{
		throw std::runtime_error("Attempt to divide by 0.");
	}

	return (u.dot(v) / u.norm() / v.norm());
}


#endif