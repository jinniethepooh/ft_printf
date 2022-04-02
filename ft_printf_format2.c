/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:53:41 by cchetana          #+#    #+#             */
/*   Updated: 2022/04/02 22:53:54 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_prefixnbr(t_inf *inf, long nbr, int len)
{
	int	i;

	i = 0;
	if (nbr >= 0)
	{
		if (inf->space)
			i += write(1, " ", 1);
		if (inf->plus)
			i += write(1, "+", 1);
	}
	if (!inf->dot)
	{
		if (nbr < 0 && inf->zero)
			ft_putchar('-');
		i += ft_print_minwd(inf, len + i);
		if (nbr < 0 && !inf->zero)
			ft_putchar('-');
	}
	return (i);
}

int	ft_print_minwd(t_inf *inf, int len)
{
	int		i;
	int		benchmark;
	char	fill;

	fill = ' ';
	if (inf->zero && !inf->dot)
		fill = '0';
	i = 0;
	benchmark = len;
	if (!inf->minus)
	{
		if (inf->dot && inf->dotwd < len && inf->type == 's')
			benchmark = inf->dotwd;
		else if (inf->dotwd > len && inf->type != 's')
			benchmark = inf->dotwd;
		while (inf->minwd > benchmark + i)
			i += write(1, &fill, 1);
	}
	return (i);
}

int	ft_print_sharp(t_inf *inf, long nbr)
{
	if (nbr == 0)
		return (0);
	if (inf->type == 'X')
		return (write(1, "0X", 2));
	return (write(1, "0x", 2));
}

int	ft_print_minus(t_inf *inf, int len)
{
	int	i;
	int	benchmark;

	i = 0;
	benchmark = len;
	if (inf->minus)
	{
		if (inf->dot && inf->dotwd < len && inf->type == 's')
			benchmark = inf->dotwd;
		else if (inf->dotwd > len && inf->type != 's')
			benchmark = inf->dotwd;
		while (inf->minwd > benchmark + i)
			i += write(1, " ", 1);
	}
	return (i);
}
