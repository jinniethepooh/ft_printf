/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:19:50 by cchetana          #+#    #+#             */
/*   Updated: 2022/04/02 22:24:55 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		++s;
	}
}

void	ft_negative(t_inf *inf, long *nbr)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		if (inf->dot)
			ft_putchar('-');
	}
}

void	ft_putnbr(unsigned long nbr, unsigned long base, char type)
{
	if (nbr > base - 1)
		ft_putnbr(nbr / base, base, type);
	if (type == 'X')
		write(1, &"0123456789ABCDEF"[nbr % base], 1);
	else
		write(1, &"0123456789abcdef"[nbr % base], 1);
}

int	ft_get_unit(long nbr, int base)
{
	int				unit;
	unsigned long	i;

	i = (unsigned long)nbr;
	if (nbr == 0)
		return (1);
	unit = 0;
	if (nbr < 0 && base != 16)
	{
		unit += 1;
		i = nbr * -1;
	}
	while (i != 0)
	{
		unit += 1;
		i /= base;
	}
	return (unit);
}
