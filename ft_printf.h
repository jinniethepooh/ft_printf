/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:32:59 by cchetana          #+#    #+#             */
/*   Updated: 2022/04/02 22:37:48 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_inf
{
	char	type;
	int		dot;
	int		dotwd;
	int		minus;
	int		minwd;
	int		plus;
	int		sharp;
	int		space;
	int		zero;
}	t_inf;

int		ft_is_numeric(char c);
int		ft_is_type(char c);
int		ft_is_int(t_inf *inf);
int		ft_is_hex(t_inf *inf);
int		ft_is_validflag_c(t_inf *inf);
int		ft_is_validflag_s(t_inf *inf);
int		ft_is_validflag_nbr(t_inf *inf);
int		ft_is_validflag_hex(t_inf *inf);
int		ft_is_validflag_p(t_inf *inf);

int		ft_strlen(char *s);
int		ft_get_unit(long nbr, int base);
int		ft_printf(const char *str, ...);
int		ft_printf_loop(char *s, va_list ptr, t_inf *inf);

int		ft_putchar_len(int c, t_inf *inf);
int		ft_putstr_len(char *s, t_inf *inf);
int		ft_putnbr_len(long nbr, int base, t_inf *inf);
int		ft_putaddr_len(void *ptr, t_inf *inf);
int		ft_putpercent_len(int c, t_inf *inf);
int		ft_putstrn(char *s, int len);

int		ft_print_assign(va_list ptr, t_inf *inf);
int		ft_print_minwd(t_inf *inf, int len);
int		ft_print_minus(t_inf *inf, int len);
int		ft_print_dotstr(t_inf *inf, char *s, int len);
int		ft_print_dotnbr(t_inf *inf, long nbr, int base, int *len);
int		ft_print_dotwd(t_inf *inf, int len);
int		ft_print_prefixnbr(t_inf *inf, long nbr, int unit);
int		ft_print_sharp(t_inf *inf, long nbr);

void	ft_set_info(t_inf *inf);
void	ft_get_info(char *s, t_inf *inf, int *index, int i);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(unsigned long nbr, unsigned long base, char type);
void	ft_negative(t_inf *inf, long *nbr);

#endif
