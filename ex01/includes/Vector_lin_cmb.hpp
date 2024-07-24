#ifndef VECTOR_LIN_CMB_HPP
#define VECTOR_LIN_CMB_HPP

#include <cmath>

#include "Vector.hpp"

template <typename K>
Vector<K> linear_combination(std::vector< Vector<K> > const &u, std::vector<K> const &coefs);

#include "Vector_lin_cmb.tpp"


#endif