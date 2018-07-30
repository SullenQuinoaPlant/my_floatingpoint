#include "inner.h"

/*need not worry about overflows if exp is within bounds*/

uint32_t
	trueexp_bias_d(
		int32_t exp)
{
	return ((uint32_t)(exp + DB_MANT_PRECISION + DB_E_BIAS));
}

int32_t
	exp_unbias_d(
		uint16_t pow)
{
	if (pow)
		return ((int32_t)pow - DB_E_BIAS);
	else
		return (DB_MIN_EXP);
}

uint16_t
	trueexp_bias_ld(
		int32_t exp)
{
	return ((uint16_t)(exp + LDB_MANT_PRECISION + LDB_E_BIAS));
}

int32_t
	exp_unbias_ld(
		uint16_t pow)
{
	if (pow)
		return ((int32_t)pow - LDB_E_BIAS);
	else
		return (LDB_MIN_EXP);
}
