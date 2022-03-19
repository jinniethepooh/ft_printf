# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchetana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 21:33:28 by cchetana          #+#    #+#              #
#    Updated: 2022/03/19 23:14:52 by cchetana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
LIBFT_A = libft.a
LIBFT	= libft
SRCS	= ft_printf.c \
	  ft_printf_format.c \
	  ft_printf_utils.c \
	  libft/ft_strlen.c
CFLAGS	= gcc -Wall -Werror -Wextra
LIBC	= ar -rcs
RM	= rm -rf

$(NAME): $(SRCS)
	make -C $(LIBFT)
	cp libft/libft.a .
	$(CFLAGS) -c $(SRCS)
	$(LIBC) $(NAME) *.o

all: $(NAME)

clean:
	$(RM) *.o $(LIBFT)/*.o

fclean: clean
	$(RM) $(NAME) $(LIBFT_A) $(LIBFT)/$(LIBFT_A)

re: fclean all

.PHONY: all clean fclean re
