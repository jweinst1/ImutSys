#ifndef TEST_UTIL_H
#define TEST_UTIL_H

#include <stdio.h>

#define TEST_IS_EQ(name, result, expected) puts(name); \
                                           if(result == expected) printf("test PASSED\n"); \
                                           else printf("test FAILED\n")

#endif