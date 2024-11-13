/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:10:20 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/11/13 19:35:47 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// , sqrt(z.x * z.x + z.i * z.i)

// static int get_color(int iteration, int max_iterations)
// {
// 	double	t;

//     t = log((double)iteration + 1) / log((double)max_iterations);
//     int r = (int)(8 * t * 255);
//     int g = (int)(12 * t * 255);
//     int b = (int)(23 * t * 255);

//     return (r << 16) | (g << 8) | b;
// }

// static int get_color(int iteration, int max_iterations, double zn)
// {

//     // Utiliser l'itération fractionnaire pour une transition plus douce
//     double smooth_iter = iteration + 1 - log(log(zn)) / log(2.0);
//     double t = smooth_iter / max_iterations;

//     // Dégradé de couleurs ajusté
//     int r = (int)(9 * (1 - t) * t * t * t * 255);
//     int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//     int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    
//     return (r << 16) | (g << 8) | b;
// }
// , sqrt(z.x * z.x + z.i * z.i)

// // Fonction pour interpoler entre deux couleurs
// int interpolate_color(int color1, int color2, double ratio) {
//     int r1 = (color1 >> 16) & 0xFF;
//     int g1 = (color1 >> 8) & 0xFF;
//     int b1 = color1 & 0xFF;

//     int r2 = (color2 >> 16) & 0xFF;
//     int g2 = (color2 >> 8) & 0xFF;
//     int b2 = color2 & 0xFF;

//     int r = (int)(r1 + ratio * (r2 - r1));
//     int g = (int)(g1 + ratio * (g2 - g1));
//     int b = (int)(b1 + ratio * (b2 - b1));

//     return (r << 16) | (g << 8) | b;
// }

// // Fonction principale get_color utilisant les points clés
// int get_color(int iteration, int max_iterations)
// {
//     // Points de couleur (ajuster selon l'effet souhaité)
//     int color_start = PSY_CYAN; // Bleu
//     int color_middle = PSY_HOT_PINK; // Magenta
//     int color_end = PSY_GREEN; // Blanc

//     double t = (double)iteration / max_iterations;

//     if (t < 0.5) {
//         // Interpolation entre color_start et color_middle
//         return interpolate_color(color_start, color_middle, t * 2);
//     } else {
//         // Interpolation entre color_middle et color_end
//         return interpolate_color(color_middle, color_end, (t - 0.5) * 2);
//     }
// }

// static int get_color(int iteration, int max_iterations) {
//     if (iteration == max_iterations) return 0x000000; // Noir pour l'intérieur de l'ensemble

//     // Calculer une valeur de dégradé `t` normalisée entre 0 et 1
//     double t = (double)iteration / max_iterations;

//     // Calculer les composantes de couleur en utilisant des sinusoïdes
//     int r = (int)(sin(4 * M_PI * t) * 127 + 128);  // Fréquence double pour le rouge
// 	int g = (int)(cos(2 * M_PI * t + M_PI / 3) * 127 + 128);  // Cosinus pour le vert
// 	int b = (int)(sin(3 * M_PI * t + M_PI / 2) * 127 + 128);  // Fréquence triple pour le bleu
// 	// int r = (int)(sin(2 * M_PI * t + 4 * M_PI / 3) * 127 + 128);  // Rouge devient comme le bleu
// 	// int g = (int)(sin(2 * M_PI * t + 0) * 127 + 128);  // Vert devient comme le rouge
// 	// int b = (int)(sin(2 * M_PI * t + 2 * M_PI / 3) * 127 + 128);  // Bleu devient comme le vert
// 	// int r = (int)(sin(2 * M_PI * t + M_PI / 2) * 127 + 128);  // Rouge décalé d'un demi-cycle
// 	// int g = (int)(sin(2 * M_PI * t + M_PI) * 127 + 128);  // Vert décalé d'un cycle complet
// 	// int b = (int)(sin(2 * M_PI * t + 3 * M_PI / 2) * 127 + 128);  // Bleu décalé d'un cycle et demi

//     return (r << 16) | (g << 8) | b;
// }

// static int get_color(int iteration, int max_iterations)
// {
//     double t = (double)iteration / max_iterations;

//     int r = (int)(127.5 * (1 + sin(3.0 * M_PI * t)));  // Oscille entre 0 et 255
//     int g = (int)(127.5 * (1 + sin(3.0 * M_PI * t + 2.0))); // Décalé pour dégradé fluide
//     int b = (int)(127.5 * (1 + sin(3.0 * M_PI * t + 4.0))); // Autre décalage

//     return (r << 16) | (g << 8) | b;
// }

static int get_color(int iteration, int max_iterations, t_color *rgb)
{
    double t = (double)iteration / max_iterations;

    int r = (int)(127.5 * (rgb->freq_r + cos(3.0 * M_PI * t + rgb->phase_r)));  // Oscille entre 0 et 255
    int g = (int)(127.5 * (rgb->freq_g + cos(3.0 * M_PI * t + rgb->phase_g))); // Décalé pour dégradé fluide
    int b = (int)(127.5 * (rgb->freq_b + cos(3.0 * M_PI * t + rgb->phase_b))); // Autre décalage

    return (r << 16) | (g << 8) | b;
}

// color = get_color(i, param->max_it);
void	mandelbrot(int x, int y, t_mlx *mlx, t_data *param)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0;
	z.i = 0.0;
	c.x = scale(x, -2, 2, WIDTH) * param->zoom + param->shift_x;
	c.i = scale(y, 2, -2, HEIGHT) * param->zoom + param->shift_y;
	i = 0;
	while (i < param->max_it)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.i * z.i) > 4.0)
		{
			color = get_color(i, param->max_it, &param->rgb);
			ft_pixel_put(x, y, &mlx->img, color);
			return ;
		}
		++i;
	}
	ft_pixel_put(x, y, &mlx->img, BLACK);
}


