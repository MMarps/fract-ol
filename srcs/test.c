/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:52:58 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/10/29 22:39:20 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// int get_color(int iteration, int max_iterations) {
//     double t = (double)iteration / (double)max_iterations;
//     int r = (int)(9 * (1 - t) * t * t * t * 255);      // Rouge
//     int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255); // Vert
//     int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255); // Bleu
//     return (r << 16) | (g << 8) | b;
// }

// int get_color(int iteration, int max_iterations) {
//     if (iteration == max_iterations) return 0x000000; // Couleur pour l'intérieur (ex: noir)

//     // Appliquer une échelle logarithmique
//     double t = log((double)iteration + 1) / log((double)max_iterations);

//     // Calculer les composantes de couleur en utilisant des dégradés
//     int r = (int)(9 * (1 - t) * t * t * t * 255);
//     int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//     int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    
//     return (r << 16) | (g << 8) | b;
// }

// static int get_color(int iteration, int max_iterations, double zn)
// {
//     if (iteration == max_iterations) return 0x000000; // Couleur pour l'intérieur

//     // Utiliser l'itération fractionnaire pour une transition plus douce
//     double smooth_iter = iteration + 1 - log(log(zn)) / log(2.0);
//     double t = smooth_iter / max_iterations;

//     // Dégradé de couleurs ajusté
//     int r = (int)(30 * (1 - t) * (1 - t) * t * t * t * 255);
//     int g = (int)(30 * (1 - t) * (1 - t) * t * t * 255);
//     int b = (int)(6* (1 - t) * (1 - t) * (1 - t) * t * 255);
    
//     return (r << 16) | (g << 8) | b;
// }

// int get_color(int iteration, int max_iterations) {
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

// int get_psychedelic_color(int iteration) {
//     double r = sin(0.016 * iteration + 4) * 230 + 25;
//     double g = sin(0.013 * iteration + 2) * 230 + 25;
//     double b = sin(0.01 * iteration + 1) * 230 + 25;
//     return ((int)r << 16) | ((int)g << 8) | (int)b;
// }

// , sqrt(z.x * z.x + z.i * z.i)

static int get_color(int iteration, int max_iterations, double zn)
{

    // Utiliser l'itération fractionnaire pour une transition plus douce
    double smooth_iter = iteration + 1 - log(log(zn)) / log(2.0);
    double t = smooth_iter / max_iterations;

    // Dégradé de couleurs ajusté
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    
    return (r << 16) | (g << 8) | b;
}

void	test_pixels(t_mlx *mlx)
{
	int x = 0;
	int y = HEIGHT;
	while (x < WIDTH && y > 0)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, RED);
		x++;
		y--;
	}
	
	x = 0;
	y = 0;
	while (x < WIDTH && y < HEIGHT)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, GREEN);
		x++;
		y++;
	}

	x = WIDTH / 2;
	y = 0;
	while (x < WIDTH && y < HEIGHT)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, BLUE);
		y++;
	}

	x = 0;
	y = HEIGHT / 2;
	while (x < WIDTH && y < HEIGHT)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, MAGENTA);
		x++;
	}
}
