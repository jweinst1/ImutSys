#ifndef COPPER_TYPES_H
#define COPPER_TYPES_H

#include <stdlib.h>

// Macro to get size of copper_t
// This is an indexable size, how many integers in the body of the chunk,
// not the size in bytes
#define COPPER_T_SIZE(ct) (ct->data[0])
// Macro to get size in bytes of a copper_t struct.
// Accounts for body memory and size field.
#define COPPER_T_SIZEOF(ct) (sizeof(copper_t) + sizeof(int32_t) * (ct->data[0]))
// Allows calculation of in bytes size of copper_t from desired
// amount of 32-bit signed integers.
#define COPPER_T_SIZE_CON(amnt) (sizeof(copper_t) + sizeof(int32_t) * amnt)
// Allocates a block of memory for a copper_t with capacity number of signed 32-bit 
// integers
#define COPPER_T_ALLOC(capacity) malloc(sizeof(copper_t) + sizeof(int32_t) * capacity)

#define COPPER_T_DEL(ct) free(ct)
// Macro that corresponds to beginning point of the data body in a copper_t
#define COPPER_T_BEGIN(ct) (ct->data + 1)
// Macro that corresponds to the end point of the data body in a copper_t
#define COPPER_T_END(ct) (ct->data + ct->data[0] + 1)
// Macro that expands to an i32 offset in the data body of copper_t
#define COPPER_T_OFFSET(ct, i) (ct->data + i + 1)
// Macro to allow random access of copper_t data body
#define COPPER_T_AT(ct, i) (ct->data[i + 1])
// Equality check if a copper_t is a specific kind
#define COPPER_T_IS_KIND(ct, k) (ct->data[0] == k)

// Enum to represent type markers that are prefixed to Copper formatted data
typedef enum
{
	copper_kind_bool
} copper_kind;

/* copper_t struct
* Main struct responsible for holding Copper formatted data.
* data = The field in which 32-bit signed integers represent the data of copper object.
       . The is aligned along 32-bit signed integers, does not use differently aligned data sizes.
       . The first integer is always the size of the allocated memory for that data chunk.
       . The second and later integers represent the copper object itself.
* The structure of a copper_t struct is
* {size}{data...}
* copper_t is always dynamically allocated, as it's data exists on the tail padding
* of the struct. It prevents using a arr[] or arr[0] parameter for compatibility.
*/
typedef struct
{
	int32_t data[1];
} copper_t;

#endif // COPPER_TYPES_H