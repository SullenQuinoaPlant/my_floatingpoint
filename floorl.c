#include "inner.h"

long double
	my_floorl(
		long double d)
{
	t_s_dfp		dec;
	int32_t		pow;

	decompose_ldouble(&d, &dec);
	if ((pow = dec.exp - LDB_MANT_PRECISION) >= 0)
		return (d);
	else if (pow < -LDB_MANT_PRECISION)
		dec.mant = 0;
	else
		dec.mant &= ~((uint64_t)0) << -pow;
	d = make_ldouble(d < 0, dec.mant, pow);
	if (dec.flags & SIGN_F)
		d -= 1;
	return (d);
}
