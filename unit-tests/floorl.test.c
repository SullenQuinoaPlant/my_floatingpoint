#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "myfloatingpoint.h"


int	declare_tests_and_run(int all_of, char *these[])
{
	T(test1,
		assert_true(my_floorl(0.1) == 0);
	)
	T(test2,
		assert_true(my_floorl(-0.1) == -1);
	)
	return(run_test_arr(all_of, these));
}
