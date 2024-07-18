#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <ostream>

#include "Matrix.hpp"

template <typename K>
class Matrix;

template <typename K>
class Vector
{
	// Base ===================================================================
private:
	std::vector<K> _vector;

public:
	Vector<K>(std::vector<K> vec = std::vector<K>());
	Vector<K>(Vector<K> const &src);
	~Vector();

	Vector<K> &operator=(Vector<K> const &rhs);
	K &operator[](size_t idx);
	const K &operator[](size_t idx) const;
	bool operator==(Vector<K> const &b) const;

	size_t getSize(void) const;
	Matrix<K> toColMatrix(void) const;
	Matrix<K> toRowMatrix(void) const;

	// Add-Sub-Scale ==========================================================
public:
	void add(Vector<K> const &v);
	void sub(Vector<K> const &v);
	void scl(K const a);
};

// Operators ==================================================================
template <typename K>
std::ostream &operator<<(std::ostream &os, const Vector<K> &vec);

// Utils ======================================================================
bool isEqual(float const &a, float const &b);

// Linear Combination =========================================================
template <typename K>
Vector<K> linear_combination(std::vector< Vector<K> > const &u, std::vector<K> const &coefs);

#include "Vector.tpp"
#include "Vector_add_sub_scale.tpp"
#include "Vector_lin_cmb.tpp"

#endif