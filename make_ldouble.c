#include "inner.h"

static int
	is_too_much(
		int32_t pow)
{
	if (!(pow <= LDB_MAX_POW && pow >= LDB_MIN_POW))
		return (1);
	return (0);
}

static int
	align_exp(
		uint64_t *times, int32_t *pow)
{
	uint64_t	const mask = ((uint64_t)1 << LDB_MANT_PRECISION);

	while (*pow > LDB_MIN_POW &&
		!(*times & mask))
	{
		*times <<= 1;
		(*pow)--;
	}
	while (*pow < LDB_MIN_POW && *times)
	{
		*times >>= 1;
		(*pow)++;
	}
	return (!is_too_much(*pow));
}

long double
	make_ldouble(
		char s, uint64_t m, int32_t p)
{
	if (!m)
		return (0.0L);
	else if (align_exp(&m, &p))
		return (compose_ldouble(s, m, exp_bias_ld(p)));
	else
		return (compose_inf(s));
}
