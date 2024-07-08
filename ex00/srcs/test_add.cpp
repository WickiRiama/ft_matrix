#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "Matrix.hpp"

Test(Add, matrixAdd)
{
	Matrix<float> mat1;
	Matrix<float> mat2;
	Matrix<float> mat3({{1.0, 8}, {-1, 3.6}});
	Matrix<float> mat4({{4, -12}, {-6, 9.6}});

	Matrix<float> result1;
	Matrix<float> result2({{5, -4}, {-7, 13.2}});
	mat1.add(mat2);
	cr_expect(mat1 == result1);
	mat3.add(mat4);
	std::cout << mat3 << std::endl;
	cr_expect(mat3 == result2);
}
