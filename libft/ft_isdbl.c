/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:44:27 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/11/13 17:12:24 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdbl(char *str)
{
	if (!str)
		return (0);
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}
