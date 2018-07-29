#ifndef FLOATING_POINT_BIT_PATTERNS_H
# define FLOATING_POINT_BIT_PATTERNS_H

# include <stdint.h>

# define SIGN_F 0x01
# define INF_F 0x02
# define NAN_F 0x04
# define OVER_F 0x08
# define DNORM_F 0x10

# define DB_E_BIAS 1023
# define LDB_E_BIAS 16383

# ifdef ARCH_A
typedef union	u_double {
	double	d;
	char	ar[sizeof(double)];
	struct	{
		uint64_t	mant : 52;
		uint64_t	exp : 11;
		uint64_t	sign : 1;
	};
}				t_u_d;

typedef union	u_ldouble {
	long double	ld;
	char		ar[sizeof(long double)];
	struct		{
		uint64_t	mant : 64;
		uint32_t	exp : 15;
		uint32_t	sign : 1;
	};
}				t_u_ld;
# endif

#endif
