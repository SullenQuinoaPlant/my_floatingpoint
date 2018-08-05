#include "inner.h"

int
	is_nan(
		double dbl)
{
	if (dbl == compose_nan())
		return (1);
	return (0);
}

int
	is_finite(
		double dbl)
{
	return (!is_inf(dbl));
}

int
	is_inf(
		double dbl)
{
	if (dbl == compose_minf() ||
		dbl == compose_pinf())
		return (1);
	return (0);
}

int
	is_overf(
		double dbl)
{
	t_s_dfp	dec;

	decompose_double(&dbl, &dec);
	if (dec.flags & OVER_F)
		return (1);
	return (0);
}

int
	is_dnorm(
		double dbl)
{
	t_s_dfp	dec;

	decompose_double(&dbl, &dec);
	if (dec.flags & DNORM_F)
		return (1);
	return (0);
}
