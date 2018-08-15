#include <stdlib.h>
#include <string.h>

#include "Copper.h"
#include "test_util.h"

void test_copper_new(void)
{
	copper_t* test = Copper_new(4);
	TEST_IS_EQ("Copper_new()", test->data[0], 4);
	COPPER_T_DEL(test);
}

void test_copper_new_copy(void)
{
	copper_t* test = Copper_new(4);
	copper_t* test2 = Copper_new_copy(test);
	TEST_IS_EQ("Copper_new_copy()", COPPER_T_SIZE(test), COPPER_T_SIZE(test2));
	COPPER_T_DEL(test);
	COPPER_T_DEL(test2);
}


int main(int argc, char const *argv[])
{
	TEST_IS_EQ("test of test macro", 6, 6);
	test_copper_new();
	test_copper_new_copy();
	return 0;
}