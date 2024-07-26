#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "cosine.hpp"

Test(Cosine, empty)
{
	Vector<float> u({1, 2});
	Vector<float> v({0, 0});
	try
	{
	float result = angle_cos(u, v);
	std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
