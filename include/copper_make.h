#ifndef COPPER_MAKE_H
#define COPPER_MAKE_H

#include "copper_types.h"

// This header contains functions for creating raw instances of copper_t,
// Other specified types of copper data will build on this module.

/** use: Allocates a new copper_t of a certain size, and sets the size at
  *      the head of the data slot.
  * size: The amount of signed 32-bit integers of space to exist in this copper_t
  */
copper_t* Copper_new(int32_t size);

/* Creates a new copy of the copper_t ct
* Does not destroy the old copy
*/
copper_t* Copper_new_copy(copper_t* ct);

/* Copper Slicing
* Creates new copper_t from slice of existing copper_t
*/
copper_t* Copper_new_slice(copper_t* ct, int32_t start, int32_t end);

/* Copper_replace
* Makes a new copy of ct and then destroys ct.
*/
copper_t* Copper_replace(copper_t* ct);

/* Copper_write
* Writes data in doc into existing copper_t, at position pos
*/
void Copper_write(copper_t* ct, int32_t* doc, int32_t pos, int32_t size);

#endif //COPPER_MAKE_H