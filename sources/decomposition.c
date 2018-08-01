#include "inner.h"

#ifdef ARCH_A
void
	decompose_double(
		double const *val, t_s_dfp *ret)
{
	t_u_d	arg;
	
	ft_memcpy(&arg, val, sizeof(*val));
	*ret = (t_s_dfp){arg.sign, exp_unbias_d(arg.exp), arg.mant};
	if (arg.exp == (1 << DB_EXP_BITS) - 1)
		ret->flags |= arg.mant ? NAN_F : INF_F;
	else if (arg.exp == 0)
	{
		ret->flags |= DNORM_F; 
		ret->exp = arg.mant ? ret->exp : 0;
	}
	else
		ret->mant |= 1ull << DB_MANT_BITS;
}

/*NOTES ON THE FOLLOWING:
**	-gnu sets highest mant bit to one for long double
**		infinity.
*/
void
	decompose_ldouble(
		long double const *val, t_s_dfp *ret)
{
	t_u_ld	arg;
	
	ft_memcpy(&arg, val, sizeof(*val));
	*ret = (t_s_dfp){arg.sign, exp_unbias_ld(arg.exp), arg.mant};
	if (arg.exp == (1 << LDB_EXP_BITS) - 1)
	{
		if (arg.mant & ~(1 << LDB_MANT_PRECISION))
			ret->flags |= NAN_F;
		else
			ret->flags |= INF_F;
	}
	else if (arg.exp == 0)
	{
		ret->flags |= DNORM_F;
		ret->exp += arg.mant ? 0 : -ret->exp;
	}
}
#endif
