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

/*can distinguist between numbers at 2 to the power exp
**	minus :
*/
# define DB_MANT_BITS 52
# define DB_EXP_BITS 11

# define LDB_MANT_BITS 64
# define LDB_EXP_BITS 15

# define DB_MANT_PRECISION 53
# define LDB_MANT_PRECISION 63

# define DB_E_BIAS 1023
# define LDB_E_BIAS 16383

# define DB_MIN_EXP -1022
# define DB_MIN_POW DB_MIN_EXP - DB_MANT_PRECISION
# define DB_MAX_EXP 1023
# define DB_MAX_POW DB_MAX_EXP - DB_MANT_PRECISION

# define LDB_MIN_EXP -16382
# define LDB_MIN_POW LDB_MIN_EXP - LDB_MANT_PRECISION
# define LDB_MAX_EXP 16383
# define LDB_MAX_POW LDB_MAX_EXP - LDB_MANT_PRECISION

/*functions*/

double
	compose_inf(
		char sign);

long double
	compose_ldouble(
		char sign, uint64_t times, uint32_t power);

double
	compose_minf();

double
	compose_nan();

double
	compose_pinf();

void
	decompose_ldouble(
		long double const *p_val, t_s_dfp *p_ret);

void
	decompose_double(
		double const *p_val, t_s_dfp *p_ret);

int32_t
	exp_unbias_d(
		uint16_t pow);

int32_t
	exp_unbias_ld(
		uint32_t pow);

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

long double
	make_ldouble(
		char sign, uint64_t times, int32_t exp);

uint16_t
	trueexp_bias_d(
		int32_t exp);

uint16_t
	trueexp_bias_ld(
		int32_t exp);

#endif
