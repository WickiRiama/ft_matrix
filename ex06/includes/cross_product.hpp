#ifndef CROSS_PRODUCT_HPP
#define CROSS_PRODUCT_HPP

#include "Vector.hpp"

template<typename K>
Vector<K> cross_product(Vector<K> const &u, Vector<K> const &v);

#include "cross_product.tpp"

#endif