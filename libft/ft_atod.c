/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:24:52 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/10/28 20:51:57 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fractional_part(char *str, double *flag, double *result, int i)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result = *result * 10 + str[i] - '0';
		*flag *= 10.0;
		i++;
	}
}

double	ft_atod(char *str)
{
	int		i;
	double	flag;
	double	sign;
	double	result;

	i = 0;
	flag = 1.0;
	sign = 1.0;
	result = 0.0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		sign = -1.0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		i++;
	fractional_part(str, &flag, &result, i);
	return (result / flag * sign);
}
