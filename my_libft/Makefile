NAME = libft.a

MY_LST_L = \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c
MY_LST = $(addprefix my_lst/, $(MY_LST_L))

MY_MEM_L = \
ft_bzero.c \
ft_calloc.c \
ft_free_mat.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c
MY_MEM = $(addprefix my_mem/, $(MY_MEM_L))

MY_NBR_L = \
ft_abs.c \
ft_atoi.c \
ft_itoa.c \
ft_log.c \
ft_pow.c \
ft_sqrt.c
MY_NBR = $(addprefix my_nbr/, $(MY_NBR_L))

MY_PUT_L = \
ft_putchar.c \
ft_putendl.c \
ft_putnbr.c \
ft_putstr.c
MY_PUT = $(addprefix my_put/, $(MY_PUT_L))

MY_STR_L = \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_pendchar.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c
MY_STR = $(addprefix my_str/, $(MY_STR_L))

GET_NEXT_LINE_L = \
get_next_line.c

GET_NEXT_LINE = $(addprefix get_next_line/, $(GET_NEXT_LINE_L))

SRCS = $(MY_LST) $(MY_MEM) $(MY_NBR) $(MY_PUT) $(MY_STR) $(GET_NEXT_LINE)

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./my_headers

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus