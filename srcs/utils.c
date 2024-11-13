/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:53:10 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/11/13 20:47:55 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_error_args(void)
{
	ft_printf("ERROR: arguments\n\n");
	ft_printf("#Launch program with:\n\n");
	ft_printf("	$>./fractol \"mandelbrot\"\n");
	ft_printf("	$>./fractol \"julia\" \"x.x\" \"x.x\"\n");
	ft_printf("	$>./fractol \"burning_ship\"\n\n");
}

void	print_menu(void)
{
	ft_printf("\n\t\t<< Fract-ol >>\n\n");
	ft_printf("  #Launch program:\n\n");
	ft_printf("	$>./fractol \"mandelbrot\"\n");
	ft_printf("	$>./fractol \"julia\" \"x.x\" \"x.x\"\n");
	ft_printf("	$>./fractol \"burning_ship\"\n\n");
	ft_printf("    ========================================\n\n");
	ft_printf("  #Keys:\n\n");
	ft_printf("	'esc'              -> close\n");
	ft_printf("	'+'  (keyboard)    -> more definition\n");
	ft_printf("	'-'  (keyboard)    -> less definition\n");
	ft_printf("	'+'  (keypad)      -> zoom IN\n");
	ft_printf("	'-'  (keypad)      -> zoom OUT\n");
	ft_printf("	directional arrows -> move picture\n\n");
	ft_printf("  #Mouse:\n\n");
	ft_printf("	You can zoom IN or OUT where your cursor is.\n\n");
	ft_printf("	*For JULIA, use the left button to change initials values.\n");
	ft_printf("\n  #Colors:\n\n");
	ft_printf("	(+)    (-)\n");
	ft_printf("	'f' or 'd' -> change the color\n");
	ft_printf("	'r' or 't' -> moove red (rgb)\n");
	ft_printf("	'g' or 'h' -> moove green (rgb)\n");
	ft_printf("	'b' or 'n' -> moove blue (rgb)\n\n");
	ft_printf("    ========================================\n\n");
	ft_printf("Enjoy ;)\n");
}

bool	check_input(int argc, char *argv[], t_mlx *mlx)
{
	int	i;

	i = 0;
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot\0", 11))
	{
		mlx->fractal = MANDELBROT;
		return (true);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia\0", 6))
	{
		if (!ft_isdbl(argv[2]) || !ft_isdbl(argv[3]))
			return (false);
		mlx->fractal = JULIA;
		return (true);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "burning_ship\0", 13))
	{
		mlx->fractal = BURNING_SHIP;
		return (true);
	}
	return (false);
}

void	error_malloc(t_mlx *mlx, char *msg)
{
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_lenght) + (x * (img->bit_per_pixels));
	*(unsigned int *)(img->addr + offset) = color;
}
