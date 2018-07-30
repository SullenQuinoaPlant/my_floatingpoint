#ifndef BIT_PATTERNS_H
# define BIT_PATTERNS_H

# ifdef ARCH_A
typedef union	u_double {
	double	d;
	char	ar[sizeof(double)];
	struct	{
		uint64_t	mant : DB_MANT_BITS;
		uint64_t	exp : DB_EXP_BITS;
		uint64_t	sign : 1;
	};
}				t_u_d;

typedef union	u_ldouble {
	long double	ld;
	char		ar[sizeof(long double)];
	struct		{
		uint64_t	mant : LDB_MANT_BITS;
		uint32_t	exp : LDB_EXP_BITS;
		uint32_t	sign : 1;
	};
}				t_u_ld;
# endif

#endif
