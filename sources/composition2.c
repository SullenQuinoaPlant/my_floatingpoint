/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composition2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:06:52 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 13:07:28 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

double				compose_pinf(
	void)
{
	t_u_d	mapper;

	mapper.sign = 0;
	mapper.exp = ~0;
	mapper.mant = 0;
	return (mapper.d);
}
