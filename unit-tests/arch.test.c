#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include <math.h>
#include "myfloatingpoint.h"
#include "bit_patterns.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(check_ARCH_double,
		t_u_d	dec;

		dec.d = -1;
		assert_true(dec.sign == 1);
		assert_true(dec.mant == 0);
		assert_true(dec.exp == DB_E_BIAS);
	)

	T(check_ARCH_ldouble,
		t_u_ld	dec;

		dec.ld = -1;
		assert_true(dec.sign == 1);
		assert_true(dec.mant == ((uint64_t)1) << 63);
		assert_true(dec.exp == LDB_E_BIAS);
	)

	return(run_test_arr(all_of, these));
}
