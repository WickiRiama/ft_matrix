#include <criterion/criterion.h>
#include <sstream>
#include <iostream>

#include "rank.hpp"

Test(Rank, empty)
{
	cr_expect(1 == 1);
}
