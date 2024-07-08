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
};

template <typename K>
std::ostream& operator<<(std::ostream& os, const Vector<K>& vec);

#include "Vector.tpp"

#endif