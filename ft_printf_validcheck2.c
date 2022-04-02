/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_validcheck2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:15:20 by cchetana          #+#    #+#             */
/*   Updated: 2022/04/02 22:21:59 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_validflag_c(t_inf *inf)
{
	return (!inf->dotwd && !inf->plus && !inf->sharp && !inf->space && \
			!inf->zero);
}

int	ft_is_validflag_s(t_inf *inf)
{
	return (!inf->plus && !inf->sharp && !inf->space && !inf->zero);
}

int	ft_is_validflag_nbr(t_inf *inf)
{
	if (ft_is_int(inf))
	{
		if (!inf->sharp)
		{
			if (inf->plus && inf->space)
				return (0);
			if (inf->minus && inf->zero)
				return (0);
			return (1);
		}
		return (0);
	}
	return (1);
}

int	ft_is_validflag_hex(t_inf *inf)
{
	if (ft_is_hex(inf))
	{
		if (inf->plus || inf->space)
			return (0);
		if (inf->minus && inf->zero)
			return (0);
	}
	return (1);
}

int	ft_is_validflag_p(t_inf *inf)
{
	return (!inf->dot && !inf->plus && !inf->sharp && !inf->space \
			&& !inf->zero);
}
