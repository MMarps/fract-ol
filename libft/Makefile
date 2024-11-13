NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_FILES = ft_atoi.c ft_atod.c ft_bzero.c ft_calloc.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isdbl.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_tolower.c ft_toupper.c
SRC_FILES_P2 =	ft_strjoin.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_strmapi.c ft_striteri.c
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c  \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstmap_bonus.c ft_lstiter_bonus.c \
			get_next_line.c
SRC_PRINTF = ft_printf/ft_printf.c ft_printf/ft_hexa.c \
			ft_printf/ft_putstr_ct.c ft_printf/ft_putnbr_ct.c ft_printf/ft_putchar_ct.c \
			ft_printf/ft_putptr.c
SRCS = $(SRC_FILES) $(SRC_FILES_P2) $(SRC_BONUS) $(SRC_PRINTF)
SRC_HEADER = libft.h get_next_line.h ft_printf/ft_printf.h
OBJ_FILES = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c $(SRC_HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o ft_printf/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus