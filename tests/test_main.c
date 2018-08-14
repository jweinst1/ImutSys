#include <stdlib.h>
#include <string.h>

#include "Copper.h"
#include "test_util.h"

int main(int argc, char const *argv[])
{
	TEST_IS_EQ("int test", Copper_new_int(3), 6);
	return 0;
}