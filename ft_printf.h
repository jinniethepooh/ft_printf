/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:32:59 by cchetana          #+#    #+#             */
/*   Updated: 2022/03/19 22:48:14 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putchar_len(int i);
int		ft_putnbr_len(long i, int base, int flag);
int		ft_putstr_len(char *str);
int		ft_get_unit(unsigned long i, int base);
int		ft_putaddr_len(void *ptr);
void	ft_putchar(char c);
void	ft_putnbr(unsigned long i, unsigned int base, int flag);
void	ft_putstr(char *str);

#endif
