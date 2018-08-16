#include <assert.h>
#include "copper_make.h"
#include "copper_utils.h"


copper_t* Copper_new(int32_t size)
{
	copper_t* new_cop = COPPER_T_ALLOC(size);
	new_cop->data[0] = size;
	return new_cop;
}


copper_t* Copper_new_copy(copper_t* ct)
{
	copper_t* new_cop = COPPER_T_ALLOC(ct->data[0]);
	new_cop->data[0] = ct->data[0];
	Copper_util_copy_i32(COPPER_T_BEGIN(new_cop), COPPER_T_BEGIN(ct), COPPER_T_SIZE(ct));
	return new_cop;	
}

copper_t* Copper_new_slice(copper_t* ct, int32_t start, int32_t end)
{
	assert( start <= end);
	int32_t diff = end - start;
	copper_t* new_cop = COPPER_T_ALLOC(diff);
	new_cop->data[0] = diff;
	Copper_util_copy_i32(COPPER_T_BEGIN(new_cop), COPPER_T_OFFSET(ct, start), diff);
	return new_cop;		
}


copper_t* Copper_replace(copper_t* ct)
{
	copper_t* new_cop = COPPER_T_ALLOC(ct->data[0]);
	new_cop->data[0] = ct->data[0];
	Copper_util_copy_i32(COPPER_T_BEGIN(new_cop), COPPER_T_BEGIN(ct), COPPER_T_SIZE(ct));
	// Deletes the old copper_t
	ct->data[0] = 0;
	COPPER_T_DEL(ct);
	return new_cop;	
}

void Copper_write(copper_t* ct, int32_t* doc, int32_t pos, int32_t size)
{
	Copper_util_copy_i32(COPPER_T_OFFSET(ct, pos), doc, size);
}