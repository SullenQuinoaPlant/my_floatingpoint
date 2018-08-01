#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include <math.h>
#include "myfloatingpoint.h"


int	declare_tests_and_run(int all_of, char *these[])
{
	T(is_nan1,
		double	dnan = NAN;
		t_s_dfp	dec;

		decompose_double(&d, &dec);
		assert_true(is_nan(&dec));
	)

	T(is_nan2,
		long double	dnan = NAN;
		t_s_dfp	dec;

		decompose_ldouble(&d, &dec);
		assert_true(is_nan(&dec));
	)

	T(is_nan3,
		double	nan;
		t_s_dfp	dec;

		nan = compose_nan();
		decompose_double(&d, &dec);
		assert_true(is_nan(&dec));
	)

	T(is_nan4,
		long double	nan;
		t_s_dfp	dec;

		nan = compose_nan();
		decompose_ldouble(&d, &dec);
		assert_true(is_nan(&dec));
	)

	return(run_test_arr(all_of, these));
}
