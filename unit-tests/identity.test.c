#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include <math.h>
#include "myfloatingpoint.h"

static
double
	identity_d(
		double d)
{
	t_s_dfp	dec;
	double	red;
	t_s_dfp decred;

	decompose_double(&d, &dec);
	red = make_ldouble(
			dec.flags & SIGN_F,
			dec.mant,
			dec.exp - LDB_MANT_PRECISION);
	decompose_double(&red, &decred);
	return (red);
}

static
long double
	identity_ld(
		long double d)
{
	t_s_dfp	dec;
	long double	red;
	t_s_dfp	decred;

	decompose_ldouble(&d, &dec);
	red = make_ldouble(
			dec.flags & SIGN_F,
			dec.mant,
			dec.exp - LDB_MANT_PRECISION);
	decompose_ldouble(&red, &decred);
	return (red);
}

int	declare_tests_and_run(int all_of, char *these[])

{
	T(identity0,
		long double	d = 123.123;

		assert_true(d == identity_ld(d));
	)

	T(identity1,
		double	d = 123.123;

		assert_true(d == identity_d(d));
	)

	T(identity2,
		double	d = 0.0;

		assert_true(d == identity_d(d));
	)

	T(identity3,
		double	d;
		t_s_dfp	dec;

		d = identity_d(NAN);
		decompose_double(&d, &dec);
		assert_true(is_nan(&dec));
	)

	T(identity4,
		double	d;

		d = INFINITY;
		assert_true(d == identity_d(d));
	)

	T(identity5,
		long double	d = 123.123L;

		assert_true(d == identity_ld(d));
	)

	T(identity6,
		long double	d = 0.0;

		assert_true(d == identity_ld(d));
	)

	T(identity7,
		long double	d;
		t_s_dfp		dec;

		d = identity_ld(NAN);
		decompose_ldouble(&d, &dec);
		assert_true(is_nan(&dec));
	)

	T(identity8,
		long double	d;

		d = INFINITY;
		assert_true(d == identity_ld(d));
	)

	return(run_test_arr(all_of, these));
}
