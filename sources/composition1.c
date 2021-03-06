/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:07:43 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 13:09:24 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

double							compose_double(
	char sign,
	uint64_t mant,
	uint16_t bias_exp)
{
	t_u_d	mapper;

	mapper.sign = sign ? 1 : 0;
	mapper.exp = bias_exp;
	mapper.mant = mant;
	return (mapper.d);
}

double							compose_inf(
	char sign)
{
	if (sign)
		return (compose_minf());
	return (compose_pinf());
}

long double						compose_ldouble(
	char sign,
	uint64_t times,
	uint16_t bias_exp)
{
	t_u_ld	mapper;

	mapper.sign = sign ? 1 : 0;
	mapper.exp = bias_exp;
	mapper.mant = times;
	return (mapper.ld);
}

double							compose_minf(
	void)
{
	t_u_d	mapper;

	mapper.sign = 1;
	mapper.exp = ~0;
	mapper.mant = 0;
	return (mapper.d);
}

double							compose_nan(
	void)
{
	t_u_d	mapper;

	mapper.sign = 0;
	mapper.exp = ~0;
	mapper.mant = ((uint64_t)1 << (DB_MANT_BITS - 1));
	return (mapper.d);
}
