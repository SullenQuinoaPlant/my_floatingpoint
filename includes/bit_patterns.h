/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_patterns.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:34:56 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 13:39:24 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_PATTERNS_H
# define BIT_PATTERNS_H

# ifdef ARCH_A
typedef union						u_double
{
	double	d;
	char	ar[sizeof(double)];
	struct
	{
		uint64_t	mant : DB_MANT_BITS;
		uint64_t	exp : DB_EXP_BITS;
		uint64_t	sign : 1;
	};
}									t_u_d;

typedef union						u_ldouble
{
	long double	ld;
	char		ar[sizeof(long double)];
	struct
	{
		uint64_t	mant : LDB_MANT_BITS;
		uint16_t	exp : LDB_EXP_BITS;
		uint16_t	sign : 1;
	};
}									t_u_ld;
# endif

#endif
