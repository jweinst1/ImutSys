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

copper_t* Copper_replace(copper_t* ct);

#endif //COPPER_MAKE_H