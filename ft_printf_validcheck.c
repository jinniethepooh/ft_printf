/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_validcheck.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:10:17 by cchetana          #+#    #+#             */
/*   Updated: 2022/04/02 21:14:29 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_numeric(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' \
			|| c == 'x' || c == 'X' || c == 'p' || c == '%');
}

int	ft_is_int(t_inf *inf)
{
	return (inf->type == 'd' || inf->type == 'i' || inf->type == 'u');
}

int	ft_is_hex(t_inf *inf)
{
	return (inf->type == 'X' || inf->type == 'x');
}
