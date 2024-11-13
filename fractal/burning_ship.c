/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:40:00 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/11/13 19:36:26 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int get_color(int iteration, int max_iterations, t_color *rgb)
{
	if (iteration == max_iterations)
		return (BLACK);
    double t = (double)iteration / max_iterations;

    int r = (int)(127.5 * (rgb->freq_r + cos(3.0 * M_PI * t + rgb->phase_r)));  // Oscille entre 0 et 255
    int g = (int)(127.5 * (rgb->freq_g + cos(3.0 * M_PI * t + rgb->phase_g))); // Décalé pour dégradé fluide
    int b = (int)(127.5 * (rgb->freq_b + cos(3.0 * M_PI * t + rgb->phase_b))); // Autre décalage

    return (r << 16) | (g << 8) | b;
}

void	burning_ship(int x, int y, t_mlx *mlx, t_data *param)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0;
	z.i = 0.0;
	c.x = scale(x, -2, 2, WIDTH) * param->zoom + param->shift_x;
	c.i = scale(y, -2, 2, HEIGHT) * param->zoom + param->shift_y;
	i = 0;
	while ((i < param->max_it) && (z.x * z.x + z.i * z.i <= 4.0))
	{
		z = abs_complex(z);
		z = sum_complex(square_complex(z), c);
		++i;
	}
	color = get_color(i, param->max_it, &param->rgb);
	ft_pixel_put(x, y, &mlx->img, color);
}