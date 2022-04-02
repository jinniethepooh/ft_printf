/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:04:55 by cchetana          #+#    #+#             */
/*   Updated: 2022/04/02 22:31:36 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dotstr(t_inf *inf, char *s, int len)
{
	int	i;
	int	benchmark;

	if (inf->dot)
	{
		benchmark = len;
		i = 0;
		if (len > inf->dotwd)
			benchmark = inf->dotwd;
		i = ft_putstrn(s, benchmark);
		return (i);
	}
	ft_putstr(s);
	return (len);
}

int	ft_print_dotnbr(t_inf *inf, long nbr, int base, int *len)
{
	int	i;

	i = 0;
	if (inf->dot)
	{
		if (nbr < 0)
			inf->dotwd += 1;
		if (nbr == 0 && !inf->dotwd)
			*len -= 1;
		i += ft_print_minwd(inf, *len);
		if (nbr == 0 && !inf->dotwd)
			return (i);
	}
	ft_negative(inf, &nbr);
	if (inf->sharp && ft_is_hex(inf))
		ft_print_sharp(inf, nbr);
	i += ft_print_dotwd(inf, *len);
	ft_putnbr(nbr, base, inf->type);
	return (i + *len);
}

int	ft_print_dotwd(t_inf *inf, int len)
{
	int	i;

	i = 0;
	if (inf->dotwd)
	{
		while (inf->dotwd > len + i)
			i += write(1, "0", 1);
	}
	return (i);
}
