# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchetana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 21:33:28 by cchetana          #+#    #+#              #
#    Updated: 2022/04/02 22:41:16 by cchetana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ft_printf.c \
	  ft_printf_format.c \
	  ft_printf_format2.c \
	  ft_printf_format3.c \
	  ft_printf_utils.c \
	  ft_printf_utils2.c \
	  ft_printf_validcheck.c \
	  ft_printf_validcheck2.c
CFLAGS	= gcc -Wall -Werror -Wextra
LIBC	= ar -rcs
RM	= rm -rf

$(NAME): $(SRCS)
	$(CFLAGS) -c $(SRCS)
	$(LIBC) $(NAME) *.o

all: $(NAME)

bonus: $(SRCS)
	$(CFLAGS) -c $(SRCS)
	$(LIBC) $(NAME) *.o

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
