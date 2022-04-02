/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:27:24 by cchetana          #+#    #+#             */
/*   Updated: 2022/04/02 22:21:09 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

int	ft_putstrn(char *s, int len)
{
	int	i;

	i = 0;
	if (*s)
		while (s[i] && i < len)
			i += write(1, &s[i], 1);
	else
		while (i < len)
			i += write(1, " ", 1);
	return (i);
}

void	ft_set_info(t_inf *inf)
{
	inf->type = 0;
	inf->dot = 0;
	inf->dotwd = 0;
	inf->minus = 0;
	inf->minwd = 0;
	inf->plus = 0;
	inf->sharp = 0;
	inf->space = 0;
	inf->zero = 0;
}

int	ft_print_assign(va_list ptr, t_inf *inf)
{
	if (inf->type == 'c')
		return (ft_putchar_len(va_arg(ptr, int), inf));
	else if (inf->type == 's')
		return (ft_putstr_len(va_arg(ptr, char *), inf));
	else if (inf->type == 'd' || inf->type == 'i')
		return (ft_putnbr_len(va_arg(ptr, int), 10, inf));
	else if (inf->type == 'u')
		return (ft_putnbr_len(va_arg(ptr, unsigned int), 10, inf));
	else if (inf->type == 'x' || inf->type == 'X')
		return (ft_putnbr_len(va_arg(ptr, unsigned int), 16, inf));
	else if (inf->type == 'p')
		return (ft_putaddr_len(va_arg(ptr, void *), inf));
	else if (inf->type == '%')
		return (ft_putpercent_len('%', inf));
	else
		return (0);
}
