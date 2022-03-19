/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:09:29 by cchetana          #+#    #+#             */
/*   Updated: 2022/03/19 22:40:26 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_selectflag(const char *str, va_list ptr)
{
	int	len;

	len = 0;
	if (str[len] == 'c')
		len += ft_putchar_len(va_arg(ptr, int));
	else if (str[len] == 's')
		len += ft_putstr_len(va_arg(ptr, char *));
	else if (str[len] == 'd' || str[len] == 'i')
		len += ft_putnbr_len(va_arg(ptr, int), 10, 1);
	else if (str[len] == 'u')
		len += ft_putnbr_len(va_arg(ptr, unsigned int), 10, 1);
	else if (str[len] == 'x' || str[len] == 'X')
		len += ft_putnbr_len(va_arg(ptr, unsigned int), 16, str[len]);
	else if (str[len] == 'p')
		len += ft_putaddr_len(va_arg(ptr, void *));
	else if (str[len] == '%')
		len += ft_putchar_len('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;
	int		index;

	len = 0;
	index = 0;
	va_start(ptr, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			index += 1;
			len += (ft_selectflag(&str[index], ptr));
		}
		else
			len += ft_putchar_len(str[index]);
		index++;
	}
	va_end(ptr);
	return (len);
}
