/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:00:37 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/11/13 16:43:25 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	scale(double unscaled_num,
			double new_min,
			double new_max,
			double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max  + new_min);
}

t_complex	abs_complex(t_complex c)
{
	t_complex	result;

	result.x = fabs(c.x);
	result.i = fabs(c.i);
	return (result);
}

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.x = a.x + b.x;
	result.i = a.i + b.i;
	return (result);
}

t_complex	square_complex(t_complex c)
{
	t_complex	result;

	result.x = c.x * c.x - c.i * c.i;
	result.i = 2 * c.x * c.i;
	return (result);
}
