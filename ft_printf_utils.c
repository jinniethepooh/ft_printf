/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:19:50 by cchetana          #+#    #+#             */
/*   Updated: 2022/03/19 22:47:00 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		++str;
	}
}

void	ft_putnbr(unsigned long i, unsigned int base, int flag)
{
	if (i > base - 1)
		ft_putnbr(i / base, base, flag);
	if (flag == 'X')
		write(1, &"0123456789ABCDEF"[i % base], 1);
	else
		write(1, &"0123456789abcdef"[i % base], 1);
}

int	ft_get_unit(unsigned long i, int base)
{
	int	unit;

	unit = 0;
	while (i > 0)
	{
		unit++;
		i /= base;
	}
	return (unit);
}
