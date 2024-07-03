#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "Matrix.hpp"

Test(MatrixClass, defaultConstructor)
{
	Matrix<float> my_mat;
	std::pair<size_t, size_t> result = {0, 0};
	cr_expect(my_mat.getShape() == result);

	std::stringstream ss;
	ss << my_mat;

	cr_expect(strcmp(ss.str().c_str(), "[]") == 0);
}

Test(MatrixClass, vectorConstructor)
{
	Matrix<float> my_mat1({{1, 2, 3}, {10, 20, 30}, {11, 22, 33}});
	std::vector< std::vector<float> > test_vec;
	test_vec.push_back({1});
	Matrix<float> my_mat2(test_vec);
	Matrix<float> my_mat3({{-1, -2, -3}, {-10, -20, -30}});
	Matrix<float> my_mat4({{-1.5, 2.5, 300, 8}, {-1.5, 2.5, 300, 8}});

	std::pair<size_t, size_t> result = {3, 3};
	cr_expect(my_mat1.getShape() == result);
	result = {1, 1};
	cr_expect(my_mat2.getShape() == result);
	result = {2, 3};
	cr_expect(my_mat3.getShape() == result);
	result = {2, 4};
	cr_expect(my_mat4.getShape() == result);

	std::stringstream ss;
	ss << my_mat1;
	cr_expect(strcmp(ss.str().c_str(), "[[1, 2, 3],\n [10, 20, 30],\n [11, 22, 33]]") == 0);

	ss.str("");
	ss << my_mat2;
	cr_expect(strcmp(ss.str().c_str(), "[[1]]") == 0);

	ss.str("");
	ss << my_mat3;
	cr_expect(strcmp(ss.str().c_str(), "[[-1, -2, -3],\n [-10, -20, -30]]") == 0);

	ss.str("");
	ss << my_mat4;
	cr_expect(strcmp(ss.str().c_str(), "[[-1.5, 2.5, 300, 8],\n [-1.5, 2.5, 300, 8]]") == 0);
}

Test(MatrixClass, copyConstructor)
{
	Matrix<float> my_mat1;
	Matrix<float> my_mat2({{-1.5, 2.5}, {300, 8}});

	Matrix<float> copy_mat1(my_mat1);
	Matrix<float> copy_mat2(my_mat2);

	std::pair<size_t, size_t> result = {0, 0};
	cr_expect(copy_mat1.getShape() == result);
	result = {2, 2};
	cr_expect(copy_mat2.getShape() == result);

	std::stringstream ss;
	ss << copy_mat1;
	cr_expect(strcmp(ss.str().c_str(), "[]") == 0);

	ss.str("");
	ss << copy_mat2;
	cr_expect(strcmp(ss.str().c_str(), "[[-1.5, 2.5],\n [300, 8]]") == 0);
}

Test(MatrixClass, isSquared)
{
	Matrix<float> my_mat1;
	Matrix<float> my_mat2({{-1.5, 2.5}, {300, 8}});
	Matrix<float> my_mat3({{-1.5, 2.5}, {300, 8}, {7, 900}});
	Matrix<float> my_mat4({{-1.5, 2.5, 9}, {300, 8, 1.5}});

	cr_expect(my_mat1.isSquare() == true);
	cr_expect(my_mat2.isSquare() == true);
	cr_expect(my_mat3.isSquare() == false);
	cr_expect(my_mat3.isSquare() == false);
}
