/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:14:29 by cchetana          #+#    #+#             */
/*   Updated: 2022/03/19 22:45:25 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putchar_len(int i)
{
	ft_putchar(i);
	return (1);
}

int	ft_putnbr_len(long i, int base, int flag)
{
	int	len;

	len = 0;
	if (i < 0)
	{
		i *= -1;
		len += 1;
		ft_putchar('-');
	}
	ft_putnbr(i, base, flag);
	if (i == 0)
		len += 1;
	len += ft_get_unit(i, base);
	return (len);
}

int	ft_putstr_len(char *str)
{
	int	len;

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(str);
	ft_putstr(str);
	return (len);
}

int	ft_putaddr_len(void *ptr)
{
	unsigned long	addr;

	if (!ptr)
	{
		ft_putstr("0x0");
		return (3);
	}
	addr = (unsigned long)ptr;
	ft_putstr("0x");
	ft_putnbr(addr, 16, 'x');
	return (ft_get_unit(addr, 16) + 2);
}
