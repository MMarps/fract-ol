/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:45:12 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/06/09 19:24:57 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_ct(char *str)
{
	int	count;
	int	i;

	if (!str)
		return (ft_putstr_ct("(null)"));
	count = 0;
	i = 0;
	while (str[i])
	{
		count += ft_putchar_ct(str[i]);
		i++;
	}
	return (count);
}
