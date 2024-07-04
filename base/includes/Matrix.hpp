#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <ostream>

#include "Vector.hpp"

// template <typename K>
// class Vector<K>;

template <typename K>
class Matrix
{
	private:
		std::vector< std::vector<K> > _matrix;

	public:
		Matrix<K>(std::vector<std::vector<K>> mat = std::vector< std::vector<K> >());
		Matrix<K>(Matrix<K> const &src);
		~Matrix();

		Matrix<K> &operator=(Matrix<K> const &rhs);
		std::vector<K> &operator[](size_t idx);
		const std::vector<K> &operator[](size_t idx) const;
		bool operator==(Matrix<K> const &b) const;

		std::pair<size_t, size_t> getShape(void) const;
		bool isSquare(void) const;
		Vector<K> toVector(void) const;

};

template <typename K>
std::ostream& operator<<(std::ostream& os, const Matrix<K>& mat);

#include "Matrix.tpp"

#endif