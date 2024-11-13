/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:57:20 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/11/13 20:47:57 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_param(t_data *param)
{
	t_color	rgb;

	param->max_it = 42;
	param->shift_x = 0.0;
	param->shift_y = 0.0;
	param->zoom = 1.0;
	rgb.freq_r = 1.0;
	rgb.freq_g = 1.0;
	rgb.freq_b = 1.0;
	rgb.phase_r = 0.0;
	rgb.phase_g = 2.0;
	rgb.phase_b = 4.0;
	rgb.shift = 0.1;
	param->rgb = rgb;
}

void	init_minilbx(t_mlx *mlx, t_data *param)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		error_malloc(mlx, "ERROR: mlx_init");
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "win_1");
	if (!mlx->win_ptr)
		error_malloc(mlx, "ERROR: win");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!mlx->img.img_ptr)
		error_malloc(mlx, "ERROR: img");
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
									&mlx->img.bit_per_pixels,
									&mlx->img.line_lenght,
									&mlx->img.endian);
	if (!mlx->img.addr)
	{
		free(mlx->img.addr);
		error_malloc(mlx, "ERROR: addr");
	}
	mlx->img.bit_per_pixels /= 8;
	mlx->param = param;
}

void	fractol_render(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (mlx->fractal == MANDELBROT)
				mandelbrot(x, y, mlx, mlx->param);
			else if (mlx->fractal == JULIA)
				julia(x, y, mlx, mlx->param);
			else if (mlx->fractal == BURNING_SHIP)
				burning_ship(x, y, mlx, mlx->param);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr,
							mlx->win_ptr,
							mlx->img.img_ptr,
							0, 0);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_data	param;

	if (!check_input(argc, argv, &mlx))
	{
		print_error_args();
		exit(EXIT_FAILURE);
	}
	init_minilbx(&mlx, &param);
	init_param(&param);
	if (mlx.fractal == JULIA)
	{
		mlx.param->julia.x = ft_atod(argv[2]);
		mlx.param->julia.i = ft_atod(argv[3]);
	}
	print_menu();
	fractol_render(&mlx);
	hooks(mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
