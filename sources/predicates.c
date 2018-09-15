/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:14:47 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 13:16:02 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

int								is_nan(
	double dbl)
{
	if (dbl == compose_nan())
		return (1);
	return (0);
}

int								is_finite(
	double dbl)
{
	return (!is_inf(dbl));
}

int								is_inf(
	double dbl)
{
	if (dbl == compose_minf() ||
		dbl == compose_pinf())
		return (1);
	return (0);
}

int								is_overf(
	double dbl)
{
	t_s_dfp	dec;

	decompose_double(&dbl, &dec);
	if (dec.flags & OVER_F)
		return (1);
	return (0);
}

int								is_dnorm(
	double dbl)
{
	t_s_dfp	dec;

	decompose_double(&dbl, &dec);
	if (dec.flags & DNORM_F)
		return (1);
	return (0);
}
