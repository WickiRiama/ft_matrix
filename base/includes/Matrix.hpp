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
	std::pair<size_t, size_t> _shape;

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
private:
	size_t column_max_index(size_t col, size_t from) const;
public:
	Matrix<K> row_echelon(void) const;

	// Determinant ============================================================
private:
	Matrix<K> create_minor(size_t col) const;
	K determinant_2x2(void) const;
	K determinant_nxn(size_t n) const;
public:
	K determinant(void) const;

	// Inverse ================================================================
private:
	Matrix<K> augmented_matrix(void) const;
	bool is_singular(Matrix<K> const &echeloned) const;
public:
	Matrix<K> inverse(void) const;
};

template <typename K>
std::ostream &operator<<(std::ostream &os, const Matrix<K> &mat);

bool isEqual(float const &a, float const &b);

#include "Matrix.tpp"

#endif