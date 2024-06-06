#include <criterion.h>
#include <iostream>

#include "Vector.hpp"

int main()
{
	Test(Vector, defaultConstructor)
	{
		Vector<float> my_vec;
		cr_expect(my_vec.getSize() == 0);
		std::cout << my_vec << std::endl;
	}

	// Vector<float> vec2({1, 56, -89, 8.5});
	// std::cout << "Vector of size " << vec2.getSize() << ":" << std::endl;
	// std::cout << vec2 << std::endl;

}