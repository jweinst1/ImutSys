#ifndef COPPER_UTILS_H
#define COPPER_UTILS_H

#include <stdint.h>
#include <string.h>

// Util functions used in copper related to int32_t data
// Provides optimization for 4-byte aligned data vs byte aligned data

// Macro to copy two same typed pointers n times.
// Note: Does not cast pointers or parenthesize, will not work for all expressions
#define _UTIL_COPY(i, j, n) for(int amnt = n; amnt > 0 ; amnt--) *i++ = *j++

/**
  * Fast, small function to copy data aligned on 32-bit signed boundaries.
  * More effecient than memcpy because does not use unsigned char* to copy.
  */
static inline void
Copper_util_copy_i32(int32_t* dest, int32_t* src, int32_t len)
{
	while(len--) *dest++ = *src++;
}


#endif //COPPER_UTILS_H