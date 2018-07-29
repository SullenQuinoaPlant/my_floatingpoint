#ifndef FLOATING_POINT_H
# define FLOATING_POINT_H

# include <stdint.h>

/*t_s_dfp flags*/
# define SIGN_F 0x01
# define INF_F 0x02
# define NAN_F 0x04
# define OVER_F 0x08
# define DNORM_F 0x10

typedef struct	s_decomposed_floating_point {
	uint32_t	flags;
	int32_t		exp;
	uint64_t	mant;
}				t_s_dfp;

# define DB_MANT_LOG2_RESOLUTION 63
# define LDB_MANT_LOG2_RESOLUTION 63

# define DB_E_BIAS 1023
# define LDB_E_BIAS 16383

# define DB_MIN_POWER -1022
# define DB_MAX_POWER 1023
# define LDB_MIN_POWER -16382
# define LDB_MAX_POWER -16383

/*functions*/

long double
	compose_ldouble(
		char sign, uint64_t times, int32_t power);

void
	decompose_ldouble(
		long double const *p_val, t_s_dfp *p_ret);

void
	decompose_double(
		double const *p_val, t_s_dfp *p_ret);

int
	is_dnorm(
		t_s_dfp *dbl);

int
	is_inf(
		t_s_dfp *dbl);

int
	is_nan(
		t_s_dfp *dbl);

int
	is_overf(
		t_s_dfp *dbl);

#endif
