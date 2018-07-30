#include "inner.h"

/*need not worry about overflows if exp is within bounds*/

uint32_t
	exp_bias_d(
		int32_t exp)
{
	return ((uint32_t)(exp + DB_E_BIAS));
}

int32_t
	exp_unbias_d(
		uint32_t pow)
{
	if (pow)
		return ((int32_t)pow - DB_E_BIAS);
	else
		return (DB_MIN_EXP);
}

uint32_t
	exp_bias_ld(
		int32_t exp)
{
	return ((uint32_t)(exp + LDB_E_BIAS));
}

int32_t
	exp_unbias_ld(
		uint32_t pow)
{
	if (pow)
		return ((int32_t)pow - LDB_E_BIAS);
	else
		return (LDB_MIN_EXP);
}
