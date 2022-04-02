/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:14:29 by cchetana          #+#    #+#             */
/*   Updated: 2022/04/02 23:00:07 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_len(int c, t_inf *inf)
{
	int	len;

	len = 1;
	if (ft_is_validflag_c(inf))
	{
		len += ft_print_minwd(inf, len);
		write(1, &c, 1);
		len += ft_print_minus(inf, len);
	}
	else
		write(1, &c, 1);
	return (len);
}

int	ft_putpercent_len(int c, t_inf *inf)
{
	int		len;
	char	fill;

	fill = ' ';
	if (inf->zero)
		fill = '0';
	len = 1;
	if (!inf->minus)
		while (len < inf->minwd)
			len += write(1, &fill, 1);
	write(1, &c, 1);
	if (inf->minus)
		while (len < inf->minwd)
			len += write(1, " ", 1);
	return (len);
}

int	ft_putstr_len(char *s, t_inf *inf)
{
	int		len;
	int		i;
	char	*str;

	str = s;
	if (!s)
		str = "(null)";
	len = ft_strlen(str);
	i = 0;
	if (ft_is_validflag_s(inf))
	{
		i += ft_print_minwd(inf, len);
		i += ft_print_dotstr(inf, str, len);
		i += ft_print_minus(inf, i);
		return (i);
	}
	if (inf->space && inf->minwd && !*str)
		return (ft_putstrn(s, inf->minwd));
	ft_putstr(str);
	return (len);
}

int	ft_putnbr_len(long nbr, int base, t_inf *inf)
{
	int	len;
	int	i;

	len = ft_get_unit(nbr, base);
	i = 0;
	if (ft_is_validflag_nbr(inf) && ft_is_validflag_hex(inf))
	{
		if (inf->sharp && ft_is_hex(inf) && nbr != 0)
			len += 2;
		i += ft_print_prefixnbr(inf, nbr, len);
		i += ft_print_dotnbr(inf, nbr, base, &len);
		i += ft_print_minus(inf, len);
	}
	else
	{
		ft_negative(inf, &nbr);
		ft_putnbr(nbr, base, inf->type);
		i = len;
	}
	return (i);
}

int	ft_putaddr_len(void *ptr, t_inf *inf)
{
	unsigned long	addr;
	int				len;

	addr = (unsigned long)ptr;
	len = ft_get_unit(addr, 16) + 2;
	if (ft_is_validflag_p(inf))
		len += ft_print_minwd(inf, len);
	if (!ptr)
	{
		ft_putstr("0x0");
		return (len);
	}
	ft_putstr("0x");
	ft_putnbr(addr, 16, 'x');
	if (ft_is_validflag_p(inf))
		len += ft_print_minus(inf, len);
	return (len);
}
