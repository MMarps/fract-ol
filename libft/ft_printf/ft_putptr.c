/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:04:41 by mmarpaul          #+#    #+#             */
/*   Updated: 2024/06/09 19:31:45 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int					count;
	unsigned long long	adrs;

	count = 0;
	if (!ptr)
		return (ft_putstr_ct("(nil)"));
	adrs = (unsigned long long)ptr;
	count = ft_putstr_ct("0x") + ft_hexa_llong((unsigned long long)adrs);
	return (count);
}
