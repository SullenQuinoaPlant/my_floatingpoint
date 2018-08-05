#include "inner.h"

long double
	floorl(
		long double d)
{
	t_s_dfp		dec;
	int32_t		pow;

	decompose_ldouble(&d, &dec);
	if ((pow = dec.exp - LDB_MANT_PRECISION) >= 0)
		return (d);
	dec.mant &= ~((uint64_t)0) << -pow;
	if ((d = make_ldouble(d < 0, dec.mant, pow)) <= 0)
		d -= 1;
	return (d);
}
