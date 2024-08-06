#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <ostream>

#include "Vector.hpp"

template <typename K>
class Vector;

template <typename K>
class Matrix
{
	// Base ===================================================================
private:
	std::vector<std::vector<K>> _matrix;

public:
	Matrix<K>(std::vector<std::vector<K>> mat = std::vector<std::vector<K>>());
	Matrix<K>(size_t n_rows, size_t n_col);
	Matrix<K>(Matrix<K> const &src);
	~Matrix();

	Matrix<K> &operator=(Matrix<K> const &rhs);
	std::vector<K> &operator[](size_t idx);
	const std::vector<K> &operator[](size_t idx) const;
	bool operator==(Matrix<K> const &b) const;

	std::pair<size_t, size_t> getShape(void) const;
	bool isSquare(void) const;
	Vector<K> toVector(void) const;

	// Add-Sub-Scale ==========================================================
public:
	void add(Matrix<K> const &v);
	void sub(Matrix<K> const &v);
	void scl(K const a);

	// Multiplication =========================================================
public:
	Matrix<K> mul_mat(Matrix<K> const &mat) const;
	Vector<K> mul_vec(Vector<K> const &vec) const;

	// Trace ==================================================================
public:
	K trace(void) const;

	// Transpose ==============================================================
public:
	Matrix<K> transpose(void) const;

	// Row Echelon ============================================================
public:
	Matrix<K> row_echelon(void) const;

	// Determinant ============================================================
public:
	K determinant(void) const;
};

template <typename K>
std::ostream &operator<<(std::ostream &os, const Matrix<K> &mat);

bool isEqual(float const &a, float const &b);

#include "Matrix.tpp"

#endif