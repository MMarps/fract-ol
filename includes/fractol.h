/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:52:57 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/11/13 19:03:30 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MANDELBROT 0
# define JULIA 1
# define BURNING_SHIP 2

# define HEIGHT 1600
# define WIDTH 1600

# define M_PI 3.14159265358979323846

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "macros.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_complex
{
	double	x;
	double	i;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bit_per_pixels;
	int		line_lenght;
	int		endian;
}			t_img;

typedef struct s_color
{
	double	freq_r;
	double	freq_g;
	double	freq_b;
	double	phase_r;
	double	phase_g;
	double	phase_b;
	double	shift;
}					t_color;

typedef struct s_data
{
	int			max_it;
	double		shift_x;
	double		shift_y;
	double		zoom;
	t_complex	julia;
	t_color		rgb;
}			t_data;

typedef struct s_mlx
{
	int		fractal;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_data	*param;
}			t_mlx;

// Maths utils
double	scale(double unscaled_num,
			double new_min,
			double new_max,
			double old_max);
t_complex	abs_complex(t_complex c);
t_complex	square_complex(t_complex c);
t_complex	sum_complex(t_complex a, t_complex b);

// Handle hooks
int	close_win(t_mlx *mlx);
void	hooks(t_mlx mlx);

// Utils
void	print_instruct(void);
void	print_error_args(void);
bool	check_input(int argc, char *argv[], t_mlx *mlx);
void	error_malloc(t_mlx *mlx, char *msg);
void	init_param(t_data *param);
void	ft_pixel_put(int x, int y, t_img *img, int color);

// Mandelbrot
void	fractol_render(t_mlx *mlx);

// Fractals
void	mandelbrot(int x, int y, t_mlx *mlx, t_data *param);
void	julia(int x, int y, t_mlx *mlx, t_data *param);
void	burning_ship(int x, int y, t_mlx *mlx, t_data *param);

#endif