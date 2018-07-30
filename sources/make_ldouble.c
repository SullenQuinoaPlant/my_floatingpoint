#include "inner.h"

static int
	is_too_much(
		int32_t exp)
{
	if (!(exp <= LDB_MAX_EXP && exp >= LDB_MIN_EXP))
		return (1);
	return (0);
}

static int
	align_exp(
		uint64_t *times, int32_t *exp)
{
	uint64_t	const mask = (1 << LDB_MANT_RESOLUTION);

	while (*exp > LDB_MIN_EXP &&
		!(*times & mask))
	{
		*times <<= 1;
		(*exp)--;
	}
	while (*exp < LDB_MIN_EXP && *times)
	{
		*times >>= 1;
		(*exp)++;
	}
	return (!is_too_much(*exp));
}

long double
	make_ldouble(
		char s, uint64_t m, int32_t e)
{
	t_u_ld	maker;
	
	if (align_exp(&m, &e))
		return (compose_ldouble(s, m, exp_bias_ld(e)));
	else
		return (compose_inf(s));
}
