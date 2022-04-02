/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:09:29 by cchetana          #+#    #+#             */
/*   Updated: 2022/04/02 22:18:42 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_info(char *s, t_inf *inf, int *index, int i)
{
	while (!ft_is_type(s[i]))
	{
		if (s[i] == '-')
			inf->minus = 1;
		else if (s[i] == '+')
			inf->plus = 1;
		else if (s[i] == '#')
			inf->sharp = 1;
		else if (s[i] == ' ')
			inf->space = 1;
		else if (s[i] == '.')
			inf->dot = 1;
		else if (inf->dot && ft_is_numeric(s[i]))
			inf->dotwd = inf->dotwd * 10 + (s[i] - '0');
		else if (s[i] == '0' && inf->minwd == 0)
			inf->zero = 1;
		else if (!inf->dot && ft_is_numeric(s[i]))
			inf->minwd = inf->minwd * 10 + (s[i] - '0');
		++i;
	}
	inf->type = s[i];
	*index += i;
}

int	ft_printf_loop(char *s, va_list ptr, t_inf *inf)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			++i;
			ft_set_info(inf);
			ft_get_info(&s[i], inf, &i, 0);
			len += ft_print_assign(ptr, inf);
		}
		else
			len += write(1, &s[i], 1);
		++i;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	t_inf	inf;
	int		len;

	va_start(ptr, str);
	len = ft_printf_loop((char *)str, ptr, &inf);
	va_end(ptr);
	return (len);
}
