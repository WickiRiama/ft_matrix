#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "cosine.hpp"

Test(Cosine, empty)
{
	cr_assert(1 == 1);
}
