NAME = libftprintf.a

SRCS =  \
	ft_printf.c \
	ft_putchar.c \
	ft_putexa.c \
	ft_putnbr.c \
	ft_putstr.c

OBJS = $(addprefix mandatory/, $(SRCS:.c=.o))

SRCS_BONUS = \
	ft_hexa_bonus.c \
	ft_void_bonus.c \
	ft_strs_bonus.c \
	ft_nbrs_bonus.c \
	ft_char_bonus.c \
	ft_parsing_bonus.c \
	ft_handle_flags_bonus.c \
	ft_printf_bonus.c

OBJS_BONUS = $(addprefix bonus/, $(SRCS_BONUS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

libft = my_libft

all: $(NAME)

$(NAME): $(OBJS)
	make libft
	cp $(libft)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	make libft
	cp $(libft)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: ft_clean
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean ft_fclean
	@rm -f $(NAME)

re: ft_fclean fclean all

libft:
	@make -C $(libft) all

ft_clean:
	@make -C $(libft) clean

ft_fclean:
	@make -C $(libft) fclean

.PHONY: all clean fclean re

test: fclean all clean
	$(CC) $(CFLAGS) main.c $(NAME)
	./a.out

test2:
	clear
	$(CC) $(CFLAGS) main2.c $(NAME) -o main2
	./main2 | cat -e

compile_bonus:
	make bonus
	$(CC) $(CFLAGS) main_bonus.c $(NAME) -o bonus.out

test_bonus:
	make bonus
	$(CC) $(CFLAGS) main_bonus.c $(NAME) -o bonus.out
	./bonus.out | cat -e

debug_bonus:
	make bonus
	$(CC) $(CFLAGS) main_bonus.c $(NAME) -o bonus.out
	lldb bonus.out