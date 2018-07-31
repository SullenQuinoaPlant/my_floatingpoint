#include "inner.h"

double
	compose_inf(
		char sign)
{
	if (sign)
		return (compose_minf());
	return (compose_pinf());
}

long double
	compose_ldouble(
		char sign, uint64_t times, uint16_t power)
{
	t_u_ld	mapper;

	mapper.sign = sign ? 1 : 0;
	mapper.exp = power;
	mapper.mant = times;
	return (mapper.ld);
}

double
	compose_minf()
{
	t_u_d	mapper;

	mapper.sign = 1;
	mapper.exp = ~0;
	mapper.mant = (1ul << (DB_MANT_BITS - 1));
	return (mapper.d);
}

double
	compose_nan()
{
	t_u_d	mapper;

	mapper.sign = 0;
	mapper.exp = ~0;
	mapper.mant = 0;
	return (mapper.d);
}

double
	compose_pinf()
{
	t_u_d	mapper;

	mapper.sign = 0;
	mapper.exp = ~0;
	mapper.mant = (1ul << (DB_MANT_BITS - 1));
	return (mapper.d);
}
