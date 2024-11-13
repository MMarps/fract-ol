/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:44:00 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/11/13 22:33:40 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int get_color(int iteration, int max_iterations, double zn)
{
    double	smooth_iter;
    double	t;
	int		r;
	int		g;
	int		b;

	if (iteration == max_iterations)
			return (PSY_HOT_PINK);
	smooth_iter = iteration + 1 - log(log(zn)) / log(2.0);
	t = smooth_iter / max_iterations;
    r = (int)(9 * (1 - t) * t * t * t * 255);
    g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return ((r << 16) | (g << 8) | b);
}

void	julia(int x, int y, t_mlx *mlx, t_data *param)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = scale(x, -2, 2) * param->zoom + param->shift_x;
	z.i = scale(y, 2, -2) * param->zoom + param->shift_y;
	c.x = param->julia.x;
	c.i = param->julia.i;
	i = 0;
	while (i < param->max_it && (z.x * z.x) + (z.i * z.i) <= 4.0)
	{
		z = sum_complex(square_complex(z), c);
		++i;
	}
	color = get_color(i, param->max_it, sqrt(z.x * z.x + z.i * z.i));
	ft_pixel_put(x, y, &mlx->img, color);
}