#ifndef FLOATING_POINT_BIT_PATTERNS_H
# define FLOATING_POINT_BIT_PATTERNS_H

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
