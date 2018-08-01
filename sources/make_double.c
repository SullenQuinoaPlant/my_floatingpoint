#include "inner.h"

static int
	is_too_much(
		int32_t pow)
{
	return (pow > DB_MAX_POW);
}

static int
	align_exp(
		uint64_t *times, int32_t *pow)
{
	uint64_t	mask;

	mask = ~((uint64_t)0) << (DB_MANT_PRECISION);
	while (*pow > DB_MIN_POW && !(*times & mask))
	{
		*times <<= 1;
		(*pow)--;
	}
	mask <<= 1;
	while ((*pow < DB_MIN_POW && *times) ||
		(*pow >= DB_MIN_POW && *times & mask))
	{
		*times >>= 1;
		(*pow)++;
	}
	if (*pow < DB_MIN_POW)
		*times = 0;
	return (!is_too_much(*pow));
}

double
	make_double(
		char s, uint64_t m, int32_t p)
{
	if (!m)
		return (0.0);
	else if (align_exp(&m, &p))
		return (compose_double(s, m, exp_bias_ld(p)));
	else
		return (compose_inf(s));
}
