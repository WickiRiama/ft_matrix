#include "Vector.hpp"

int main(void)
{
	Vector<float> my_vec1;
	Vector<float> my_vec2({-1.5, 2.5, 300, 8});

	Matrix<float> mat2 = my_vec2.toColMatrix();
	Matrix<float> mat2_check({{-1.5}, {2.5}, {300}, {8}});
	if (mat2 == mat2_check)
	{
		return 0;
	}
	return 1;
}