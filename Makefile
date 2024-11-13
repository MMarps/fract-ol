NAME = fractol

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

MLX = minilibx-linux
MLX_FLAGS = -L$(MLX) -lmlx_Linux -L/usr/bin -lX11 -lXext -lm -lbsd

HEADER = includes/fractol.h

LIBFT = libft/libft.a
LIBFT_PATH = ./libft

FRACTAL = 	fractal/mandelbrot.c \
			fractal/julia.c \
			fractal/burning_ship.c

SRCS =	srcs/main.c \
		srcs/maths_utils.c \
		srcs/utils.c \
		srcs/handle_events.c

SRCS_OBJ =	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o)) \
			$(addprefix $(OBJ_DIR)/, $(FRACTAL:.c=.o))

OBJ_DIR = obj

all: lib $(NAME)

$(NAME): $(SRCS_OBJ)
	$(CC) $(CFLAGS) $(SRCS_OBJ) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

lib:
	@make -C $(LIBFT_PATH)
	@make -C $(MLX)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX) clean

re: fclean all

.PHONY: all clean fclean re lib bonus