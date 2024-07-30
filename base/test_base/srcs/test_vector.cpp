#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "Vector.hpp"

Test(VectorClass, defaultConstructor)
{
	Vector<float> my_vec;
	cr_expect(my_vec.getSize() == 0);

	std::stringstream ss;
	ss << my_vec;

	cr_expect(strcmp(ss.str().c_str(), "[]") == 0);
}

Test(VectorClass, vectorConstructor)
{
	Vector<float> my_vec1({1, 2, 3});
	Vector<float> my_vec2(std::vector<float>(1, 1.f));
	Vector<float> my_vec3({-1, -2, -3});
	Vector<float> my_vec4({-1.5, 2.5, 300, 8});

	cr_expect(my_vec1.getSize() == 3);
	cr_expect(my_vec2.getSize() == 1);
	cr_expect(my_vec3.getSize() == 3);
	cr_expect(my_vec4.getSize() == 4);

	std::stringstream ss;
	ss << my_vec1;
	cr_expect(strcmp(ss.str().c_str(), "[1, 2, 3]") == 0);

	ss.str("");
	ss << my_vec2;
	cr_expect(strcmp(ss.str().c_str(), "[1]") == 0);

	ss.str("");
	ss << my_vec3;
	cr_expect(strcmp(ss.str().c_str(), "[-1, -2, -3]") == 0);

	ss.str("");
	ss << my_vec4;
	cr_expect(strcmp(ss.str().c_str(), "[-1.5, 2.5, 300, 8]") == 0);

}

Test(VectorClass, shapeConstructor)
{
	Vector<float> my_vec(2);
	cr_expect(my_vec.getSize() == 2);

	std::stringstream ss;
	ss << my_vec;
	cr_expect(ss.str() == "[0, 0]");

	my_vec = Vector<float>(0);
	cr_expect(my_vec.getSize() == 0);

	ss.str("");
	ss << my_vec;
	cr_expect(ss.str() == "[]");
}


Test(VectorClass, copyConstructor)
{
	Vector<float> my_vec1;
	Vector<float> my_vec2({-1.5, 2.5, 300, 8});

	Vector<float> copy_vec1(my_vec1);
	Vector<float> copy_vec2(my_vec2);

	cr_expect(copy_vec1.getSize() == 0);
	cr_expect(copy_vec2.getSize() == 4);

	std::stringstream ss;
	ss << copy_vec1;
	cr_expect(strcmp(ss.str().c_str(), "[]") == 0);

	ss.str("");
	ss << copy_vec2;
	cr_expect(strcmp(ss.str().c_str(), "[-1.5, 2.5, 300, 8]") == 0);
}

Test(VectorClass, equalityOperator)
{
	Vector<float> my_vec1;
	Vector<float> my_vec2({-1.5, 2.5, 300, 8});
	Vector<float> my_vec3;
	Vector<float> my_vec4({-1.5, 2.5, 300, 8});

	bool result = (my_vec1 == my_vec3);
	cr_expect(result);
	result = (my_vec1 == my_vec2);
	cr_expect(!result);
	result = (my_vec4 == my_vec2);
	cr_expect(result);
	result = (my_vec4 == my_vec3);
	cr_expect(!result);
}

Test(VectorClass, toColMatrix)
{
	Vector<float> my_vec1;
	Vector<float> my_vec2({-1.5, 2.5, 300, 8});

	Matrix<float> mat1 = my_vec1.toColMatrix();
	Matrix<float> mat1_check;
	cr_expect(mat1 == mat1_check);

	Matrix<float> mat2 = my_vec2.toColMatrix();
	Matrix<float> mat2_check({{-1.5}, {2.5}, {300}, {8}});
	cr_expect(mat2 == mat2_check);
}

Test(VectorClass, toRowMatrix)
{
	Vector<float> my_vec1;
	Vector<float> my_vec2({-1.5, 2.5, 300, 8});

	Matrix<float> mat1 = my_vec1.toRowMatrix();
	Matrix<float> mat1_check;
	cr_expect(mat1 == mat1_check);

	Matrix<float> mat2 = my_vec2.toRowMatrix();
	Matrix<float> mat2_check({{-1.5, 2.5, 300, 8}});
	cr_expect(mat2 == mat2_check);
}
