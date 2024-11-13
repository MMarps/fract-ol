NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS =	ft_printf.c ft_hexa.c ft_putstr_ct.c ft_putnbr_ct.c \
		ft_putchar_ct.c ft_putptr.c
SRC_HEADER = ft_printf.h
OBJ_FILES = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c $(SRC_HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re