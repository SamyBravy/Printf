# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 13:58:35 by sdell-er          #+#    #+#              #
#    Updated: 2023/10/31 12:05:17 by sdell-er         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -c

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putexa.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<
clean:
	@rm -f $(OBJS) 

fclean: clean
	@rm -f $(NAME)

re: fclean all