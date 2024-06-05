#include <iostream>

#include "Vector.hpp"

int main()
{
	Vector<float> my_vec;
	std::cout << "Vector of size " << my_vec.getSize() << ":" << std::endl;
	std::cout << my_vec << std::endl;

	Vector<float> vec2({1, 56, -89, 8.5});
	std::cout << "Vector of size " << vec2.getSize() << ":" << std::endl;
	std::cout << vec2 << std::endl;

}