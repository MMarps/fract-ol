/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 22:37:08 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/11/13 21:54:49 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_win(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	change_iterations(t_mlx *mlx, int keysym)
{
	if (keysym == XK_equal)
	{
		mlx->param->max_it += 10;
		ft_printf("iterations = %d\n", mlx->param->max_it);
	}
	else if (keysym == XK_minus)
	{
		if (mlx->param->max_it - 10 > 0)
			mlx->param->max_it -= 10;
		ft_printf("iterations = %d\n", mlx->param->max_it);
	}
}

void	change_colors(t_color *rgb, int keysym)
{
	if (keysym == XK_r)
		rgb->phase_r += rgb->shift;
	else if (keysym == XK_t)
		rgb->phase_r -= rgb->shift;
	else if (keysym == XK_g)
		rgb->phase_g += rgb->shift;
	else if (keysym == XK_h)
		rgb->phase_g -= rgb->shift;
	else if (keysym == XK_b)
		rgb->phase_b += rgb->shift;
	else if (keysym == XK_n)
		rgb->phase_b -= rgb->shift;
	else if (keysym == XK_f)
	{
		rgb->phase_r += rgb->shift;
		rgb->phase_g += rgb->shift;
		rgb->phase_b += rgb->shift;
	}
	else if (keysym == XK_d)
	{
		rgb->phase_r -= rgb->shift;
		rgb->phase_g -= rgb->shift;
		rgb->phase_b -= rgb->shift;
	}
}

void	moove_picture(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Up)
	{
		if (mlx->fractal != BURNING_SHIP)
			mlx->param->shift_y += (0.5 * mlx->param->zoom);
		else
			mlx->param->shift_y -= (0.5 * mlx->param->zoom);
	}
	else if (keysym == XK_Down)
	{
		if (mlx->fractal != BURNING_SHIP)
			mlx->param->shift_y -= (0.5 * mlx->param->zoom);
		else
			mlx->param->shift_y += (0.5 * mlx->param->zoom);
	}
	else if (keysym == XK_Left)
		mlx->param->shift_x -= (0.5 * mlx->param->zoom);
	else if (keysym == XK_Right)
		mlx->param->shift_x += (0.5 * mlx->param->zoom);
}

int	key_handler(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		close_win(mlx);
	else if (keysym == XK_Up || keysym == XK_Down
			|| keysym == XK_Left || keysym == XK_Right)
		moove_picture(keysym, mlx);
	else if (keysym == XK_equal || keysym == XK_minus)
		change_iterations(mlx, keysym);
	else if (keysym == XK_KP_Add)
		mlx->param->zoom *= 0.8;
	else if (keysym == XK_KP_Subtract)
		mlx->param->zoom *= 1.2;
	else if (keysym == XK_BackSpace)
		init_param(mlx->param);
	else if (keysym == XK_r || keysym == XK_g || keysym == XK_b || keysym == XK_f
			|| keysym == XK_t || keysym == XK_h || keysym == XK_n || keysym == XK_d)
		change_colors(&mlx->param->rgb, keysym);
	else
		return (0);
	fractol_render(mlx);
	return (0);
}

void	change_zoom(int button, int x, int y, t_data *param)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	zoom_factor = 1.0;
	mouse_x = scale(x, -2, 2) * param->zoom + param->shift_x;
	mouse_y = scale(y, 2, -2) * param->zoom + param->shift_y;
	if (button == Button5)
		zoom_factor = 0.8;
	else if (button == Button4)
		zoom_factor = 1.2;
	param->zoom *= zoom_factor;
	param->shift_x = mouse_x - scale(x, -2, 2) * param->zoom;
	param->shift_y = mouse_y - scale(y, 2, -2) * param->zoom;
}

int	mouse_handler(int button, int x, int y, t_mlx *mlx)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	zoom_factor = 1.0;
	mouse_x = scale(x, -2, 2);
	mouse_y = scale(y, 2, -2);
	if (button == Button5 || button == Button4)
		change_zoom(button, x, y, mlx->param);
	else if (button == Button1 && mlx->fractal == JULIA)
	{
		mlx->param->julia.x = mouse_x;
		mlx->param->julia.i = mouse_y;
		printf("x = %f\ni = %f\n", mouse_x, mouse_y);
	}
	else
		return (0);
	fractol_render(mlx);
	return (0);
}

void	hooks(t_mlx mlx)
{
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, key_handler, &mlx);
	mlx_hook(mlx.win_ptr, ButtonPress, ButtonPressMask, mouse_handler, &mlx);
	mlx_hook(mlx.win_ptr, DestroyNotify, StructureNotifyMask, close_win, &mlx);
}
