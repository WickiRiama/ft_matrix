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
	// if (u.norm() == 0 || v.norm() == 0)
	// {
	// 	throw
	// }
	// std::cout << u.norm() << std::endl;
	return (u.norm() / 0);
}


#endif