/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:13:03 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 13:14:35 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static int						is_too_much(
	int32_t pow)
{
	return (pow > DB_MAX_POW);
}

static int						align_exp(
	uint64_t *times,
	int32_t *pow)
{
	uint64_t	mask;

	mask = ~((uint64_t)0) << (DB_MANT_PRECISION);
	while (*pow > DB_MIN_POW && !(*times & mask))
	{
		*times <<= 1;
		(*pow)--;
	}
	mask <<= 1;
	while ((*pow < DB_MIN_POW && *times) ||
		(*pow >= DB_MIN_POW && *times & mask))
	{
		*times >>= 1;
		(*pow)++;
	}
	if (*pow < DB_MIN_POW)
		*times = 0;
	return (!is_too_much(*pow));
}

double							make_double(
		char s,
		uint64_t times,
		int32_t p)
{
	if (!times)
	{
		if (p > DB_MAX_POW)
			return (compose_inf(s));
		else
			return (0.0);
	}
	else
	{
		align_exp(&times, &p);
		return (compose_double(s, times, exp_bias_d(p)));
	}
}
