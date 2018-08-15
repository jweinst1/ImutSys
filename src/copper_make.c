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